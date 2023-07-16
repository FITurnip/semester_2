<?php

namespace App\Http\Controllers;

use App\Models\MasterOrder;
use App\Models\Order;
use App\Models\Receipt;
use Illuminate\Http\Request;

class ReceiptController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        //
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     */
    public function show(Receipt $receipt)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Receipt $receipt)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Receipt $receipt)
    {
        $receiptUpdate['state'] = $request->state;
        Receipt::where('id', $request->id)->update($receiptUpdate);

        $masterOrder['state'] = 2;
        MasterOrder::where('id', $request->master_order)->update($masterOrder);

        return back()->with('success', $receipt->masterOrder->noreg);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Receipt $receipt)
    {
        $oldReg = $receipt->masterOrder->reg;

        Order::where('master_order', $receipt->master_order)->delete();
        MasterOrder::where('id', $receipt->master_order)->delete();
        Receipt::where('id', $receipt->id)->delete();

        return back()->with('danger', $oldReg );
    }
}
