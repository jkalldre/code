<?php

header("Content-type: text/xml\n\n");
print "<?xml version='1.0' encoding='UTF-8'?>";
print "<?xml-stylesheet type='text/xsl' href='assign09.xsl'?>";

$fname      = array("Jake", "Trevor", "Colleen", "Tara", "Ben");
$middle     = array("Kenneth", "Heinrich", "Nicole", "Justine", "Lee");
$lname      = array("Alldredge", "Nestman", "Alldredge", "Roberts", "Stanza");
$city       = array("Vidor", "Salt Lake City", "Vidor", "Modesto", "Denver");
$state      = array("Texas", "Utah", "Texas", "California", "Colorado");
$college    = array("BYUI", "BYUI", "N/A", "BYUI", "MIT");
$department = array("Physical Sciences", "Physical Sciences", "N/A", "Health", "Physical Sciences");
$major      = array("Computer Science", "CIT", "N/A", "Health Science", "Electrical Engineering");

print "<studentList>";

for ($i = 0; $i < sizeof($fname); $i++)
{
  print "<student>\n";
  print "<name>";
  print "<first>$fname[$i]</first>";
  print "<middle>$middle[$i]</middle>";
  print "<last>$lname[$i]</last>";
  print "</name>\n";
  print "<location>";
  print "<city>$city[$i]</city>";
  print "<state>$state[$i]</state>";
  print "</location>\n";
  print "<college name='$college[$i]'>";
  print "<department name='$department[$i]'>";
  print "<major>$major[$i]</major>";
  print "</department>";
  print "</college>\n";
  print "</student>\n";
}
print "</studentList>";

?>
