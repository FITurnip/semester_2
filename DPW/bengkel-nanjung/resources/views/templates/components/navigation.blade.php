@section('left-nav')
    <ul class="nav col-12 col-lg-auto me-lg-auto mb-2 justify-content-center mb-md-0">
        <li><a href="/" class="nav-link px-2  {{ (Request::is('/') ? 'text-secondary' : 'text-white' ) }} ">Beranda</a></li>
        <li><a href="/tentang_kami" class="nav-link px-2 {{ (Request::is('*tentang_kami')) ? 'text-secondary' : 'text-white' }}">Tentang Kami</a></li>
        <li><a href="/ketersediaan" class="nav-link px-2 {{ (Request::is('*ketersediaan')) ? 'text-secondary' : 'text-white' }}">Daftar ketersediaan</a></li>
    </ul>
@endsection

@section('right-nav')
    <ul class="nav col-12 col-lg-auto mb-3 mb-lg-0 me-lg-3 justify-content-center">
        <li><a href="/master_order/create" class="nav-link px-2 {{ (Request::is('*master_order*') ? 'text-secondary' : 'text-white' ) }}">Buat Pesanan!</a></li>
    </ul>    
@endsection