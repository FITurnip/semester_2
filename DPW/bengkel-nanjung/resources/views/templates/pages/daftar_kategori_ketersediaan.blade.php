@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Daftar Kategori Ketersediaan</h2>
<div class="table-responsive">
  @if(session()->has('success'))
  <div class="alert alert-success fade show" role="alert">
    {{ session()->get('success') }}
  </div>
  @elseif(session()->has('update'))
  <div class="alert alert-success fade show" role="alert">
      Data berhasil diperbarui.
  </div>
  @elseif(session()->has('danger'))
  <div class="alert alert-danger fade show" role="alert">
    Data berhasil dihapus.
  </div>
  @endif

  <table class="table table-striped table-sm">
    <thead>
      <tr class="table-dark">
        <th scope="col">No</th>
        <th scope="col">Nama</th>
        <th scope="col">Deskripsi</th>
        <th scope="col">Thumbnail</th>
        <th scope="col">Kondisi</th>
        <th scope="col">Tindakan</th>
      </tr>
    </thead>
    <tbody>
        {{-- Formulir Penambahan Data --}}
        <form action="/availabilityCategory" method="post" enctype="multipart/form-data">
        @csrf
            <tr>
                <td>#</td>
                <td>
                  <div class="row">
                    <div class="col-9">
                      <input type="text" name="name" id="name" class="form-control" placeholder="Nama Kategori" required>
                    </div>
                  </div>
                </td>
                <td>
                  <div class="row">
                    <div class="col-11">
                      <input type="text" name="desc" id="desc" class="form-control" placeholder="Deskripsi Kategori" required>
                    </div>
                  </div>
                </td>
                <td>
                  <div class="row">
                    <div class="col-9">
                      <div class="input-group">
                        <input type="file" class="form-control" id="photo" name="photo">
                        <label class="input-group-text bg-secondary px-2 text-white" for="photo"><i class="bi bi-file-earmark-image"></i></label>
                      </div>
                    </div>
                  </div>
                </td>
                <td>
                  <select name="state" id="state" class="form-select">
                    <option value="1">Dapat digunakan</option>
                    <option value="0">Diblokir</option>
                  </select>
                <td>
                  <button type="submit" class="btn btn-primary"><i class="bi bi-check-circle"></i> Simpan Data Baru</button>
                </td>
            </tr>
        </form>

        {{-- Formulir Pengeditan data --}}
        @foreach ($availabilityCategories as $item)    
        <form action="/availabilityCategory/{{ $item->id }}" method="post" enctype="multipart/form-data">
          @csrf
          @method('put')

            <tr class="@if(session()->has('update'))
              @if($item->id == session()->get('update')) {{ 'table-success' }} @endif @endif">

                <td>{{ $loop->index + 1 }}</td>
                <td>
                  <div class="row">
                    <div class="col-9">
                      <input type="text" name="name" id="name" value="{{ $item->name }}" class="form-control" onchange="$.fn.enableButton('{{ '#update-' . $item->id }}');">
                    </div>
                  </div>
                </td>
                <td>
                  <div class="row">
                    <div class="col-11">
                      <input type="text" name="desc" id="desc" value="{{ $item->desc }}" class="form-control" onchange="$.fn.enableButton('{{ '#update-' . $item->id }}');">
                    </div>
                  </div>
                </td>

                @php
                if($item->photo) $photo = asset('storage/' . $item->photo);
                else $photo = asset('img/winter-tires-g20c2dbe32_1920.jpg');
                @endphp

                <td>
                  <div class="row">
                    <div class="col-9">
                      <div class="input-group">
                        <input type="file" class="form-control" id="photo" aria-describedby="photo" aria-label="Upload" name="photo" onchange="$.fn.enableButton('{{ '#update-' . $item->id }}');">
                        <button class="btn btn-secondary px-2" type="button"><a href="{{ $photo }}" target="_blank" class="text-decoration-none text-white"><i class="bi bi-file-earmark-image"></i> <span>Lihat</span></a></button>
                      </div>
                    </div>
                  </div>
                </td>

                <td>
                  <select name="state" id="state" class="form-select" onchange="$.fn.enableButton('{{ '#update-' . $item->id }}');">
                    <option value="1" {{ ($item->state == 1 ? 'selected' : '') }}>Dapat digunakan</option>
                    <option value="0" {{ ($item->state == 0 ? 'selected' : '') }}>Diblokir</option>
                  </select>
                </td>

                <td>
                  <button type="submit" class="btn btn-success dynamic-disable px-2" id="update-{{ $item->id }}"><i class="bi bi-arrow-repeat"></i> Perbarui</button>
                </td>
            </tr>
        </form>
        @endforeach
    </tbody>
  </table>
</div>
@endsection