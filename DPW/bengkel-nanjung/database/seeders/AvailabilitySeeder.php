<?php

namespace Database\Seeders;

use App\Models\Availability;
use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class AvailabilitySeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        Availability::factory()->create([
            'availability_category' => 1,
            'name' => 'Isi angin',
            'desc' => '-',
            'qty' => 999,
            'price' => 2000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 1,
            'name' => 'Isi nitrogen',
            'desc' => '-',
            'qty' => 99,
            'price' => 5000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 1,
            'name' => 'Perbaikan sebagian',
            'desc' => '-',
            'qty' => 99,
            'price' => 5000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 1,
            'name' => 'Perbaikan penuh',
            'desc' => '-',
            'qty' => 99,
            'price' => 20000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 2,
            'name' => 'Isi angin',
            'desc' => '-',
            'qty' => 999,
            'price' => 2000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 2,
            'name' => 'Isi nitrogen',
            'desc' => '-',
            'qty' => 99,
            'price' => 5000,
            'state' => '1'
        ]);
        
        Availability::factory()->create([
            'availability_category' => 2,
            'name' => 'Perbaikan sebagian',
            'desc' => '-',
            'qty' => 99,
            'price' => 5000,
            'state' => '1'
        ]);
        
    }
}
