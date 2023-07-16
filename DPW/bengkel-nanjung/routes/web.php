<?php

use App\Http\Controllers\AdminController;
use App\Http\Controllers\GeneralController;
use App\Http\Controllers\AuthController;
use App\Http\Controllers\AvailabilityCategoryController;
use App\Http\Controllers\AvailabilityController;
use App\Http\Controllers\EmployeeController;
use App\Http\Controllers\MasterOrderController;
use App\Http\Controllers\OrderController;
use App\Http\Controllers\ReceiptController;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

// UMUM
Route::get('/', [GeneralController::class, 'index']);
Route::get('/ketersediaan', [GeneralController::class, 'ketersediaan']);
Route::get('/getCategory/{id_category}', [GeneralController::class, 'getCategory']);
Route::get('/getAvailability/{id_availability}', [GeneralController::class, 'getAvailabilityByCategory']);
Route::get('/tentang_kami', [GeneralController::class, 'tentang_kami']);
Route::get('/pemesan', [GeneralController::class, 'pemesan']);
Route::get('/pemesan/detail_order', [GeneralController::class, 'show_detail_order']);
Route::post('/pemesan/detail_order', [GeneralController::class, 'show_receipt']);

// AUTENTIKASI
Route::post('/login', [AuthController::class, 'authenticate']);
Route::group(['middleware' => ['guest']], function() {
    Route::get('/login', [AuthController::class, 'index']);
    Route::get('/signup', [AuthController::class, 'show_signup']);
    Route::post('/signup', [AuthController::class, 'create_account']);
});
Route::group(['middleware' => ['auth']], function() {
    Route::get('/dashboard', [AuthController::class, 'dashboard']);
    Route::post('/dashboard', [AuthController::class, 'dashboard']);
    Route::post('/auth/edit_account', [AuthController::class, 'update']);
    Route::post('/logout', [AuthController::class, 'logout']);
    Route::post('/auth/accountActivation', [AuthController::class, 'accountActivation']);
});

// PEMESAN
Route::resource('/master_order', MasterOrderController::class);
Route::resource('master_order.order', OrderController::class)->except('show', 'edit', 'update', 'destroy');
Route::resource('/receipt', ReceiptController::class);

// USER
Route::resource('/availability', AvailabilityController::class);
Route::resource('/availabilityCategory', AvailabilityCategoryController::class);

// KARYAWAN
Route::group(['middleware' => ['employee']], function() {
    Route::get('/karyawan', [EmployeeController::class, 'index']);
    Route::get('/karyawan/master_order', [EmployeeController::class, 'master_order']);
    Route::get('/karyawan/master_order/{id_master_order}', [EmployeeController::class, 'show_order']);
    Route::get('/karyawan/receipt', [EmployeeController::class, 'show_receipt']);
    Route::get('/karyawan/receipt/{receipt_id}', [EmployeeController::class, 'show_the_receipt']);
    Route::get('/karyawan/availability', [EmployeeController::class, 'show_availability']);
    Route::get('/karyawan/availability/show/{availability_id}', [EmployeeController::class, 'show_the_availability']);
    Route::get('/karyawan/availability/create', [EmployeeController::class, 'show_create_availability']);
    Route::get('/karyawan/availability/update/{availability_id}', [EmployeeController::class, 'show_update_availability']);
    Route::get('/karyawan/availabilityCategory', [EmployeeController::class, 'show_availability_category']);
    Route::get('/karyawan/account', [EmployeeController::class, 'edit_account']);
    Route::get('/karyawan/identity', [EmployeeController::class, 'edit_identity']);
    Route::post('/karyawan/identity', [EmployeeController::class, 'update_identity']);
});

// ADMIN
Route::group(['middleware' => ['admin']], function() {
    Route::get('/admin', [AdminController::class, 'index']);
    Route::get('/admin/employee', [AdminController::class, 'employee']);
    Route::get('/admin/account', [AdminController::class, 'edit_account']);
    Route::get('/admin/receipt', [AdminController::class, 'show_receipt']);
    Route::get('/admin/receipt/{receipt_id}', [AdminController::class, 'show_the_receipt']);
    Route::get('/admin/availability', [AdminController::class, 'show_availability']);
    Route::get('/admin/availability/show/{availability_id}', [AdminController::class, 'show_the_availability']);
    Route::get('/admin/availability/create', [AdminController::class, 'show_create_availability']);
    Route::get('/admin/availability/update/{availability_id}', [AdminController::class, 'show_update_availability']);
    Route::get('/admin/availabilityCategory', [AdminController::class, 'show_availability_category']);
});

?>