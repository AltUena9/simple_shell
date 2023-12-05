#!/bin/bash

pid_max=$(cat/proc/sys/kernel/pid_max)
	echo "The mximum value a process id can be is $pid_max"
