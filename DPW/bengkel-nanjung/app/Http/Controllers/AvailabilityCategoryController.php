<?php

namespace App\Http\Controllers;

use App\Models\Availability;
use App\Models\AvailabilityCategory;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Storage;

class AvailabilityCategoryController extends Controller
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
            'name' => 'required|min:3|max:255',
            'desc' => 'required|max:255',
            'photo' => 'image|file',
            'state' => 'required'
        ]);

        if($request->photo) {
            $temp['photo'] = $request->file('photo')->store('availability-thumbnail');
        }

        AvailabilityCategory::create($temp);

        return back()->with('success', 'Data berhasil ditambahkan.');
    }

    /**
     * Display the specified resource.
     */
    public function show(AvailabilityCategory $availabilityCategory)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(AvailabilityCategory $availabilityCategory)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(Request $request, AvailabilityCategory $availabilityCategory)
    {
        $temp = $request->except(['_token', '_method']);

        if($request->photo) {
            if($availabilityCategory->photo) Storage::delete($availabilityCategory->photo);
            $temp['photo'] = $request->file('photo')->store('availability-thumbnail');
        }

        AvailabilityCategory::where('id', $availabilityCategory->id)->update($temp);
        return back()->with('update', $availabilityCategory->id);
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(AvailabilityCategory $availabilityCategory)
    {
        // Availability::where('availabilityCategory', $availabilityCategory)->delete();
        // AvailabilityCategory::destroy($availabilityCategory->id);
        // return back()->with('danger', 'Data berhasil dihapus');
    }
}
