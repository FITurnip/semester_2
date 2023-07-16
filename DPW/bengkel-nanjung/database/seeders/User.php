<?php

namespace Database\Seeders;
 
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Hash;
use Illuminate\Support\Str;

class User extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        \App\Models\User::factory()->create([
            'username' => 'admin',
            'password' => Hash::make('adminroot'),
            'user_type' => 1,
            'state' => 1
        ]);
        
        \App\Models\User::factory()->create([
            'username' => 'staff1',
            'password' => Hash::make('staff1test'),
            'user_type' => 2,
            'state' => 1
        ]);
        
        \App\Models\User::factory()->create([
            'username' => 'staff2',
            'password' => Hash::make('staff2test'),
            'user_type' => 2,
            'state' => 0
        ]);
        
        \App\Models\User::factory()->create([
            'username' => 'staff3',
            'password' => Hash::make('staff3test'),
            'user_type' => 2,
            'state' => 1
        ]);
    }
}
