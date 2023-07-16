<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use App\Models\MasterOrder;
use App\Models\Order;
use Illuminate\Http\Request;

class OrderController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        return view('nontemplates.pemesan.order.index');
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create($masterOrder)
    {
        // mengecek keadaan apakah master order sudah berisi order atau belum
        // jika belum data tidak akan bisa masuk
        $masterOrderId = MasterOrder::select('id')->where('id', decrypt($masterOrder))->get();
        $state = Order::whereIn('master_order', $masterOrderId)->limit(1)->count();

        // dapatkan data master order yang dipilih, 
        $master_order = MasterOrder::where('id', decrypt($masterOrder))->get();

        // dapatkan data ketersediaan bersama kategorinya (hanya yang eksis)
        $exist = Availability::select('availability_category')->where('state', 1)->get();
        $availability_categories = AvailabilityCategory::whereIn('id', $exist)->where('state', 1)->get();
        $availabilities = Availability::where('state', 1)->get();

        return view('nontemplates.pemesan.order.mulai_pemesanan', compact('master_order', 'availability_categories', 'availabilities', 'state'));
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        /* Simpan data */
        $order['master_order'] = decrypt($request->master_order);
        
        $valid = Order::where('master_order', $order['master_order'])->count();

        if($valid > 0) {
            $valid = 0;
        } else {
            $valid = 0;
            $price['total_price'] = 0;
    
            for($itr = 0; $itr < count($request->qty); $itr++) {
                if($request->qty[$itr] > 0) {
                    $order['availability'] = $request->availability[$itr];
                    $order['price'] = $request->price[$itr];
                    $order['qty'] = $request->qty[$itr];
                    $order['total_price'] =  $order['price'] * $order['qty'];

                    $price['total_price'] = $price['total_price'] + $order['total_price'];

                    // simpan data order
                    Order::create($order);

                    // update qty pada availability
                    $availability['qty'] = $request->oldQty[$itr] - $order['qty'];
                    Availability::where('id', $order['availability'])->update($availability);
                    $valid = 1;
                }
            }
        }

        // pindah halaman
        if($valid == 1) {
            MasterOrder::where('id', $order['master_order'])->update($price); // update total biaya apda master order

            return redirect('/pemesan/detail_order');
        } else {
            return back()->with('danger', 'pesanan salah');
        }
    }

    /**
     * Display the specified resource.
     */
    public function show(Order $order)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Order $order)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Order $order)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Order $order)
    {
        Order::where('master_order', $order->master_order)->delete();
    }
}
