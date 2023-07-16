@extends('templates.layouts.main')
@extends('templates.css.login')

@section('content')
    <main class="form-signin w-100 m-auto text-white">
        <form action="/login" method="post">
            @csrf
            <div class="text-center">
                <h1 class="h3 mb-3 text-warning">BENGKEL NANJUNG</h1>
                <h2 class="h5 mb-3 fw-normal">Silahkan Login</h1>
                    
                @if (session()->has('danger'))
                <div class="alert alert-danger fade show" role="alert">
                    <strong>{{ session()->get('danger') }}</strong>
                </div>
                @endif
            </div>
        
            <div class="form-floating text-dark my-2">
                <input type="text" class="form-control @error('username') is-invalid @enderror" id="username" placeholder="username" name="username" value="{{ old('username') }}" required>
                <label for="username">Username</label>
                @error('username')
                    <div class="form-text text-danger mx-3">Username tidak valid</div>
                @else
                    <div class="form-text text-white mx-3">Min. 3 karakter</div>
                @enderror
            </div>
            <div class="form-floating text-dark my-2">
                <input type="password" class="form-control @error('password') is-invalid @enderror" id="password" placeholder="password" name="password" value="{{ old('password') }}" required>
                <label for="password">Password</label>
                @error('password')
                    <div class="form-text text-danger mx-3">Password tidak valid</div>
                @else
                    <div class="form-text text-white mx-3">Min. 8 karakter</div>
                @enderror
            </div>

            <button class="w-100 btn btn-lg btn-primary" type="submit">Login</button>
        </form>

        <p class="my-3">
            Tidak punya akun? <a href="/signup" class="text-warning">Daftar disini</a><br>
            <a href="/">Kembali ke Beranda</a>
        </p>
        <p class="mt-4 mb-3">&copy; 2023</p>
    </main>
@endsection