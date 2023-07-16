<?php
    $servername = "localhost";
    $username = "root";
    $password = "";

    // Create connection
    $conn = mysqli_connect($servername, $username, $password);

    // Check connection
    if (! $conn) {
        die("Connection failed: " . mysql_error());
    }

    $db_selected = mysqli_select_db($conn, 'db_shoes');
?>