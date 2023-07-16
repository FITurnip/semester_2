@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Ketersediaan</h2>
<div class="row">

    @if(session()->has('success'))
    <div class="alert alert-success fade show" role="alert">
        {{ session()->get('success') }}
    </div>
    @endif

    <div class="col-xl-7">
        <form action="{{ '/availability' }}@isset($availability[0]->id){{ '/' . $availability[0]->id }}@endisset" method="POST" enctype="multipart/form-data">
            @csrf

            @isset($availability[0]->id)
                @method('put')
                <input type="hidden" name="id" value="{{ $availability[0]->id }}">
            @endisset

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label" for="availability_category">Kategori</label>
                </div>
                <div class="col-10">
                   <select class="form-select @error('availability_category') {{ 'is-invalid' }} @enderror" name="availability_category" id="availability_category" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset required>
                    @foreach ($availabilityCategories as $availability_category)
                        <option value="{{ $availability_category->id }}">{{ $availability_category->name }}</option>
                    @endforeach
                    @isset($availability[0]->id)
                        @foreach ($availabilityCategories as $availability_category)
                            <option value="{{ $availability_category->id }}" {{ ($availability[0]->$availability_category == $availability_category->id) ? 'selected' : '' }}>{{ $availability_category->name }}</option>
                        @endforeach                  
                    @endisset
                   </select>
                </div>
            </div>

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label" for="photo">Thumbnail</label>
                </div>
                <div class="col-10">
                    <input class="form-control @error('photo') {{ 'is-invalid' }} @enderror" type="file" name="photo" id="photo" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset>
                </div>
            </div>

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label" for="name">Nama</label>
                </div>
                <div class="col-10">
                    <input class="form-control @error('name') {{ 'is-invalid' }} @enderror" type="text" name="name" id="name" placeholder="min. 3 karakter" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset value="@isset($availability[0]->id){{ $availability[0]->name }}@endisset" required>
                </div>
            </div>

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label @error('desc') {{ 'is-invalid' }} @enderror" for="desc">Deskripsi</label>
                </div>
                <div class="col-10">
                    <input class="form-control" type="text" name="desc" id="desc" placeholder="maks. 225 karakter" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset value="@isset($availability[0]->id){{ $availability[0]->desc }}@endisset" required>
                </div>
            </div>

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label" for="qty">Jumlah barang</label>
                </div>
                <div class="col-10">
                    <input class="form-control @error('qty') {{ 'is-invalid' }} @enderror" type="number" name="qty" id="qty" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset value="@isset($availability[0]->id){{ $availability[0]->qty }}@else{{ '99' }}@endisset" min="0" max="1000" required>
                </div>
            </div>

            <div class="row my-3">
                <div class="col-2">
                    <label class="form-label" for="price">Harga Satuan</label>
                </div>
                <div class="col-10">
                    <input class="form-control @error('price') {{ 'is-invalid' }} @enderror" type="number" name="price" id="price" @isset($availability[0]->id) onchange="$.fn.enableButton ('#btn');" @endisset value="@isset($availability[0]->id){{ $availability[0]->price }}@else{{ '50000' }}@endisset" min="0" max="1000000" required>
                </div>
            </div>
            
            <button type="submit" class="btn btn-primary @isset($availability[0]->id) dynamic-disable @endisset px-2" id="btn">@isset($availability[0]->id) Perbarui @else Tambahkan @endisset</button>
        </form>
    </div>
</div>
@endsection