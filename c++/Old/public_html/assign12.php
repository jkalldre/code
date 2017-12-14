<?php

  $myfile = fopen("data/newfile.txt", "a+"); //or die("Unable to open file!");
  chmod("data/newfile.txt", 0777);

  $type   = $_GET["type"];
  $fname  = $_GET["fname"];
  $lname  = $_GET["lname"];
  $Inum   = $_GET["Inum"];
  $skill  = $_GET["skill"];
  $instr  = $_GET["instr"];
  $loc    = $_GET["loc"];
  $room   = $_GET["room"];
  $time   = $_GET["time"];
  if ($type == "Duet")
  {
     $fname2 = $_GET["fname2"];
     $lname2 = $_GET["lname2"];
     $Inum2  = $_GET["Inum2"];
  }
if ($fname != "")
{
  $row = "<tr><td>" . $type . "</td><td>" . $fname . " " . $lname;
  if ($type == "Duet")
  {
    $row .= " / " . $fname2 . " " . $lname2;
  }

  $row .= "</td><td>" . $Inum;
  if ($type == "Duet")
  {
    $row .= " / " . $Inum2;
  }

  $row .= "</td><td>" . $skill . "</td><td>" . $instr . "</td><td>" . $loc .
  "</td><td>" . $room . "</td><td>" . $time . "</td></tr>\n";

  fwrite($myfile, $row);
  fclose($myfile);
}
  //$file_content = file_get_contents("data/newfile.txt");
  //readfile("data/newfile.txt");

?>

/*
$myfile = fopen("data/newfile.txt", "a+");
$txt = "John Doe\n";
fwrite($myfile, $txt);
$txt = "Jane Doe\n";
fwrite($myfile, $txt);

echo file_get_contents("data/newfile.txt");
fclose($myfile);

?>
