<?php

namespace App\Models;

use App\Models\User;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Relations\HasOne;
use Illuminate\Database\Eloquent\Factories\HasFactory;


class Admin extends Model
{
    use HasFactory;
    public $timestamps = false;

    public function user(): HasOne {
        return $this->hasOne(User::class, 'id', 'user');
    }
}
