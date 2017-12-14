<?php
$doet = $_GET["doet"];
for ($i = 0; $i < $doet; $i++)
{
   $to = $_GET["to"];
   $subject = $_GET["subject"];
   $message = $_GET["message"];

   mail($to, $subject, $message);
}
?>
