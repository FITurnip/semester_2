@extends('templates.pages.cek_struk')
@extends('templates.components.sidebar_dashboard.karyawan')

@section('recorded_data')

@if(session()->has('success'))
<div class="alert alert-success fade show" role="alert">
    Data dengan no. reg {{ session()->get('success') }} berhasil diperbarui.
</div>
@elseif(session()->has('danger'))
<div class="alert alert-danger fade show" role="alert">
    Data dengan no. reg {{ session()->get('danger') }} berhasil dihapus.
</div>
@endif

@foreach ($receipts as $receipt)    
<tr class="@if(session()->has('success')) @if($receipt->masterOrder->reg == session()->get('success')) {{ 'table-success' }} @endif @endif">
    <td>{{ $receipt->masterOrder->reg }}</td>
    <td>{{ $receipt->masterOrder->name }}</td>
    <td>{{ $receipt->masterOrder->total_price }}</td>
    <td>
        <form action="/receipt/{{ $receipt->id }}" method="POST">
            @method('put')
            @csrf
            <input type="hidden" name="master_order" value="{{ $receipt->master_order }}">
            <input type="hidden" name="id" value="{{ $receipt->id }}">
              <div class="row">
                  <div class="col-5">
                      <select name="state" id="state" class="form-select" onchange="$.fn.enableButton('{{ '#btn-'.$receipt->id }}');" {{ ($receipt->state == 1 ? 'disabled' : '') }}>
                          <option value="0" {{ ($receipt->state == 0 ? 'selected' : '') }}>Belum dibayar</option>
                          <option value="1" {{ ($receipt->state == 1 ? 'selected' : '') }}>Telah dibayar</option>
                      </select>
                  </div>
                  <div class="col-5">
                      <button type="submit" class="btn btn-success dynamic-disable px-2" id="btn-{{ $receipt->id }}" {{ ($receipt->state == 1 ? 'disabled' : '') }}><i class="bi bi-arrow-repeat"></i> <span>Perbarui</span></button>
                  </div>
              </div>
        </form>
    </td>
    <td>
        <a href="/karyawan/receipt/{{ $receipt->masterOrder->reg }}" class="d-inline"><button class="btn btn-primary px-2"><i class="bi bi-eye"></i></button></a>
        <form action="/receipt/{{ $receipt->id }}" method="POST" class="d-inline">
            @method('delete')
            @csrf
            <input type="hidden" name="id" value="{{ $receipt->id }}">
            <button type="submit" class="btn btn-danger px-2"><i class="bi bi-trash"></i></button>
        </form>
    </td>
</tr>
@endforeach
@endsection