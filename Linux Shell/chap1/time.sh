#!/bin/bash
start=$(date +%s)
command;
#stat;
end=$(date +%s)
diff=$((end - start))
echo Time consuming $diff seconds.
