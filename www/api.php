<?php
$cmd = preg_replace( "/[^LRFBS]/", "", substr($_GET['cmd'], 0, 2));

exec('echo "'.$cmd.'" > /dev/ttyUSB0 >&1', $output);

print_r($output);
