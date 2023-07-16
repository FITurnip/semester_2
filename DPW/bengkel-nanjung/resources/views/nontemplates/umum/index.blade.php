@extends('templates.pages.main')
@extends('templates.components.header')
@extends('templates.components.navigation')
@extends('templates.components.footer')

@section('main-content')
    <div style="background-image: linear-gradient(rgb(0, 0, 0, 0.7), rgb(0, 0, 0, 0.7)), url('img/winter-tires-g20c2dbe32_1920.jpg'); background-position: center; height: 300px; position: relative;">
        <div style="margin: 0; position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);" class="text-center">
            <a href="/master_order/create"><button class="btn btn-success me-2 m-1">Mulai Pemesanan!</button></a>&nbsp;
            <a href="/pemesan/detail_order"><button class="btn btn-outline-warning me-2 m-1">Cek Pemesanan</button></a>
        </div>
    </div>
@endsection


@section('second-content')
    <h2 class="mb-3 text-center">Apa yang kami sediakan?</h2>

    <div class="row">        
    @foreach ($categories->take(9) as $category)

        <div class="card col-md-4 p-3">
            <img src="img/winter-tires-g20c2dbe32_1920.jpg" class="card-img-top" alt="...">
            <div class="card-body">
              <h5 class="card-title">{{ $category->name }}</h5>
              <p class="card-text">{{ $category->desc }}</p>
            </div>

            <ul class="list-group list-group-flush">
            @foreach ($availabilities->where('availability_category', $category->id)->take(3) as $availability)
                <li class="list-group-item">{{ $availability->name }}</li>
            @endforeach
            </ul>
        </div>

    @endforeach
    </div>        

    <div  class="text-center m-3">
        <a href="/ketersediaan"><button class="btn btn-outline-success me-2 m-1">Lihat Selengkapnya!</button></a>
    </div>
@endsection