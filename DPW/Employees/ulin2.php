<?php

    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_employees";

    //buat query
    $result = mysqli_query($conn,$sql);

    //eksekusi query
    $data= mysqli_fetch_array($result);
    //echo $data['name'];

    //tempat array
    $wadah[] ="";

    while ($data){
         $wadah[] =$data;
         $data= mysqli_fetch_array($result);        
    }

    //cetak dong
    print_r($wadah);
?>

