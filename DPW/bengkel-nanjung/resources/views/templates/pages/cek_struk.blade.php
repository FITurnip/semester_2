@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Daftar Struk</h2>
<div class="table-responsive">
  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">No. Reg</th>
        <th scope="col">Nama</th>
        <th scope="col">Harga</th>
        <th scope="col">Kondisi</th>
        <th scope="col">Aksi</th>
      </tr>
    </thead>
    <tbody>
      @yield('recorded_data')
    </tbody>
  </table>
</div>
@endsection