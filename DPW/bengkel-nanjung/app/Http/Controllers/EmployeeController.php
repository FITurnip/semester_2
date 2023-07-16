<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use App\Models\Availibility;
use App\Models\Employee;
use App\Models\MasterOrder;
use App\Models\Order;
use App\Models\Receipt;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Storage;

class EmployeeController extends Controller
{
    /* MENAMPILKAN HALAMAN */
    public function index() {
        return redirect('/karyawan/master_order');
    }

    public function master_order() {
        $masterOrders = MasterOrder::orderBy('state', 'asc')->get();
        return view('nontemplates.karyawan.daftar_pemesanan', compact('masterOrders'));
    }

    public function show_order($master_order_id) {
        $masterOrders = MasterOrder::where('id', $master_order_id)->get();
        $orders = Order::where('master_order', $master_order_id)->get();
        $availabilityCategories = AvailabilityCategory::all();
        return view('nontemplates.karyawan.pemesanan', compact('masterOrders', 'orders', 'availabilityCategories'));
    }

    public function show_receipt() {
        $employees = Employee::where('user', auth()->user()->id)->get();
        $receipts = Receipt::where('employee', $employees[0]->id)->orderBy('state')->get();
        return view('nontemplates.karyawan.cek_struk', compact('receipts', 'employees'));
    }

    public function show_the_receipt($reg) {
        $masterOrder = MasterOrder::where('reg', $reg)->get()->first();
        $orders = Order::where('master_order', $masterOrder->id)->get();
        $availability_categories = AvailabilityCategory::all();
        $master_order = MasterOrder::where('id', $masterOrder->id)->get()->first();
        return view('nontemplates.admin.tampilkan_struk', compact('orders', 'availability_categories', 'master_order'));
    }

    public function show_availability() {
        $availabilities = Availability::orderBy('state', 'desc')->orderBy('id', 'asc')->get();
        return view('nontemplates.karyawan.daftar_layanan', compact('availabilities'));
    }

    public function show_the_availability($availability_id) {
        $availability = Availability::where('id', $availability_id)->get()->first();
        return view('nontemplates.karyawan.tampilkan_ketersediaan', compact('availability'));
    }

    public function show_create_availability() {
        $availabilityCategories = AvailabilityCategory::all();
        return view('nontemplates.karyawan.buat_edit_layanan', compact('availabilityCategories'));
    }

    public function show_update_availability($availability_id) {
        $availabilityCategories = AvailabilityCategory::all();
        $availability = Availability::where('id', $availability_id)->get();
        return view('nontemplates.karyawan.buat_edit_layanan', compact('availabilityCategories', 'availability'));
    }

    public function show_availability_category() {
        $availabilityCategories = AvailabilityCategory::orderBy('state', 'desc')->orderBy('id', 'asc')->get();
        return view('nontemplates.karyawan.daftar_kategori_ketersediaan', compact('availabilityCategories'));
    }

    public function edit_account() {
        $user['id'] = auth()->user()->id;
        $user['username'] = auth()->user()->username;
        return view('nontemplates.karyawan.akun', $user);
    }

    public function edit_identity() {
        $employee = Employee::where('user', auth()->user()->id)->get();
        return view('nontemplates.karyawan.identitas', compact('employee'));
    }

    /* UPDATE IDENTITAS */
    public function update_identity(Request $request) {
        $temp = $request->validate([
            'name' => 'required|min:3|max:255',
            'tel' => 'required|regex:/^([0-9\s\-\+\(\)]*)$/|min:10|max:13',
            'gender' => 'required',
            'photo' => 'image|file'
        ]);

        if($request->photo) {
            $filename = Employee::where('id', $request->id)->first()->photo;
            if($filename) Storage::delete($filename);
            $temp['photo'] = $request->file('photo')->store('employee-photo');
        }

        Employee::where('id', $request->id)->update($temp);
        return back()->with('success', 'Data berhasil diperbaharui.');
    }
}
