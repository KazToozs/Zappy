<?php
	$arg = $_GET['arg'];
	$output = shell_exec("/root/Zappy/zappy_ia " . $arg . " > /dev/null 2>/dev/null & echo $!");
	echo $output;
?>