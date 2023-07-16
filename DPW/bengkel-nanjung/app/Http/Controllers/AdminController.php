<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use App\Models\Employee;
use App\Models\MasterOrder;
use App\Models\Order;
use App\Models\Receipt;
use Illuminate\Http\Request;

class AdminController extends Controller
{
    // MENAMPILKAN HALAMAN
    public function index() {
        return redirect('/admin/employee');
    }

    public function employee() {
        $employees = Employee::all();
        return view('nontemplates.admin.daftar_karyawan', compact('employees'));
    }
    
    public function show_receipt() {
        $receipts = Receipt::all();
        return view('nontemplates.admin.cek_struk', compact('receipts'));
    }

    public function show_the_receipt($reg) {
        $master_order = MasterOrder::where('reg', $reg)->get()->first();
        $orders = Order::where('master_order', $master_order->id)->get();
        $availability_categories = AvailabilityCategory::all();
        return view('nontemplates.admin.tampilkan_struk', compact('orders', 'availability_categories', 'master_order'));
    }

    public function edit_account() {
        $user['id'] = auth()->user()->id;
        $user['username'] = auth()->user()->username;
        return view('nontemplates.admin.akun', $user);
    }

    public function show_availability() {
        $availabilities = Availability::orderBy('state', 'desc')->orderBy('id', 'asc')->get();
        return view('nontemplates.admin.daftar_layanan', compact('availabilities'));
    }

    public function show_the_availability($availability_id) {
        $availability = Availability::where('id', $availability_id)->get();
        return view('nontemplates.admin.tampilkan_ketersediaan', compact('availability'));
    }

    public function show_create_availability() {
        $availabilityCategories = AvailabilityCategory::all();
        return view('nontemplates.admin.buat_edit_layanan', compact('availabilityCategories'));
    }

    public function show_update_availability($availability_id) {
        $availabilityCategories = AvailabilityCategory::all();
        $availability = Availability::where('id', $availability_id)->get();
        return view('nontemplates.admin.buat_edit_layanan', compact('availabilityCategories', 'availability'));
    }

    public function show_availability_category() {
        $availabilityCategories = AvailabilityCategory::orderBy('state', 'desc')->orderBy('id', 'asc')->get();
        return view('nontemplates.admin.daftar_kategori_ketersediaan', compact('availabilityCategories'));
    }
}
