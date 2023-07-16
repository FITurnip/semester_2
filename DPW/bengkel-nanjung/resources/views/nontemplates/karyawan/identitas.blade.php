@extends('templates.layouts.dashboard')
@extends('templates.components.sidebar_dashboard.karyawan')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Identitas</h2>

@if(session()->has('success'))
<div class="alert alert-success fade show" role="alert">
    {{ session()->get('success') }}
</div>
@endif

<div class="row">
    <div class="col-7">
        <form action="/karyawan/identity" method="POST" enctype="multipart/form-data">
            @csrf
            <input type="hidden" name="id" value="{{ $employee[0]->id }}">

            {{-- Nama --}}
            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="name">Nama</label>
                </div>
                <div class="col-9">
                    <input class="form-control @error('name') {{ 'is-invalid' }} @enderror" type="text" name="name" id="name" value="{{ $employee[0]->name }}" onchange="$.fn.enableButton('#btn');" required>
                    @error('name')
                    <div class="form-text text-danger mx-3">Nama tidak valid</div>
                    @else
                        <div class="form-text mx-3">Min. 3 karakter</div>
                    @enderror
                </div>
            </div>

            {{-- Telepon --}}
            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="tel">Tel</label>
                </div>
                <div class="col-9">
                    <input class="form-control @error('tel') {{ 'is-invalid' }} @enderror" type="tel" name="tel" id="tel" value="{{ $employee[0]->tel }}" onchange="$.fn.enableButton('#btn');" required>
                    @error('tel')
                    <div class="form-text text-danger mx-3">Tel tidak valid</div>
                    @else
                        <div class="form-text mx-3">Min. 10 & maks. 13 karakter</div>
                    @enderror
                </div>
            </div>

            {{-- Jenis Kelamin --}}
            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="gender">Jenis Kelamin</label>
                </div>
                <div class="col-9">
                    <select name="gender" id="gender" class="form-select @error('gender') {{ 'is-invalid' }} @enderror" onchange="$.fn.enableButton('#btn');">
                        <option value="1" {{ ($employee[0]->gender == 1) ? 'selected' : '' }}>Laki-laki</option>
                        <option value="2" {{ ($employee[0]->gender == 2) ? 'selected' : '' }}>Perempuan</option>
                    </select>
                </div>
            </div>

            {{-- Foto Profil --}}
            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="photo">Foto Profil</label>
                </div>
                <div class="col-9">
                    <input class="form-control @error('photo') {{ 'is-invalid' }} @enderror" type="file" name="photo" id="photo" onchange="$.fn.enableButton('#btn');">

                    @php
                        if($employee[0]->photo) $photo = asset('storage/' . $employee[0]->photo);
                        else $photo = asset('img/auto-repair-g2eb98b15d_640.jpg');
                    @endphp

                    <img src="{{ $photo }}" alt="" style="height: 150px" class="my-2"><br>
                    <caption>Foto Profil Sebelumnya</caption>
                </div>
            </div>
            <button type="submit" class="btn btn-warning dynamic-disable px-2" id="btn">Perbarui</button>
        </form>
    </div>
</div>
@endsection