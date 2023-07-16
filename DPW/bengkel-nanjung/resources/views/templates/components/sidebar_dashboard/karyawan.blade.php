@section('sidebar_menu')
<nav id="sidebarMenu" class="col-md-3 col-lg-2 d-md-block bg-body-tertiary sidebar collapse">
    <div class="position-sticky pt-3 sidebar-sticky">
        <h2 class="sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-body-secondary text-uppercase">
          Order
        </h2>
        <ul class="nav flex-column">
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/master_order">
              Master Order
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/receipt">
              Struk
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/availability">
              Ketersediaan
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/availabilityCategory">
              Kategori Ketersediaan
            </a>
          </li>
        </ul>

        <h2 class="sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-body-secondary text-uppercase">
          Akun
        </h2>
        <ul class="nav flex-column">
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/account">
              Akun
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="/karyawan/identity">
              Identitas
            </a>
          </li>
        </ul>
    </div>
</nav>
@endsection