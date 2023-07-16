@extends('templates.layouts.main')
@extends('templates.components.header')
@extends('templates.components.navigation')
@extends('templates.components.footer')

@section('content')
    <section class="container">
        {{-- PENGENCEKAN --}}
        <div id="row">
            <div class="mb-3 col-md-5"><h2>Cek Pemesanan</h2></div>
            <div class="mb-3 col-md-5">
                <form action="/pemesan/detail_order" method="post">
                    @csrf
                    <div class="row">
                        <div class="mb-3 col-lg-7"><input type="text" name="reg" id="reg" class="form-control" placeholder="No. Reg" autofocus></div>
                        <div class="mb-3 col-5"><button type="submit" class="btn btn-primary text-white" id="check">Cek</button></div>
                    </div>
                </form>
                @if (session()->has('warning'))
                    <div class="alert alert-warning fade show" role="alert">
                        <strong>{{ session()->get('warning') }}</strong>
                    </div>
                @endif
            </div>
        </div>

        {{-- RINCIAN --}}
        <div class="row">
            <div class="col-lg-8">
                <div class="text-center">
                    @yield('receipt_table')
                </div>
            </div>
            
            <div class="col-lg-4">
                <table class="table table-secondary">
                    <tr>
                        <th width="100">Ditangani oleh</th>
                        <td width="10">:</td>
                        <td id="employee">
                            @isset($receipt->employee)
                            {{ $receipt->employees->name }}
                            @else
                            {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                    <tr>
                        <th width="100">Kondisi</th>
                        <td width="10">:</td>
                        <td id="state">
                            @isset($master_order->state)
                                @switch($master_order->state)
                                    @case(-1) {{ 'Belum dieksekusi' }} @break
                                    @case(0) {{ 'Dibatalkan' }} @break
                                    @case(1) {{ 'Belum dibayar' }} @break
                                    @case(2) {{ 'Telah dibayar pada ' . $receipt->created_at }}  @break
                                @endswitch
                            @else
                                {{ '-' }}
                            @endif
                        </td>
                    </tr>
                </table>
                <table class="table">
                    <tr>
                        <th width="100">No. Reg</th>
                        <td width="10">:</td>
                        <td id="reg">
                            @isset($master_order->reg)
                                {{ $master_order->reg }}
                            @else
                                {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                    <tr>
                        <th width="100">Nama</th>
                        <td width="10">:</td>
                        <td id="name">
                            @isset($master_order->reg)
                                {{ $master_order->name }}
                            @else
                                {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                    <tr>
                        <th width="100">No. Telp</th>
                        <td width="10">:</td>
                        <td id="tel">
                            @isset($master_order->reg)
                                {{ $master_order->tel }}
                            @else
                                {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                    <tr>
                        <th width="100">No. Pol</th>
                        <td width="10">:</td>
                        <td id="nopol">
                            @isset($master_order->reg)
                                {{ $master_order->nopol }}
                            @else
                                {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                    <tr>
                        <th width="100">Keluhan</th>
                        <td width="10">:</td>
                        <td id="message">
                            @isset($master_order->reg)
                                {{ $master_order->message }}
                            @else
                                {{ '-' }}
                            @endisset
                        </td>
                    </tr>
                </table>
            </div>
        </div>
    </section>
@endsection