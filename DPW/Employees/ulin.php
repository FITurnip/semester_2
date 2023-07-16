<?php

    $conn = mysqli_connect("localhost","root","","db_ujicoba");
    $sql = "SELECT * from t_employees";

    //buat query
    $result = mysqli_query($conn,$sql);

    //eksekusi query
    $data= mysqli_fetch_array($result);
    //echo $data['name'];

    while ($data){
         echo $data['name'] . "<br>";
         $data= mysqli_fetch_array($result);
         

    }
?>

