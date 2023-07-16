<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Document</title>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.5/font/bootstrap-icons.css">
    <link rel="stylesheet" href="{{ asset('/css/dashboard.css') }}" />
</head>
<body>
    <header class="navbar navbar-dark sticky-top bg-dark flex-md-nowrap p-0 shadow">
        <a class="navbar-brand col-md-3 col-lg-2 me-0 px-3 fs-6 text-warning" href="#">BENGKEL NANJUNG</a>
        <button class="navbar-toggler position-absolute d-md-none collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#sidebarMenu" aria-controls="sidebarMenu" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="w-100"></div>
        <div class="navbar-nav">
            <div class="nav-item text-nowrap">
                <a href="/" class="text-decoration-none">
                    <button type="submit" class="nav-link px-3 border-start">
                        <i class="bi bi-house-fill me-3"></i>Home
                    </button>
                </a>
            </div>
        </div>
        <div class="navbar-nav">
            <div class="nav-item text-nowrap">
                <form action="/logout" method="POST">
                    @csrf
                    <button type="submit" class="nav-link px-3 border-start text-danger">
                        <i class="bi bi-arrow-left-circle-fill me-3"></i>Log ut
                    </button>
                </form>
            </div>
        </div>
    </header>
    
    <div class="container-fluid">
        <div class="row">
            @yield('sidebar_menu')

            <main class="col-md-9 ms-sm-auto col-lg-10 px-md-4">
                @yield('content')
            </main>
        </div>
    </div>
    
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ENjdO4Dr2bkBIFxQpeoTz1HIcje39Wm4jDKdf19U8gI4ddQ3GYNS7NTKfAdVQSZe" crossorigin="anonymous"></script>
    
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.4/jquery.min.js"></script>
    <script>
    $(document).ready(function() {
        $('.dynamic-disable').prop('disabled', true);
    });

    // fungsi untuk mendapatkan data ketersediaan berdasarkan kategorinya
    $.fn.enableButton = function(selector) {
        $(selector).prop('disabled', false);
    };
    </script>
</body>
</html>