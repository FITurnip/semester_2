@extends('templates.layouts.dashboard')
@extends('templates.components.sidebar_dashboard.karyawan')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Daftar Pemesanan</h2>
<div class="table-responsive">

  @if(session()->has('success'))
  <div class="alert alert-success fade show" role="alert">
      Data dengan no. reg {{ session()->get('success') }} berhasil diperbarui.
  </div>
  @elseif(session()->has('danger'))
  <div class="alert alert-danger fade show" role="alert">
      Data dengan no. reg {{ session()->get('danger') }} berhasil dihapus.
  </div>
  @endif
  
  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">Tgl</th>
        <th scope="col">No. Pol</th>
        <th scope="col">No. Tel</th>
        <th scope="col">Nama</th>
        <th scope="col">Keluhan</th>
        <th scope="col">Status</th>
        <td>Aksi</td>
      </tr>
    </thead>
    <tbody>
        @foreach ($masterOrders as $masterOrder)    
        <tr class="@if(session()->has('success')) @if($masterOrder->reg == session()->get('success')) {{ 'table-success' }} @endif @endif">
            <td>{{ $masterOrder->created_at }}</td>
            <td>{{ $masterOrder->nopol }}</td>
            <td>{{ $masterOrder->tel }}</td>
            <td>{{ $masterOrder->name }}</td>
            <td>{{ $masterOrder->message }}</td>
            <td>
                <form action="/master_order/{{ $masterOrder->id }}" method="POST">
                  @method('put')
                  @csrf
                  <input type="hidden" name="id" value="{{ $masterOrder->id }}">
                    <div class="row">
                        <div class="col-5">
                            <select name="state" id="state" class="form-select" onchange="$.fn.enableButton('{{ '#btn-'.$masterOrder->id }}');" {{ ($masterOrder->state == 2 ? 'disabled' : '') }}>
                                <option value="-1" {{ ($masterOrder->state == -1 ? 'selected' : '') }}>Belum diekskusi</option>
                                <option value="0" {{ ($masterOrder->state == 0 ? 'selected' : '') }}>Dibatalkan</option>
                                <option value="1" {{ ($masterOrder->state == 1 ? 'selected' : '') }} {{ ($masterOrder->state == 1 ? 'disabled' : '') }}>Dieksekusi</option>
                                
                                @if ($masterOrder->state >= 1)
                                <option value="2" {{ ($masterOrder->state == 2 ? 'selected' : '') }} disabled>Selesai</option>
                                @endif

                            </select>
                        </div>
                        <div class="col-5">
                            <button type="submit" class="btn btn-success dynamic-disable px-2" {{ ($masterOrder->state >= 1 ? 'disabled' : '') }} id="btn-{{ $masterOrder->id }}"><i class="bi bi-arrow-repeat"></i> <span>Perbarui</span></button>
                        </div>
                    </div>
                </form>
            </td>
            <td>
                <a href="/karyawan/master_order/{{ $masterOrder->id }}"><button class="btn btn-primary px-2"><i class="bi bi-eye"></i></button></a>
                <form action="/master_order/{{ $masterOrder->id }}" method="POST" class="d-inline">
                    @method('delete')
                    @csrf
                    <input type="hidden" name="id" value="{{ $masterOrder->id }}">
                    <button type="submit" class="btn btn-danger px-2"><i class="bi bi-trash"></i></button>
                </form>
            </td>
        </tr>
        @endforeach
    </tbody>
  </table>
</div>

@endsection