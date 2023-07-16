<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use App\Models\Employee;
use App\Models\MasterOrder;
use App\Models\Order;
use App\Models\Receipt;
use Carbon\Carbon;
use Illuminate\Http\Request;

class MasterOrderController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        return view('nontemplates.pemesan.master_order.buat_pesanan');
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
       return static::index();
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        // validasi
        $masterOrder = $request->validate([
            'name' => 'required|min:3|max:255',
            'tel' => 'required|regex:/^\d{10,13}$/|min:10|max:13',
            'nopol' => 'required|regex:/^[A-Z]{1,2}+\s{1}+\d{1,4}+\s{1}+[A-Z]{1,3}$/|min:5|max:11',
        ]);
        
        // membuat nomor registrasi berdasarkan timestamp saat ini(bukan dari database) & banyaknya data masterorder saat ini
        $masterOrderCount = MasterOrder::all()->count();

        $masterOrder['reg'] = date("Y" . "m" . "d" . "h" . "i");
        for($digit = strlen((string) $masterOrderCount); $digit < 4; $digit++) $masterOrder['reg'] = $masterOrder['reg'] . '0'; // panjang digit adalah bagian count adalah 4
        $masterOrder['reg'] = $masterOrder['reg'] . $masterOrderCount;

        $masterOrder['message'] = $request->message;
        if($masterOrder['message'] == NULL) $masterOrder['message'] = '-';

        // data default
        $masterOrder['state'] = -1; // belum dilakukan apa-apa
        $masterOrder['created_at'] = Carbon::now();
        $masterOrder['updated_at'] = Carbon::now();
        $masterOrder['total_price'] = 0; // belum ada yang dibeli

        MasterOrder::create($masterOrder);

        return redirect()->route('master_order.order.create', encrypt(MasterOrder::all()->last()->id));
    }

    /**
     * Display the specified resource.
     */
    public function show(MasterOrder $masterOrder)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(MasterOrder $masterOrder)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, MasterOrder $masterOrder)
    {
        if($request->state == NULL) return back();

        $masterOrderUpdated['state'] = $request->state;
        MasterOrder::where('id', $masterOrder->id)->update($masterOrderUpdated);

        if($request->state < 1 && $masterOrder->state == 1) {
            $receipt = Receipt::select('id')->where('master_order', $masterOrder->id)->get()->first();
            Receipt::destroy('id', $receipt['id']);
        }

        if($request->state == 1) {
            $sumOfReceipt = Receipt::where('master_order', $masterOrder->id)->count();
            if($sumOfReceipt == 0) {
                $employee = Employee::where('user', auth()->user()->id)->get();
                $receiptCreated['master_order'] = $masterOrder->id;
                $receiptCreated['employee'] = $employee[0]->id;
                $receiptCreated['state'] = 0;
                $receiptCreated['created_at'] = now();
                $receiptCreated['updated_at'] = now();

                Receipt::create($receiptCreated, ['master_order' => $receiptCreated['master_order']]);
            }
        } else if($request->state == 2) {
            $receiptUpdated['state'] = 1;
            $receiptUpdated['updated_at'] = now();

            Receipt::where('master_order', $masterOrder->id)->update($receiptUpdated);
        }

        return back()->with('success', $masterOrder->reg);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(MasterOrder $masterOrder)
    {
        $oldReg = $masterOrder->reg;

        Order::where('master_order', $masterOrder->id)->delete();
        MasterOrder::where($masterOrder->id)->delete();
        Receipt::where('master_order', $masterOrder->id)->delete();

        return back()->with('danger', $oldReg );
    }
}
