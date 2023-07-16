@extends('templates.layouts.dashboard')
@extends('templates.components.sidebar_dashboard.admin')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

{{-- List Karyawan --}}
<h2 class="h3">Akun Karyawan</h2>

{{-- Alert untuk keadaan success --}}
@if(session()->has('success'))
<div class="alert alert-success fade show" role="alert">
    Data berhasil diperbaharui
</div>
@endif

<div class="table-responsive">
  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">No.</th>
        <th scope="col">Nama</th>
        <th scope="col">Username</th>
        <th scope="col">Tel</th>
        <th scope="col">Jenis Kelamin</th>
        <th scope="col">Kondisi</th>
      </tr>
    </thead>
    <tbody>
      @foreach ($employees as $employee)
      <tr class="@if(session()->get('success') == $employee->users->id ) {{ 'table-success' }} @endif">
        <td>{{ $loop->index + 1 }}</td> {{-- Nomor --}}
        <td>{{ $employee->name }}</td> {{-- Nama Karyawan --}}
        <td>{{ $employee->users->username }}</td> {{-- Username Karyawan --}}
        <td>{{ $employee->tel }}</td> {{-- Nomor telepon/notel --}}
        <td>{{ ($employee->gender == 1) ? 'L' : 'P'}} </td> {{-- Gender --}}
        <td>
          {{-- Pengubahan kondisi keaktifan akun --}}
          <form action="/auth/accountActivation" method="POST">
            @csrf
            <input type="hidden" name="id" value="{{ $employee->users->id }}">
            <div class="row">
                <div class="col-5">
                    <select name="state" id="state" class="form-select" onchange="$.fn.enableButton('{{ '#btn-' . $employee->id }}');">
                        <option value="0" {{ ($employee->users->state == 0 ? 'selected' : '') }}>Nonaktif</option>
                        <option value="1" {{ ($employee->users->state == 1 ? 'selected' : '') }}>Aktif</option>
                    </select>
                </div>
                <div class="col-5">
                    <button type="submit" class="btn btn-success dynamic-disable px-2" id="btn-{{ $employee->id }}"><i class="bi bi-arrow-repeat"></i> <span>Perbarui</span></button>
                </div>
            </div>
          </form>
        </td>
      </tr>
          
      @endforeach
    </tbody>
  </table>
</div>
@endsection