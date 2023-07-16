<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Storage;

class AvailabilityController extends Controller
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
        $temp = $request->validate([
            'availability_category' => 'required',
            'name' => 'required|min:3|max:255',
            'desc' => 'required|min:1|max:255',
            'qty' => 'required|min:0',
            'price' => 'required|min:0',
            'photo' => 'image|file'
        ]);

        if($request->photo) {
            $temp['photo'] = $request->file('photo')->store('availability-thumbnail');
        }

        $temp['state'] = 1;
        Availability::create($temp);

        return back()->with('success', 'Data berhasil ditambahkan.');
    }

    /**
     * Display the specified resource.
     */
    public function show(Availability $availability)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Availability $availability)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, Availability $availability)
    {
        $temp = $request->except(['_token', '_method', 'oldQty']);

        if($request->oldQty) {
            $temp['qty'] = $request->qty + $request->oldQty;
            if($temp['qty'] >= 1000 or $temp['qty'] <= 0) {
                return back()->with('limit', $availability->id);
            }
        }

        if($request->name) {
            $temp = $request->validate([
                'availability_category' => 'required',
                'name' => 'required|min:3|max:255',
                'desc' => 'required|min:1|max:255',
                'qty' => 'required|min:0|max:1000',
                'price' => 'required|min:0',
                'photo' => 'image|file'
            ]);
        }

        if($request->photo) {
            if($availability->photo) Storage::delete($availability->photo);
            $temp['photo'] = $request->file('photo')->store('availability-thumbnail');
        }

        Availability::where('id', $availability->id)->update($temp);
        return back()->with('success', $availability->id);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Availability $availability)
    {
        // Availability::destroy($availability->id);
        // return back()->with('danger', 'Data berhasil dihapus');
    }
}
