@extends('templates.pages.main')
@extends('templates.components.header')
@extends('templates.components.navigation')
@extends('templates.components.footer')

@section('main-content')
<h2 id="h2_kepala">Daftar Ketersediaan</h2>
    <form action="" method="GET">
        <div class="row">
          <div class="col-1 align-self-center text-center"><label for="kategori">Kategori</label></div>

          <div class="col-md-3">
            <select name="kategori" id="kategori" class="form-select" aria-label="Default select example">
                @foreach ($categories as $category)
                    <option value="{{ $category->id }}">{{ $category->name }}</option>
                @endforeach
            </select>
          </div>
        </div>
    </form>
@endsection


@section('second-content')
    <div id="induk"></div>
@endsection

@section('js_body')
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.4/jquery.min.js"></script>

<script type="text/javascript">
  // fungsi untuk mendapatkan data ketersediaan berdasarkan kategorinya
  $.fn.getAvailability = function(id_kategori) {
    var url = 'getAvailability/' + id_kategori;

    $.ajax({
      url: url,
      type: 'get',
      dataType: 'json',
      success: function(result) {
        $("#induk").append('<div class="row" id="item"></div>');

        if(result.length > 0) {
          for(var i = 0; i < result.length; i++) {
            $("#item").append(result[i]);
          }
        } else {
          $('#item').append('<div class="alert alert-warning fade show" role="alert"><strong>Maaf...</strong><br/>Tidak ada layanan maupun penjualan pada kategori ini.</div>')
        }

      }
    });
  }

  // menampilkan data dari fungsi di atas
  $(document).ready(function() {
    $.fn.getAvailability(1); // kategori pertama
  });

  $("#kategori").change(function() {
    // fetch id kategori
    var id_kategori = $("#kategori").val(); // dapatkan id kategori terlebih dahulu

    $("#induk").html('');

    $.fn.getAvailability(id_kategori);
    
  });
</script>
@endsection