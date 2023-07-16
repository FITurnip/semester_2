@extends('templates.layouts.dashboard')

@section('content')
<div class="d-flex justify-content-between flex-wrap flex-md-nowrap align-items-center pt-3 pb-2 mb-3 border-bottom">
  <h1 class="h2">Dashboard</h1>
</div>

<h2 class="h3">Struk</h2>
<div class="table-responsive">
    <a href="{{ URL::previous() }}"><button class="btn btn-primary my-2"><i class="bi bi-arrow-left-circle me-2"></i>Kembali</button></a>
    @yield('receipt_table')
</div>
@endsection