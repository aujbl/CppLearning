#!/bin/bash
# debug.sh
for i in {1 2 3 4 5}
do 
	set -x
	echo $i
	set +x
done
echo "Script executed"
