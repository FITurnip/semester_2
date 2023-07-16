<?php

    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_employees";

    //buat query
    $result = mysqli_query($conn,$sql);

    //ambil semua data
    $data= mysqli_fetch_all($result,MYSQLI_ASSOC);

    //cetak dong
    print_r($data);
?>

