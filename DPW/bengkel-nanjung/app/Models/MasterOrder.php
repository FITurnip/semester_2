<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class MasterOrder extends Model
{
    use HasFactory;

    protected $table = 'master_orders';
    protected $guarded = ['id'];

    public $timestamps = false;

    public function order() {
        return $this->belongsTo(Order::class);
    }
}
