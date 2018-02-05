
<?php
print "<!doctype html>";
print "<html lang='en'>";
print "<body>";
if ($_POST['action'] == 'submit') {
     print "<h1>Submit</h1>";
 }
 elseif ($_POST['action'] == 'cancel') {
     print "<h1>Cancel</h1>";
 }

print "</body>";
print "</html>";
?>
