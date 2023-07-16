<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('master_orders', function (Blueprint $table) {
            $table->id();
            $table->string('reg');
            $table->timestamps();
            $table->string('name');
            $table->string('tel');
            $table->string('nopol');
            $table->integer('state'); // -1 untuk default, 0 untuk batal, 1 untuk sedang diekskusi, 2 untuk selesai
            $table->string('message');
            $table->unsignedBigInteger('total_price');
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('master_orders');
    }
};
