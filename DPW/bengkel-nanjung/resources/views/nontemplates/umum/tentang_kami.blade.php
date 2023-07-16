@extends('templates.pages.main')
@extends('templates.components.header')
@extends('templates.components.navigation')
@extends('templates.components.footer')

@section('main-content')
    <div style="background-image: linear-gradient(rgb(0, 0, 0, 0.7), rgb(0, 0, 0, 0.7)), url('img/winter-tires-g20c2dbe32_1920.jpg'); background-position: center; height: 300px; position: relative;">
        <div style="margin: 0; position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);" class="text-white">
            <p>Kami siap menyediakan apa yang Anda perlukan!</p>
            <table>
                <tr>
                    <th width="80">Alamat</th>
                    <td width="10">:</td>
                    <td class="text-warning">Nanjung</td>
                </tr>
                <tr>
                    <th>No. Telp</th>
                    <td>:</td>
                    <td><a href="tel:+6289999999999" class="text-warning">+62 899 9999 9999</a></td>
                </tr>
            </table>
        </div>
    </div>
@endsection


@section('second-content')
    <h2>Karyawan</h2>
    <div class="row">
        @foreach ($employees as $employee)    
        <div class="card col-md-4 p-3">
            @php
                if($employee->photo) $photo = asset('storage/' . $employee->photo);
                else $photo = asset('img/auto-repair-g2eb98b15d_640.jpg');
            @endphp
            <img src="{{ $photo }}" class="card-img-top" alt="...">
            <div class="card-body">
              <h5 class="card-title">{{ $employee->name }}</h5>
            </div>
            <ul class="list-group list-group-flush">
              <li class="list-group-item">No. Telp : {{ $employee->tel }}</li>
            </ul>
        </div>
        @endforeach
    </div>    
@endsection