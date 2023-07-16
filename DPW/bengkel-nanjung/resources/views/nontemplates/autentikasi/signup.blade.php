@extends('templates.layouts.main')
@extends('templates.css.login')

@section('content')
    <main class="form-signup w-100 m-auto text-white">
        <form action="/signup" method="post" enctype="multipart/form-data">
            @csrf
            <div class="text-center">
                <h1 class="h3 mb-2 text-warning">BENGKEL NANJUNG</h1>
                
                @if (session()->has('success'))
                <div class="alert alert-success fade show" role="alert">
                    <strong>{{ session()->get('success') }}</strong>
                </div>
                @endif
    
                <span class="mb-4">Bekerjalah bersama kami dengan mendaftar dsini!</span>
            </div>
            
            <div class="row">
                <div class="col-md-6">
                    <legend class="text-center text-small mt-2">Identitas</legend>
                    <div class="form-floating text-dark my-3">
                        <input type="text" class="form-control @error('name') is-invalid @enderror" id="name" placeholder="name" name="name" value="{{ old('name') }}" required>
                        <label for="name">Nama</label>
                        @error('name')
                            <div class="form-text text-danger mx-3">Nama tidak valid</div>
                        @else
                            <div class="form-text text-white mx-3">Min. 3 karakter</div>
                        @enderror
                    </div>
                    <div class="form-floating text-dark my-3">
                        <input type="tel" class="form-control @error('tel') is-invalid @enderror" id="tel" placeholder="tel" name="tel" value="{{ old('tel') }}" required>
                        <label for="tel">No. Telp</label>
                        @error('tel')
                            <div class="form-text text-danger mx-3">No. Telp tidak valid</div>
                        @else
                            <div class="form-text text-white mx-3">Min. 10 & Maks. 13</div>
                        @enderror
                    </div>
                    <div class="form-floating text-dark my-3">
                        <select name="gender" id="gender" class="form-select">
                            <option value="1" {{ (old('gender') == 1 ? 'selected' : '') }}>Laki-laki</option>
                            <option value="2" {{ (old('gender') == 2 ? 'selected' : '') }}>Perempuan</option>
                        </select>
                        <label for="gender">Jenis Kelamin</label>
                    </div>
                    <div class="form-floating text-dark my-3">
                        <input type="file" name="photo" id="photo" class="form-control">
                        <label for="photo">Foto Profil</label>
                        @error('photo')
                            <div class="form-text text-danger mx-3">Photo tidak valid</div>
                        @enderror
                    </div>
                </div>
                <div class="col-md-6">
                    <legend class="text-center text-small mt-2">Akun</legend>
                    <div class="form-floating text-dark my-3">
                        <input type="text" class="form-control @error('username') is-invalid @enderror" id="username" placeholder="username" name="username" value="{{ old('username') }}" required>
                        <label for="username">Username</label>
                        @error('username')
                            <div class="form-text text-danger mx-3">Username tidak valid/pernah dipakai</div>
                        @else
                            <div class="form-text text-white mx-3">Min. 3 karakter</div>
                        @enderror
                    </div>
                    <div class="form-floating text-dark my-3">
                        <input type="password" class="form-control @error('password') is-invalid @enderror" id="password" placeholder="password" name="password" required>
                        <label for="password">Password</label>
                        @error('password')
                            <div class="form-text text-danger mx-3">Password tidak valid</div>
                        @else
                            <div class="form-text text-white mx-3">Min. 8 karakter</div>
                        @enderror
                    </div>
                </div>
            </div>

            <button class="w-100 btn btn-lg btn-success" type="submit">Sign up</button>
        </form>

        <p class="my-3">
            Sudah punya akun? <a href="/login" class="text-warning">Login disini</a><br>
            <a href="/">Kembali ke Beranda</a>
        </p>
        <p class="mt-4 mb-3">&copy; 2023</p>
    </main>
@endsection