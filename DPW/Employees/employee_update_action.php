<?php
//create connection
$conn = mysqli_connect("localhost","root","","db_ujicoba");

//if cancel
if (isset($_POST['CancelSubmit'])) {
    //do nothing

//if not cancel
} elseif (isset($_POST['UpdateSubmit'])) {

    //get var form user input
    $emp_id= $_POST['emp_id'];
    $emp_name= $_POST['emp_name'];
    $dept_id = $_POST['dept_id'];
    $job_level_id = $_POST['job_level_id'];
    $year_hired = $_POST['year_hired'];

     //check or validate
    if (!empty($emp_name) && !empty($year_hired)) {

        //create sql command
        $sql = "update t_employees 
                set name = '$emp_name',
                dept_id = '$dept_id',
                job_level_id = '$job_level_id',
                year_hired = '$year_hired'
                where employee_id = '$emp_id'";
    
        //get result
        $result = mysqli_query($conn,$sql);
        
        //if success
        if ($result) {
          //do nothing

        //if not success
        } else {
          //send error
          echo mysqli_error($conn);
          exit();   
        }
    }
}

//back to employee
header("location:employee.php");

?>