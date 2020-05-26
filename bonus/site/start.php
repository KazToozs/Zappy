<?php

if (file_exists("/tmp/zappy_pid_serv") === false)
{
	$output = "LOL";
	$arg = $_GET['arg'];
	echo $arg."\n";
	$output = shell_exec("/root/Zappy/serverLinux " . $arg . " > /tmp/log_Zappy 2>/tmp/log_Error_Zappy & echo $!");
	$file_r = fopen("/tmp/zappy_pid_serv", 'w');
	fwrite($file_r, $output);
	fclose($file_r);
	echo $output;
}
else
{
	fclose($file);
	echo "Already started";
}
?>