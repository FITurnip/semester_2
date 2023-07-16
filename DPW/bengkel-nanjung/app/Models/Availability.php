<?php

namespace App\Models;

use App\Models\AvailabilityCategory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;

class Availability extends Model
{
    use HasFactory;

    protected $table = 'availabilities';
    protected $guarded = ['id'];
    public $timestamps = false;

    /**
     * Get the availability_category that owns the availability
     *
     * @return \Illuminate\Database\Eloquent\Relations\BelongsTo
     */
    public function availabilityCategory()
    {
        return $this->hasOne(AvailabilityCategory::class, 'id', 'availability_category');
    }
}
