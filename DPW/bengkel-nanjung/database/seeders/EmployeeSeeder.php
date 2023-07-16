<?php

namespace Database\Seeders;

use App\Models\Employee;
use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class EmployeeSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        Employee::factory()->create([
            'user' => 2,
            'name' => 'franklin',
            'tel' => '08123456789',
            'gender' => 1,
        ]);
        
        Employee::factory()->create([
            'user' => 3,
            'name' => 'impianro',
            'tel' => '08123456789',
            'gender' => 1,
        ]);
        
        Employee::factory()->create([
            'user' => 4,
            'name' => 'turnip',
            'tel' => '08123456789',
            'gender' => 2,
        ]);
        
    }
}
