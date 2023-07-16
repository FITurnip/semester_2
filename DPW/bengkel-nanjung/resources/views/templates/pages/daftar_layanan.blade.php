@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Daftar Ketersediaan</h2>
<div class="table-responsive">
  <a href="/{{ (auth()->user()->user_type == 1) ? 'admin' : 'karyawan' }}/availability/create"><button class="btn btn-primary my-2"><i class="bi bi-plus-circle me-2"></i>Tambah</button></a>

  @if(session()->has('success'))
  <div class="alert alert-success fade show" role="alert">
      Data berhasil diperbarui.
  </div>
  @elseif(session()->has('danger'))
  <div class="alert alert-danger fade show" role="alert">
    Data berhasil dihapus.
  </div>
  @elseif(session()->has('limit'))
    <div class="alert alert-warning fade show" role="alert">
        Data dengan id {{ session()->get('limit') }} memiliki jumlah yang tidak dapat ditampung
    </div>
  @endif

  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">No</th>
        <th scope="col">Kategori</th>
        <th scope="col">Nama</th>
        <th scope="col">Qty</th>
        <th scope="col">Harga Satuan</th>
        <th scope="col">Kondisi</th>
        <th scope="col">Tambah</th>
        <th scope="col">Thumbnail</th>
        <th scope="col">TIndakan</th>
      </tr>
    </thead>

    <tbody>
        @foreach ($availabilities as $availability)    
        <tr class="@if(session()->has('success'))
                      @if($availability->id == session()->get('success')) {{ 'table-success' }} @endif
                   @elseif(session()->has('limit'))
                      @if($availability->id == session()->get('limit')) {{ 'table-warning' }} @endif @endif">

            <td>{{ $loop->index + 1 }}</td>
            <td>{{ $availability->availabilityCategory->name }}</td>
            <td>{{ $availability->name }}</td>
            <td>{{ $availability->qty }}</td>
            <td>{{ $availability->price }}</td>

            <td>
                <form action="/availability/{{ $availability->id }}" method="POST">
                    @method('put')
                    @csrf
                    <input type="hidden" name="id" value="{{ $availability->id }}">

                    <div class="row">
                        <div class="col-7">
                            <select name="state" id="state" class="form-select" onchange="$.fn.enableButton('{{ '#state-'.$availability->id }}');">
                                <option value="0" {{ ($availability->state == 0 ? 'selected' : '') }}>Blokir</option>
                                <option value="1" {{ ($availability->state == 1 ? 'selected' : '') }}>Dijual</option>
                            </select>
                        </div>
                        <div class="col-5">
                            <button type="submit" class="btn btn-success dynamic-disable px-2" id="state-{{ $availability->id }}"><i class="bi bi-arrow-repeat"></i> <span>Perbarui</span></button>
                        </div>
                    </div>

                </form>
            </td>

            <td>
                <form action="/availability/{{ $availability->id }}" method="POST">
                    @method('put')
                    @csrf
                      <div class="row">
                        <input type="hidden" name="oldQty" value="{{ $availability->qty }}">
                          <div class="col-4">
                              @php
                                  $max = 1000 - $availability->qty;
                              @endphp
                              <input type="number" name="qty" id="qty" value="{{ ($max == 0) ? '0' : '1' }}" class="form-control" min="{{ '-' . $availability->qty }}" max="{{ $max }}" onchange="$.fn.enableButton('{{ '#add-'.$availability->id }}');">
                          </div>
                          <div class="col-5">
                              <button type="submit" class="btn btn-primary dynamic-disable px-2" id="add-{{ $availability->id }}"><i class="bi bi-plus-circle-dotted"></i> <span>Tambah</span></button>
                          </div>
                      </div>
                  </form>
            </td>
            
            @php
              if($availability->photo) $photo = asset('storage/' . $availability->photo);
              else $photo = asset('img/winter-tires-g20c2dbe32_1920.jpg');
            @endphp
            <td><a href="{{ $photo }}" target="_blank"><button class="btn btn-info px-2"><i class="bi bi-file-earmark-image"></i> <span>Lihat</span></button></a></td>

            <td>
              <a href="/{{ (auth()->user()->user_type == 1) ? 'admin' : 'karyawan' }}/availability/update/{{ $availability->id }}"><button class="btn btn-secondary px-2"><i class="bi bi-pencil-square"></i> <span>Edit</span></button></a>
              <a href="/{{ (auth()->user()->user_type == 1) ? 'admin' : 'karyawan' }}/availability/show/{{ $availability->id }}"><button class="btn btn-info px-2"><i class="bi bi-eye"></i> <span>Lihat</span></button></a>
              {{-- <form action="/availability/{{ $availability->id }}" method="post" class="d-inline">
                @csrf
                @method('delete')
                <button type="submit" class="btn btn-danger px-2" onclick="return confirm('Hapus permanen?')"><i class="bi bi-trash-fill"></i> <span>Hapus</span></button>
              </form> --}}
            </td>
        </tr>
        @endforeach
    </tbody>
  </table>
</div>
@endsection