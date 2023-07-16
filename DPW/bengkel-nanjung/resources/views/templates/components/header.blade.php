@section('header')
    <header class="p-3 text-bg-dark mb-3">
        <div class="container">
          <div class="d-flex flex-wrap align-items-center justify-content-center justify-content-lg-start">
            <a href="/" class="d-flex align-items-center mb-2 mb-lg-0 text-warning text-decoration-none header-title">
              BENGKEL NANJUNG 
            </a>

            @yield('left-nav')
            @yield('right-nav')

    
            <div class="text-end">
              @guest

                <a href="/login"><button type="button" class="btn btn-outline-light me-2">Login</button></a>
                <a href="/signup"><button type="button" class="btn btn-warning">Sign-up</button></a>

              @else

                <div class="dropdown">
                  <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown" aria-expanded="false">
                    <i class="bi bi-person-lines-fill me-4"></i>
                    {{ auth()->user()->username }}
                  </button>
                  <form action="/logout" method="POST">
                    @csrf
                    <ul class="dropdown-menu">
                      <li>
                        <button type="submit" class="dropdown-item" formaction="/dashboard">
                          <i class="bi bi-layout-text-window-reverse me-4"></i>Dashboard
                        </button>
                      </li>
                      <li>
                        <button type="submit" class="dropdown-item">
                          <i class="bi bi-arrow-left-circle-fill me-4"></i>Log ut
                        </button>
                      </li>
                    </ul>
                  </form>
                </div>

              @endguest
            </div>
          </div>
        </div>
      </header>
@endsection