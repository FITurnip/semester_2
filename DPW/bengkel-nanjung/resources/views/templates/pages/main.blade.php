@extends('templates.layouts.main')

@section('content')
    <section class="container my-3">
        @yield('main-content')
    </section>

    <section class="container my-3">
        @yield('second-content')
    </section>
@endsection