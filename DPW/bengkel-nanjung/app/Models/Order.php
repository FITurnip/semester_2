<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Order extends Model
{
    use HasFactory;

    protected $table = 'orders';
    protected $guarded = ['id'];
    public $timestamps = false;

    public function masterOrder() {
        return $this->hasOne(MasterOrder::class, 'id', 'master_order');
    }

    public function availabilities() {
        return $this->hasOne(Availability::class, 'id', 'availability');
    }
}
