<?php

//fungsi list dept
function f_dept(){
    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_departments order by dept_name ASC";

    // buat query
    $result = $conn->query($sql);

    // eksekusi query
    $data= mysqli_fetch_all($result,MYSQLI_ASSOC);
    mysqli_free_result($result);
    return $data;
}


//fungsi list job level
function f_job_level(){
    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_job_levels order by name asc";

    //buat query
    $result = mysqli_query($conn,$sql);

    //eksekusi query
    $data= mysqli_fetch_all($result,MYSQLI_ASSOC);
    mysqli_free_result($result);
    return $data;
}


//fungsi get single employee
function f_get_employee($employee_id){
    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_employees where employee_id = '$employee_id'";

    //buat query
    $result = mysqli_query($conn,$sql);

    //eksekusi query
    $data= mysqli_fetch_assoc($result);
    mysqli_free_result($result);
    return $data;
}

//fungsi semua employee
function f_all_employee(){
    //buat koneksi
    $conn = mysqli_connect("localhost","root","","db_ujicoba");
 
    //buat string sql
    $sql = "SELECT
            t_employees.employee_id as emp_id,
            t_employees.`name` as emp_name,
            t_departments.dept_name,
            t_departments.dept_head,
            t_job_levels.`name` as job_name,
            t_job_levels.min_salary,
            t_employees.year_hired
            FROM
            t_employees
            INNER JOIN t_departments ON t_employees.dept_id = t_departments.dept_id
            INNER JOIN t_job_levels ON t_employees.job_level_id = t_job_levels.job_level_id
            ORDER BY
            t_employees.`name` ASC
            ";

    // buat query
    $result = $conn->query($sql);

    // eksekusi query
    $data= mysqli_fetch_all($result,MYSQLI_ASSOC);
    mysqli_free_result($result);
    return $data;
}

//  echo "<pre>";
//  $d = f_dept();
//  print_r ($d);

//  $j = f_job_level();
//  print_r ($j);

//  $e = f_get_employee(2);
//  print_r ($e);

//coba donks eksekusi fungsi f_all_employee
 //$umar = f_all_employee();
// echo "<pre>";
 //print_r($umar);
// echo "</pre>";
// foreach($umar as $m){
//   echo $m['emp_name'] . "<br>";
// }
 
?>