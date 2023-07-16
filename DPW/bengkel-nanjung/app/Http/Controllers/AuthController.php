<?php

namespace App\Http\Controllers;

use App\Models\Employee;
use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Hash;
use Illuminate\Support\Facades\Storage;

class AuthController extends Controller
{
    /* LOGIN */
    // Menampilkan halaman login
    public function index() {
        return view('nontemplates.autentikasi.login');
    }

    // autentikasi data login
    public function authenticate(Request $request) {

        $credentials = $request->validate([
            'username' => 'required|lowercase|min:3|max:255',
            'password' => 'required|min:8|max:255',
        ]);
        
        if (Auth::attempt($credentials)) {
            $request->session()->regenerate();

            if(auth()->user()->state == 1) {

                return redirect()->intended('/dashboard');

            } else {
                $request->session()->invalidate();
     
                $request->session()->regenerateToken();

                return back()->with('danger', 'Username/password salah!');
            }
        }
        
        return back()->with('danger', 'Username/password salah!');
    }

    /* SING UP */
    // Menampilkan halaman sign up
    public function show_signup() {
        return view('nontemplates.autentikasi.signup');
    }

    // Menyimpan akun karyawan baru
    public function create_account(Request $request) {
        // validasi data user dan employee
        $newUser = $request->validate([
            'username' => 'required|lowercase|regex:/^[0-9a-z(_)]*$/|min:3|max:255|unique:users,username',
            'password' => 'required|min:8|max:255'
        ]);

        $newEmployee = $request->validate([
            'name' => 'required|min:3|max:255',
            'tel' => 'required|regex:/^([0-9\s\-\+\(\)]*)$/|min:10|max:13',
            'gender' => 'required',
            'photo' => 'image|file'
        ]);

        // gunakan standar penyimpanan data awal
        $newUser['password'] = Hash::make($request->password); // gunakan hashing
        $newUser['user_type'] = 2; // jadikan karyawan
        $newUser['state'] = 0; //akun dalam keadaan nonaktif

        // simpan data user terlebih dahulu agar didapatkan user id
        User::create($newUser);

        //dapatkan user id
        $temp = User::where('username', $newUser['username'])->get();
        $newEmployee['user'] = $temp->first()->id;

        // simpan data employee
        if($request->photo) {
            $newEmployee['photo'] = $request->file('photo')->store('employee-photo');
        }
        
        Employee::create($newEmployee);

        return back()->with('success', 'Akun berhasil dibuat! Agar dapat login, tunggu aktivasi akun dari admin');
    }

    /* LOG OUT */
    public function logout(Request $request) {
        Auth::logout();

        // persiapan untuk data login terbaru
        $request->session()->invalidate();
        $request->session()->regenerateToken();
     
        return redirect('/');
    }

    /* DASHBOARD */
    // menampilkan halaman dashboard
    public function dashboard(Request $request) {
        $user_type = auth()->user()->user_type;
        if($user_type == 1) { // jika rolenya admin

            return redirect()->intended('/admin');

        } else { // jika rolenya karyawan

            return redirect()->intended('/karyawan');

        }
    }

    // update status akun
    public function accountActivation(Request $request) {
        $temp['state'] = $request->state;
        User::where('id', $request->id)->update($temp);

        return back()->with('success', $request->id);
    }

    // update data user
    public function update(Request $request) {
        // validasi data 
        $temp = $request->validate([
            'username' => 'required|lowercase|regex:/^[0-9a-z(_)]*$/|min:3|max:255',
            'password' => 'required|min:8|max:255'
        ]);

        // jika ada perubahan username, pastikan username unik
        $user = User::where('id', $request->id)->get()->first();
        if($request->username != $user->username) {
            $request->validate([
                'username' => 'unique:users,username'
            ]);
        }

        // hashing password
        $temp['password'] = Hash::make($request->password);
        // if($request->password != NULL) {
        // }

        User::where('id', $request->id)->update($temp);
        return back()->with('success', 'Data berhasil diperbaharui.');
    }

}
