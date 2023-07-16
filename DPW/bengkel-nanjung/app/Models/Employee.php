<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Employee extends Model
{
    use HasFactory;
    protected $table = 'employees';
    protected $guarded = ['id'];
    public $timestamps = false;
    
    public function users() {
        return $this->hasOne(User::class, 'id', 'user');
    }
}
