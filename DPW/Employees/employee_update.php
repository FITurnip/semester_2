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

    <h1>Update Employee</h1>

    <?php 
        //kaitkan dengan data referensi
        include_once "data_ref.php";

        //ambil list dept
        $list_dept = f_dept();

        //ambil list job_level
        $list_job_level = f_job_level();
        
        //ambil data sebelumnya
        $emp_id = $_GET['arg'];
        $old_employee =  f_get_employee($emp_id);

        // print_r ($old_employee);
        // exit();        
    ?>

    <div class="container">
    <form action="employee_update_action.php" method="post">
    <div class="row">
        <div class="col-25">
        <label for="emp_name">Name</label>
        </div>
        <div class="col-75">
        <input type="hidden" id="emp_id" name="emp_id" value="<?php echo $emp_id ?>">
        <input type="text" id="emp_name" name="emp_name" placeholder="Employee name.." 
         value="<?=$old_employee['name'] ?>">
        </div>
    </div>
    <div class="row">
        <div class="col-25">
        <label for="dept">Department</label>
        </div>
        <div class="col-75">
            <select id="dept" name="dept_id">
            <?php 
                //ulangi untuk semua elemen dept
                foreach ($list_dept as $d){          
                    if (($d['dept_id'] == $old_employee['dept_id'])) {
                        echo "<option value=$d[dept_id] selected>" . $d['dept_name'] . "</option>";
                    } else {
                        echo "<option value=$d[dept_id]>" . $d['dept_name'] . "</option>";
                    }
                } 
           ?>
        </select>
        </div>
    </div>
    <div class="row">
        <div class="col-25">
        <label for="job_level">Job Level</label>
        </div>
        <div class="col-75">
            <select id="job_level" name="job_level_id">
                <?php 
                //ulangi untuk semua elemen job level
                foreach ($list_job_level as $j){
                    if (($j['job_level_id'] == $old_employee['job_level_id'])) {
                        echo "<option value=$j[job_level_id] selected>" . $j['name'] . "</option>";
                    } else {
                        echo "<option value=$j[job_level_id]>" . $j['name'] . "</option>";
                    }
                }            
                ?>
            </select>
        </div>
    </div>
    
    <div class="row">
        <div class="col-25">
        <label for="year_hired">Year Hired</label>
        </div>
        <div class="col-75">
        <input type="number" id="year_hired" name="year_hired" placeholder="Enter year hired.." value="<?php echo $old_employee['year_hired'] ?>">
        </div>
    </div>
    <br>
    <div class="row">
        <div class="col-25">
            &nbsp;
        </div>
        <div class="col-75">
            <input type="submit" value="Update" name="UpdateSubmit"> &nbsp;
            <input type="submit" value="Cancel" name="CancelSubmit">
        </div>
    </div>

</body>
</html>