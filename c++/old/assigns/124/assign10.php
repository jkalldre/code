<?php

print "<!doctype html>";
print "<html lang='en'>";
$fname = $_GET["firstname"];
$lname = $_GET["lastname"];
$address = $_GET["address"];
$phone = $_GET["phone"];
$ccType = $_GET["ccType"];
$ccNumber = $_GET["ccNumber"];
$ccExpiration = $_GET["ccExpiration"];
$total = intval($_GET["bpack"]) + intval($_GET["spack"]) + intval($_GET["apack"]) + intval($_GET["lpack"]);
$pieces = explode("-", $ccExpiration);
$months = array("01" => "January", "02" => "February", "03" => "March",
"04" => "April", "05" => "May", "06" => "June", "07" => "July", "08" => "August",
"09" => "September", "10" => "October", "11" => "November", "12" => "December");
$month = $months[$pieces[0]];

print "<head>";
print "<title>Purchase Review</title>";
print "<link rel='stylesheet' type='text/css' href='assign10.css'/>";
print "<script src='assign10.js' type='text/javascript'></script>";
print "</head>";
print "<body>";
print "<form action='assign10_a.php'>";
print "<table class='review'>";
print "<tr><th><h2>Purchase Review</h2></th></tr>";
print "<tr><td>First: $fname</td></tr>";
print "<tr><td>Last: $lname</td></tr>";
print "<tr><td>Address: $address</td></tr>";
print "<tr><td>Phone: $phone</td></tr>";
print "<tr><td>$ccType: $ccNumber</td></tr>";
print "<tr><td>Expires: $month, $pieces[1]</td></tr>";
print "<tr><td>Total: $$total</td></tr>";
print "<tr><td><button type='submit' name='action' value='cancel'>Cancel</button>";
print "<button type='submit' name='action' value='submit'>Submit</button></td></tr>";
print "</table>";
print "</form>";
print "</body>";
print "</html>";

?>
