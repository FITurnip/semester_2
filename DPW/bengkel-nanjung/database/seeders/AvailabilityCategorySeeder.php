<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;
use App\Models\AvailabilityCategory;

class AvailabilityCategorySeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        AvailabilityCategory::factory()->create([
            'name' => 'Layanan Umum',
            'desc' => 'Pelayanan akan dilakukan oleh staff terbaik kami',
            'state' => '1'
        ]);
        
        AvailabilityCategory::factory()->create([
            'name' => 'Swalayan',
            'desc' => 'Customer dapat melakukan pelayanan secara mandiri',
            'state' => '1'
        ]);

        AvailabilityCategory::factory()->create([
            'name' => 'Ban motor',
            'desc' => 'Ban motor terbaik tersedia di sini',
            'state' => '1'
        ]);

        AvailabilityCategory::factory()->create([
            'name' => 'Ban mobil',
            'desc' => 'Ban mobil terbaik tersedia di sini',
            'state' => '1'
        ]);

        AvailabilityCategory::factory()->create([
            'name' => 'Oli',
            'desc' => 'Oli terbaik tersedia di sini',
            'state' => '1'
        ]);

        AvailabilityCategory::factory()->create([
            'name' => 'Skrup',
            'desc' => 'Skrup terbaik tersedia di sini',
            'state' => '1'
        ]);

        AvailabilityCategory::factory()->create([
            'name' => 'Mur',
            'desc' => 'Mur terbaik tersedia di sini',
            'state' => '1'
        ]);
    }
}
