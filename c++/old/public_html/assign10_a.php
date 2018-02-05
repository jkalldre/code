
<?php
print "<!doctype html>";
print "<html lang='en'>";
print "<head>";
print "<link rel='stylesheet' type='text/css' href='assign10.css'/>";
print "</head>";
print "<body>";

$action = $_GET['action'];
if ($action == 'submit') {
     print "<h1>Purchase Confirmed!</h1>";
     print "<p><span class='i'>Please return for all your future purchases!</span></p>";
 }
 elseif ($action == 'cancel') {
     print "<h1 style='background-color:blue;'>Purchase Canceled :(</h1>";
     print "<p><span class='i'>Please return in the future!</span></p>";
 }

print "</body>";
print "</html>";
?>
