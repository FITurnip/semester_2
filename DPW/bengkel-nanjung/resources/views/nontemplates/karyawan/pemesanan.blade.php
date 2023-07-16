@extends('templates.layouts.dashboard')
@extends('templates.components.sidebar_dashboard.karyawan')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Daftar Pemesanan</h2>

<a href="{{ URL::previous() }}"><button class="btn btn-primary my-2"><i class="bi bi-arrow-left-circle me-2"></i>Kembali</button></a>

<div class="table-responsive">
  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">No</th>
        <th scope="col">Jenis</th>
        <th scope="col">Deskripsi</th>
        <th scope="col">Jumlah</th>
      </tr>
    </thead>
    <tbody>
        @foreach ($orders as $order)    
        <tr>
            <td>{{ $loop->index + 1 }}</td>
            <td>{{ $order->availabilities->availability_category }}</td>
            <td>{{ $order->availabilities->name }}</td>
            <td>{{ $order->qty }}</td>
        </tr>
        @endforeach
    </tbody>
  </table>
</div>
@endsection