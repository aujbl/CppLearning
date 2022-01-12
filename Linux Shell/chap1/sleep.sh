#!/bin/bash
# sleep.sh
echo count:
# 存储光标位置
tput sc

# loop 40s
for count in `seq 0 10`
do 
	# 恢复光标位置
	tput rc
	# 清除光标到行尾的内容
	tput ed
	echo -n $count
	sleep 1
done

