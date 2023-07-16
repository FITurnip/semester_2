@section('sidebar_menu')
<nav id="sidebarMenu" class="col-md-3 col-lg-2 d-md-block bg-body-tertiary sidebar collapse">
    <div class="position-sticky pt-3 sidebar-sticky">
        <h2 class="sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-body-secondary text-uppercase">
          Antar Muka
        </h2>
        <ul class="nav flex-column">
          <li class="nav-item">
            <a class="nav-link" href="/admin/receipt">
              Struk
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/admin/availability">
              Ketersediaan
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/admin/availabilityCategory">
              Kategori Ketersediaan
            </a>
          </li>
        </ul>

        <h2 class="sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-body-secondary text-uppercase">
          Akun
        </h2>
        <ul class="nav flex-column">
          <li class="nav-item">
            <a class="nav-link" href="/admin/account">
              Pribadi
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/admin/employee">
              Karyawan
            </a>
          </li>
        </ul>
    </div>
</nav>
@endsection