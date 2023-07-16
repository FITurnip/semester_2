<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class AvailabilityCategory extends Model
{
    use HasFactory;
    
    protected $table = 'availability_categories';
    protected $guarded = ['id'];
    public $timestamps = false;
}
