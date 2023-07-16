@extends('templates.layouts.main')
@extends('templates.components.header')
@extends('templates.components.footer')
@extends('templates.components.navigation')

@section('content')
<section class="container">
    {{-- Jika keadaanya sudah pernah pesan, hindari terjadi pemesanan pada master order yang sama --}}
    @if ($state == 1)
    <div class="row">
        <div class="col-lg-6">
            <div class="alert alert-danger" role="alert">
                <h4 class="alert-heading">Pesanan sudah dibuat!</h4>
                <p>Anda telah selesai membuat pesanan. Periksa status pesanan anda <a href="/pemesan/detail_order">disini!</a></p>
                <hr>
                <p class="mb-0">Untuk membatalkan pesanan, hubungi langsung <a href="/tentang_kami">karyawan kami</a>.</p>
            </div>
        </div>
    </div>

    {{-- Jika tidak, laukukan pemesanan --}}
    @else
    <h2>Mulai Melakukan Pesanan</h2>
    <div class="row">
        <div class="col-lg-9 my-3">
            <h3 class="mb-4">Apa yang ingin pesan?</h3>

            @if (session()->has('danger'))
            <div class="alert alert-danger" role="alert">
                Pesanan salah!
            </div>
            @endif

            {{-- Formulir pemesanan --}}
            <form action="/master_order/{{ encrypt($master_order[0]->id) }}/order" method="POST">
                @csrf
                <input type="hidden" name="master_order" id="master_order" value="{{ encrypt($master_order[0]->id) }}">
                <div class="mb-3">
                    <div class="table-responsive">
                        <table class="table table-hover table-striped-columns text-center align-middle">
                            <thead>
                                <tr class="table-dark">
                                    <th width="80">No</th>
                                    <th>Deskripsi</th>
                                    <th width="80">Stok</th>
                                    <th>Harga</th>
                                    <th width="80">Beli</th>
                                </tr>
                            </thead>
                            <tbody>
                                @foreach ($availability_categories as $availability_category)
                                <tr class="table-active table-dark">
                                    <td colspan="5">{{ $availability_category->name }}</td>
                                </tr>
                                    @foreach ($availabilities->where('availability_category', $availability_category->id) as $availability)
                                    <tr>
                                        <td>{{ $loop->index + 1 }}</td>
                                        <td>{{ $availability->name }}</td>
                                        <td>{{ $availability->qty }}</td>
                                        <td>{{ $availability->price }}</td>
                                        <td>
                                            <input type="hidden" name="availability[]" id="availability" value="{{ $availability->id }}">
                                            <input type="hidden" name="price[]" id="price" value="{{ $availability->price }}">
                                            <input type="hidden" name="oldQty[]" id="oldQty" value="{{ $availability->qty }}">
                                            <input type="number" name="qty[]" id="qty" class="form-control" value="0" min="0" max="{{ $availability->qty }}">
                                        </td>
                                    </tr>
                                    @endforeach
                                @endforeach
                            </tbody>
                        </table>
                    </div>
                </div>
                <button type="submit" class="btn btn-primary">Mulai Pemesanan!</button>
            </form>
        </div>

        {{-- Data master order --}}
        <div class="col-lg-3 my-3">
            <h3 class="mb-4">Identitas</h3>
            <table class="table">
                <tr>
                    <th width="100">No. Reg</th>
                    <td width="10">:</td>
                    <td class="text-danger">{{ $master_order[0]->reg }}</td>
                </tr>
                <tr>
                    <th width="100">Nama</th>
                    <td width="10">:</td>
                    <td>{{ $master_order[0]->name }}</td>
                </tr>
                <tr>
                    <th width="100">No. Telp</th>
                    <td width="10">:</td>
                    <td>{{ $master_order[0]->tel }}</td>
                </tr>
                <tr>
                    <th width="100">No. Pol</th>
                    <td width="10">:</td>
                    <td>{{ $master_order[0]->nopol }}</td>
                </tr>
                <tr>
                    <th width="100">Keluhan</th>
                    <td width="10">:</td>
                    <td>{{ $master_order[0]->message }}</td>
                </tr>
            </table>

            <div class="alert alert-warning" roler="alert">
                <span>Catat <strong>NO. REG</strong> untuk mengecek pemesanan!</span>
            </div>
            <div class="alert alert-warning" roler="alert">
                <span>Anda tidak dapat mengedit pesanan</span>
            </div>
        </div>
    </div>
    @endif
</section>
@endsection