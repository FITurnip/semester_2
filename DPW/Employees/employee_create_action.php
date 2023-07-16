<?php
//create connection
$conn = mysqli_connect("localhost","root","","db_ujicoba");

//if cancel
if (isset($_POST['CancelSubmit'])) {
    //do nothing

//if not cancel
} elseif (isset($_POST['CreateSubmit'])) {

    //get var form user input
    $emp_name= $_POST['emp_name'];
    $dept_id = $_POST['dept_id'];
    $job_level_id = $_POST['job_level_id'];
    $year_hired = $_POST['year_hired'];

    //check or validate
    if (!empty($emp_name) && !empty($year_hired)) {

        //create sql command
        $sql = "insert into t_employees (name,dept_id,job_level_id, year_hired) values
        ('$emp_name','$dept_id','$job_level_id', '$year_hired')";
        
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