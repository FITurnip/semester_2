<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employees</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <ul class="menu">
        <li class="menu"><a href="index.html">Home</a></li>
        <li class="menu"><a class="active" href="employee.php">Employee</a></li>
        <li class="menu"><a href="search.php">Search</a></li>
        <li style="float:right"><a href="#about">About</a></li>
    </ul>

    <h1>Employee List</h1>

    <table id="employees">
        <tr>
            <th>Index</th>
            <th>Name</th>
            <th>Dept</th>
            <th>Job</th>
            <th>Dept Head</th>
            <th>Min Salary</th>
            <th>Year Hired</th>
            <th>Action</th>
        </tr>

    <?php
        //kaitkan dengan data referensi
        include_once "data_ref.php";

        //ambil list pegawai
        $krim_employee = f_all_employee();

        //buat pencacah
        $cacah=1;

        //buat link ADD
        echo "<a href='employee_create.php'><button class='button'>Create</button> </a><br><br>";

        //buat looping untuk menampilkan data sd selesai
        foreach($krim_employee as $krim){    
    ?>
    
    <!--tampilkan record-->
    <tr>
        <td><?= $cacah ?> </td> 
        <td><?= $krim['emp_name'] ?> </td> 
        <td><?= $krim['dept_name'] ?> </td> 
        <td><?= $krim['job_name'] ?> </td> 
        <td><?= $krim['dept_head'] ?> </td> 
        <td align="right"><?= $krim['min_salary'] ?> </td> 
        <td align="center"><?= $krim['year_hired'] ?> </td> 
        <td> <a href="employee_update.php?arg= <?= $krim['emp_id'] ?>">Update</a>&nbsp;
             <a href="employee_delete.php?arg= <?= $krim['emp_id'] ?>">Delete</a> </td>
    </tr>

    <?php
         //next record
         $cacah++;
    }
    ?>

   </table>
</body>
</html>
