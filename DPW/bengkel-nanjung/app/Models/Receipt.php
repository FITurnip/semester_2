<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Receipt extends Model
{
    use HasFactory;

    protected $table = 'receipts';
    protected $guarded = ['id'];
    public $timestamps = false;

    public function masterOrder() {
        return $this->hasOne(MasterOrder::class, 'id', 'master_order');
    }

    public function employees() {
        return $this->hasOne(Employee::class, 'id', 'employee');
    }
}
