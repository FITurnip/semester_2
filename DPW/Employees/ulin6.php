<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <select name="kota" id="kota">
        <option value="JKt">JKt</option>
        <option value="Bdg">Bdg</option>
        <option value="Sby">Sby</option>
        <option value="Jokowi">Jokowfa-inverse</option>
    </select>

    <select name="dept" id="">
        <?php
          include "data_ref.php";
          $tampung = f_dept();
          foreach($tampung as $a){
            echo "<option value=$a[dept_id]>" . $a['dept_name']. " </option>";
          }
        ?>
    </select>
</body>
</html>