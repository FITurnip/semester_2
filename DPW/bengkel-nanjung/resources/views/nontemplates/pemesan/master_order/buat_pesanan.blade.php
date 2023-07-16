@extends('templates.layouts.main')
@extends('templates.components.header')
@extends('templates.components.footer')
@extends('templates.components.navigation')

@section('content')
<section class="container">
    <h2>Buat Pesanan</h2>
    <div class="row">
        <div class="col-lg-7 mb-3">
            <form action="/master_order" method="POST">
                <legend class="my-4">Mulai Buat Pesanan!</legend>
                @csrf

                {{-- Nama --}}
                <div class="mb-3 row">
                    <div class="col-2">
                        <label for="name" class="form-label">Nama</label>
                    </div>
                    <div class="col-6">
                        <input type="text" class="form-control @error('name') is-invalid @enderror" id="name" name="name" placeholder="min. 3 karakter" value="{{ old('name') }}" required>
                        @error('name')
                            <div class="form-text text-danger mx-3">Nama tidak valid</div>
                        @enderror
                    </div>
                </div>

                {{-- Telepon --}}
                <div class="mb-3 row">
                    <div class="col-2">
                        <label for="tel" class="form-label">No. Telp</label>
                    </div>
                    <div class="col-6">
                        <input type="tel" class="form-control @error('tel') is-invalid @enderror" id="tel" name="tel" placeholder="Min. 10 & maks. 13 karakter" value="{{ old('tel') }}" required>
                        @error('tel')
                            <div class="form-text text-danger mx-3">No. Telp tidak valid</div>
                        @enderror
                    </div>
                </div>

                {{-- Nopol --}}
                <div class="mb-3 row">
                    <div class="col-2">
                        <label for="nopol" class="form-label">No. Polisi</label>
                    </div>
                    <div class="col-6">
                        <input type="text" class="form-control @error('nopol') is-invalid @enderror" id="nopol" name="nopol" placeholder="D 1234 XYZ" value="{{ old('nopol') }}" required>
                        @error('nopol')
                            <div class="form-text text-danger mx-3">No. Polisi tidak valid</div>
                        @enderror
                    </div>
                </div>

                {{-- Message --}}
                <div class="mb-3 row">
                    <div class="col-2">
                        <label for="pesan_tambahan" class="form-label">Keluhan</label>
                    </div>
                    <div class="col-8">
                        <textarea name="message" id="" cols="10" rows="3" class="form-control" placeholder="Kosongkan jika tidak ada">{{ old('message') }}</textarea>
                    </div>
                </div>
                <button type="submit" class="btn btn-primary">Mulai Pemesanan!</button>
            </form>
        </div>
    </div>
</section>
@endsection