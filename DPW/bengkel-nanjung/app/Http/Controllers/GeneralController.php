<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use App\Models\Employee;
use App\Models\MasterOrder;
use App\Models\Order;
use App\Models\Receipt;
use App\Models\User;
use Illuminate\Http\Request;

class GeneralController extends Controller
{
    /* INDEX */
    public function index() {
        $availabilities = Availability::where('state', 1)->get();
        $categories = AvailabilityCategory::where('state', 1)->get();
        return view('nontemplates.umum.index', compact('availabilities', 'categories'));
    }

    /* KETERSEDIAAN */
    // menampilkan halaman
    public function ketersediaan() {
        $availabilities = Availability::where('state', 1)->get();
        $categories = AvailabilityCategory::where('state', 1)->get();
        return view('nontemplates.umum.ketersediaan', compact('availabilities', 'categories'));
    }

    // mendapatkan data category dan availability category
    public function getCategory($id_category) {
        $categories = AvailabilityCategory::all();
        return $categories->firstWhere('id', $id_category);
    }

    // mengembalikan html yang menampilkan data availablity berdasarkan kategori yang dipilih
    public function getAvailabilityByCategory($id_category) {
        $availabilities = Availability::where('availability_category', '=', $id_category)->where('state', 1)->get();
        $results = [];
        $i = 0;
        foreach($availabilities as $availability) {
            if($availability['photo'] != NULL) $photo = asset('storage/' . $availability['photo']);
            else $photo = asset('img/winter-tires-g20c2dbe32_1920.jpg');

            $results[$i] = '<div class="card col-md-4 p-3" id="item-card">'
                            . '<img src="' . $photo . '" class="card-img-top" alt="...">'
                            . '<div class="card-body">'
                            . '<h5 class="card-title">' . $availability['name'] . '</h5>'
                            . '</div>'
                            . '<ul class="list-group list-group-flush">'
                            . '<li class="list-group-item">Deskripsi : ' . $availability['desc'] . '</li>'
                            . '<li class="list-group-item">Ketersedian : ' . $availability['qty'] . '</li>'
                            . '<li class="list-group-item">Harga : ' . $availability['price'] . '</li>'
                            . '</ul>'
                            . '</div>';
            // echo($results[$i]);
            $i++;
        }

        return $results;
        // return Availability::where('availability_category', '=', $id_category)->where('state', 1)->get();
    }

    /* TENTANG KAMI */
    public function tentang_kami() {
        $user_active = User::select('id')->where('state', 1)->get();
        $employees = Employee::whereIn('user', $user_active)->get();
        return view('nontemplates.umum.tentang_kami', compact('employees'));
    }
    
    /* PEMESANAN */
    // menampilkan formulir membuat master order
    public function pemesan() {
        return redirect()->route('master_order.create');
    }

    // menampilkan detail order
    public function show_detail_order() {
        return view('nontemplates.pemesan.receipt.cek_pemesanan');
    }

    // menampilkan struk
    public function show_receipt(Request $request) {
        $masterOrder_id = MasterOrder::select('id')->where('reg', $request->reg)->get()->first();
        if($masterOrder_id == NULL) { // jika data tidak ada, maka no reg salah
            return back()->with('warning', 'No. Reg yang dimasukkan salah!');
        }

        // dapatkan data-data terkait struk
        $master_order = MasterOrder::where('id', $masterOrder_id->id)->get()->first();
        $receipt = Receipt::where('master_order', $masterOrder_id->id)->get()->first();
        $orders = Order::where('master_order', $masterOrder_id->id)->get();
        $availability_categories = AvailabilityCategory::all();

        return view('nontemplates.pemesan.receipt.cek_pemesanan', compact('master_order', 'receipt', 'orders', 'availability_categories'));
    }
}
