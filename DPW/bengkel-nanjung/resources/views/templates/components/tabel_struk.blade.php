@section('receipt_table')
<table class="table table-hover table-striped-columns text-center">
    <thead>
        <tr class="table-dark">
            <th>No</th>
            <th>Deskripsi</th>
            <th>Jum</th>
            <th>Harga</th>
            <th>Biaya</th>
        </tr>
    </thead>
    <tbody>
        @empty($orders[0]->id)
            <tr class="table-active table-dark">
                <td colspan="5">Jenis Y</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Nama</td>
                <td>1</td>
                <td>Rp 90000</td>
                <td>Rp 90000</td>
            </tr>
            <tr>
                <td>2</td>
                <td>Nama</td>
                <td>1</td>
                <td>Rp 90000</td>
                <td>Rp 180000</td>
            </tr>
            <tr class="table-active table-dark">
                <td colspan="5">Jenis Y</td>
            </tr>
            <tr>
                <td>3</td>
                <td>Nama</td>
                <td>1</td>
                <td>Rp 90000</td>
                <td>Rp 90000</td>
            </tr>
            <tr>
                <td>4</td>
                <td>Nama</td>
                <td>1</td>
                <td>Rp 90000</td>
                <td>Rp 180000</td>
            </tr>
        @else
            @foreach ($orders as $order)
                @if ($loop->index == 0)
                    <tr class="table-active table-dark">
                        <td colspan="5">{{ $availability_categories->where('id', $order->availabilities->availability_category)->first()->name }}</td>
                    </tr>
                @elseif($order->availabilities->availability_category != $orders[$loop->index - 1]->availabilities->availability_category)
                    <tr class="table-active table-dark">
                        <td colspan="5">{{ $availability_categories->where('id', $order->availabilities->availability_category)->first()->name }}</td>
                    </tr>                       
                @endif
                <tr>
                    <td>{{ $loop->index + 1 }}</td>
                    <td>{{ $order->availabilities->name }}</td>
                    <td>{{ $order->qty }}</td>
                    <td>{{ $order->price }}</td>
                    <td>{{ $order->total_price }}</td>
                </tr>
            @endforeach
        @endempty
    </tbody>
    <tfoot>
        <tr class="table-secondary">
            <td colspan="4"><strong>Total Keseluruhan</strong></td>
            <td><strong id="totprice">
                @isset($master_order->total_price)
                    {{ $master_order->total_price }}
                @else
                    {{ 'Rp XXXXXX' }}
                @endisset
                </strong></td>
        </tr>
    </tfoot>
</table>
@endsection