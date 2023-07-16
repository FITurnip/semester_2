@extends('templates.pages.cek_struk')
@extends('templates.components.sidebar_dashboard.admin')

@section('recorded_data')
{{-- Menampilkan Daftar Struk --}}
@if($receipts)    
    @foreach ($receipts as $receipt)    
    <tr>
        <td>{{ $receipt->masterOrder->reg }}</td>
        <td>{{ $receipt->masterOrder->name }}</td>
        <td>{{ $receipt->masterOrder->total_price }}</td>
        <td>
            @switch($receipt->state)
                @case(0)
                    {{ 'Belum dibayar' }}
                    @break
                @case(1)
                    {{ 'Telah dibayar' }}
                    @break
            @endswitch
        </td>
        <td>
            <a href="/admin/receipt/{{ $receipt->masterOrder->reg }}"><button class="btn btn-primary px-2"><i class="bi bi-eye"></i></button></a>
        </td>
    </tr>
    @endforeach
@else
    <tr>
        <td colspan="5">Tidak ada data</td>
    </tr>
@endif
@endsection