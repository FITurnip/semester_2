@extends('templates.layouts.dashboard')
@extends('templates.components.sidebar_dashboard.karyawan')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Akun</h2>

@if(session()->has('success'))
<div class="alert alert-success fade show" role="alert">
    {{ session()->get('success') }}
</div>
@endif

<div class="row">
    <div class="col-7">
        <form action="/auth/edit_account" method="POST">
            @csrf
            <input type="hidden" name="id" value="{{ $id }}">

            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="username">username</label>
                </div>
                <div class="col-9">
                    <input class="form-control @error('username') is-invalid @enderror" type="text" name="username" id="username" value="{{ $username }}" onchange="$.fn.enableButton('{{ '#btn-'.$id }}');" required>
                    @error('username')
                        <div class="form-text text-danger mx-3">Username pernah dipakai/tidak valid</div>
                    @else
                        <div class="form-text mx-3">Min. 3 karakter</div>
                    @enderror
                </div>
            </div>

            <div class="row my-3">
                <div class="col-md-3">
                    <label class="form-label" for="username">password</label>
                </div>
                <div class="col-9">
                    <input class="form-control @error('password') is-invalid @enderror" type="password" name="password" id="password" onchange="$.fn.enableButton('{{ '#btn-'.$id }}');" required>
                    @error('password')
                        <div class="form-text text-danger mx-3">Password tidak valid</div>
                    @else
                        <div class="form-text mx-3">Min. 8 karakter</div>
                    @enderror
                </div>
            </div>
            
            <button type="submit" class="btn btn-warning dynamic-disable px-2" id="btn-{{ $id }}">Perbarui</button>
        </form>
    </div>
</div>
@endsection