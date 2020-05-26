<?php

if (file_exists("/tmp/zappy_pid_serv") === true)
{
	$file_r = fopen("/tmp/zappy_pid_serv", 'r');
	$pid_file = fread($file_r, filesize("/tmp/zappy_pid_serv") - 1);
	echo "/usr/bin/sudo /bin/kill -s SIGTERM $pid_file";
	$output = shell_exec("/usr/bin/sudo /bin/kill -s SIGTERM $pid_file");
	fclose($file_r);
	shell_exec("/bin/rm /tmp/zappy_pid_serv");
	echo "Server Killed";
}
else
{
	echo "Error: Server don't start";
}
?>