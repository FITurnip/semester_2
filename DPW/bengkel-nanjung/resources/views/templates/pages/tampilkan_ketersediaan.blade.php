@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Ketersediaan</h2>
<div class="table-responsive">
  <a href="{{ URL::previous() }}"><button class="btn btn-primary my-2"><i class="bi bi-arrow-left-circle me-2"></i>Kembali</button></a>

  <table class="table table-striped table-sm table-striped-columns table-dark">
    <tr>
      <th>Photo</th>
      <td>:</td>
      
      @php
      if($availability->photo) $photo = asset('storage/' . $availability->photo);
      else $photo = asset('img/winter-tires-g20c2dbe32_1920.jpg');
      @endphp

      <td><img src="{{ $photo }}" alt="" style="height: 500px;"></td>
    </tr>
    <tr>
      <th>Kategori</th>
      <td>:</td>
      <td>{{ $availability->availabilityCategory->name }}</td>
    </tr>
    <tr>
      <th>Nama</th>
      <td>:</td>
      <td>{{ $availability->name }}</td>
    </tr>
    <tr>
      <th>Jumlah Ketersediaan</th>
      <td>:</td>
      <td>{{ $availability->qty }}</td>
    </tr>
    <tr>
      <th>Harga Satuan</th>
      <td>:</td>
      <td>Rp {{ $availability->price }}</td>
    </tr>
    <tr>
      <th>Status</th>
      <td>:</td>
      <td>{{ ($availability->state == 1) ? 'Dapat dijual' : 'Diblokir untuk djiual' }}</td>
    </tr>
  </table>
</div>
@endsection