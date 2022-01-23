# chap 1

0. 脚本执行方式：```1): bash xxx.sh;       2): ./xxx.sh```

1. ```#!```定义解释该脚本所用的解释器；```#```注释

2. ```.bashrc```交互式shell初始化脚本文件；```.bash_profile```登录shell初始化脚本文件；```.bash_history```历史记录

3. 打印彩色文本(30+)```echo -e "\e[1;31m This is red text \e[0m```；设置彩色背景(40+)```\e[1;42m```

4. echo使用单引号时，变量不会被拓展```echo '$var'    ->      $var``` 

5. export命令声明将由子进程继承的变量

6. 环境变量

    1. ```PS1```修改Bash提示字符串

    2. ```PS4```设置显示每行的行号

    3. ```_DEBUG```

    4. ```$?```保存返回值（退出状态）

    5. ```$$```当前脚本的进程ID

7. 数学运算：```let;    (());    [];     expr;   bc```；```bc```是用于数学运算的工具

8. 使用```>```重定向到文件，使用```>>```追加到文件,```2>```文件描述符 + 重定向

9. ```tee```接收来自```stdin```的数据，将```stdout```写入文件，同时将一份副本作为后续命令的```stdin```

10. ```/dec/null```（黑洞）：丢弃接收到的任何数据

11. ```exec```创建新的文件描述符

12. 数组和关联数组，关联数组（字典）要先用```declare```声明

13. 别名```alias; unalias```;```    \cmd```忽略别名

14. 采集终端信息：```tput;  stty```

15. ```date```日期及延时

16. ```seq 0 40```生成一系列数字

17. 调试脚本
    
    1. ```bash -x xxx.sh```启用跟踪调试功能

    2. ```set -x; set +x; set -v; set +v```

    3. ```#!/bin/bash -xv```

    4. ```_DEBUG```可以启用或禁止调试及生成特定形式的信息

18. 函数和参数

    1. 定义

        ```sh
        function fname()
        {
            statements;
        }
        fname()
        {
            statements;
        }
        fname () {statements;}
        ```

    2. 访问函数
        
        ```sh
        fname arg1 arg2;
        # $0:脚本名称
        # $n:第n个参数
        # $@:以列表形式打印所有参数
        # $*:打印所有参数，但所有参数被当作单个字符串
        # shift可以将参数一次向左移动一个位置
        ```

    3. 函数可以递归，可以导出

19. ```(ls | cat -n)```()定义子shell，子shell执行不影响当前shell

20. ```read [-nsptd]```读取字符

21. 内部字符分隔符：默认```IFS=“ ” ```，可以更改```data="name, gender";     for item in $data"```

22. 比较与测试

    1. ```if```语句

        ```sh
        if cond;
        then    
            cmds;
        else
            cmds;
        fi
        ```

    2. 比较条件```[ condition ]```（condition前后要有空格）

        ```[ condition ] && action;```，```&&```逻辑与 **（运算符）**，条件为真，执行action

        ```[ condition ] || action;```， ```||```逻辑或 **（运算符）**,条件为假，执行action

        ```[ $var1 -ne 0 -a $var2 -gt 2 ]```, ```-a```逻辑与 **（操作符）**

        ```[ $var1 -ne 0 -o $var2 -gt 2 ]```, ```-o```逻辑或 **（操作符）**

    3. 文件系统测试```[ -arg $var ]```

        | -f | -x | -d | -e | -c | -b | -w | -r | -L |
        | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
        |文件|可执行|目录|文件存在|字符设备文件|块设备文件|可写|可读|符号链接|

    4. 可以用```test```来测试条件，可以避免括号，但test是外部程序，需要衍生出对应的进程，```[]```是内部函数，效率更高

        ```if [ $var -eq 0 ]; then echo "True"; fi```

        ```if test $var -eq 0; then echo "True"; fi```

23. 可以使用配置文件定制bash，登录时 / 启动交互式shell / 调用shell处理脚本调用不同的配置文件

# chap 2

1. ```cat [-s -T -n]```

2. ```script;   scriptreplay;``` 

3.  ```find```
    ```sh
    find [-print -print0]           # 设置不同的分隔符
         [-path]                    # 限制匹配路径
         [-iname]                   # 不区分大小写
         [-regex]                   # 基于正则表达式限制文件路径
         [!]                        # 否定参数
         [-L]                       # 遍历时进入符号链接
         [-mindepth -maxdepth]      # 限制深度，先限制深度再匹配效率更高
         [-type]                    # 根据文件类型搜索
         [-atime -mtime -ctime]     # 根据文件时间戳搜索（天）
         [-amin -mmin -cmin]        # （分钟）
         [-size]                    # 根据文件大小搜索
         [-perm 644]                # 根据文件权限搜索
         [-user jbl]                # 根据user搜索
         [-delete -exec]            # 执行相应操作
         [-name '.git' -prune]      # 跳过指定目录
    ```

4. ```xargs```重新格式化stdin接收到的数据，再将其作为参数提供给指定命令
    ```sh
     [-n]       # 按指定数量重新划分
     [-d]       # 改变分隔符
     [-I]       # 指定替换字符串
     [-0]       # 用NULL作分隔符
     ```
5. ```tr```(translate)
    ```sh
    tr  [option] set1 set2
        [-d]                    # 指定删除的字符集合
        [-c]                    # 使用补集
        [-s]                    # 压缩字符
    tr '[:lower:]' '[:upper:]'  # 使用字符集合
    ```

6. 检验和
    ```sh
    # 单向散列算法
     md5sum; sha1sum;       # [-c]核实（检验文件）
     md5deep; sha1deep;     # 检验目录
     ```

7. 加密算法，可以无损地重构数据```crypt; gpg; base64```

8. ```sort + uniq```

9. ```mktemp```为临时文件或目录命名

10. ```split```分割文件；```csplit```基于上下文分割文件（如分割日志）

11. ```%; %%; （从右向左匹配， 非贪婪/贪婪）  #; ##; （从左向右匹配） ```
    
12. ```rename```

13. ```aspell```检查某个单词是否在词典中

14. ```look```显示出以特定字符串起始的行

15. ```&```令shell将命令置于后台并继续执行

16. ```$!```获得进程PID 

# chap 3

1. 可以使用```dd```命令生成任意大小的文件

2. ```comm```可用于比较两个已排序的文件

3. 可以根据文件大小和检验和查找重复文件

4. 粘滞位：只有创建该目录的用户才能删除目录中的文件（可用于/tmp）

5. 权限：```+s(setuid)```，允许可执行文件以其拥有者的权限来执行；```+t```设置粘滞位

6. 设置不可修改文件（需要文件系统支持）：```chattr +i file```

7. ```touch```创建空白文件

8. 文件也可以作为文件系统挂载

9. ```diff```可以生成两个文件之间的差异对比；```patch```将变更应用于其中一个文件

10. ```tail -f```可用于监控文件更新

11. 快速定位目录```pushd; dirs; popd; cd -;```

12.  ```wc```统计文件信息

# chap4

1. 正则表达式

    1. 位置标记：```^(行首)     $(行尾)```

    2. 标识符

        ```sh
        .       # 任意一个字符；
        []      # 匹配括号内的任意一个字符
        [^]     # 匹配不在括号内的任意一个字符
        ```

    3. 数量修饰符

        ```sh
        ?           # 1次或0次
        +           # 1次或多次
        *           # 0次或多次
        {n}         # n次
        {n,}        # 至少n次
        {n, m}      # n-m次
        ```

    4. 其他```(); |; \;```

2. ```grep [-E -e -f -o -v -c -n -b -l -L -R -i -q -B -A]```

3. 按列切分文件
    
    ```sh
    cut -f              # 按字段划分列，提取字段
        -b              # 按字节划分列
        -c              # 按字符划分列
        -d              # 设置分隔符
        --complement    # 补集  
    ```
4. ```sed(stream editor)```流编辑器

    ```sh
    sed 's/t1/t2/'          # 用t2替换t1
        's:t1:t2:'          # s后的字符是分隔符(:)
        's/^$/d'            # ^$代表空行，/d不替换直接删除
        -i                  # 原地替换，修改文件内容
        -i.bak              # 替换并保留备份
        &                   # 可以用来指代匹配到的字符串
        \#                  # 子串匹配标记
    ```

5. ```awk```awk命令是一个解释器，能够解释并执行程序

    ```sh
    awk 'BEGIN{ statements } pattern { statements } END { statements }' 
        "-"         # 双引号被当作拼接操作符
        NR          # 行号
        NF          # 字段数量
        $0          # 当前记录内容
        $1          # 第一个字段的内容
        $2          # 第二个字段的内容
        -v          # 可以将外部值传递给awk
    ```

6. ```paste```按列合并

7. ```tac```逆序打印

# chap5

1. ```wget [-t --limit-rate --quota -c --mirror -l -r -N -k --convert-links]```

2. ```Lynx```一款基于命令行的Web浏览器，能够以纯文本形式下载Web页面

3. ```culr```可以使用HTTP/HTTPS/FTP协议在客户端与服务器之间传递数据

# chap6

1. ```git add```将工作代码中的变更添加到暂存区

2. ```git commit [-a]在提交前加入新的代码；[-m]指定一条信息，不进入编辑器```将变更提交至仓库

3. ```git checkout```更改及创建新分支

4. ```git branch```查看分支

5. ```git merge```将变更合并入新分支

6. ```git format-patch```生成当前分支的补丁文件

7. ```git apply```将补丁应用于工作代码

8. ```git push```将分支推送到主线

9. ```git fetch; git pull;```将数据从远程下载到本地仓库，合并变更到工作代码

10. ```git status```输出项目的当前状态

11. ```git log```查看历史记录

12. ```git blame```返回包含提交的SHA-作者-提交日期以及提交信息的第一行

13. ```git bisect```找出引发问题的提交

14. ```git tag```用于添加/删除和列出标签

15. ```fossil```另一种分布式版本控制系统

# chap7

1.  ```sh
    tar -c              # 创建新的归档文件
        -t              # 列出归档文件中所包含的文件
        -v -vv          # （非常）冗长模式输出
        -r              # 将新文件追加到末尾
        -f              # 指定归档文件名
        -x              # 将归档文件的内容提取到当前目录
                        # 将文件名作为参数，可以提取指定文件
        -A              # 合并多个tar文件
        -u              # 只添加比归档文件中的同名文件更新的文件
        -d              # 归档文件与系统文件作比较
        --delete        # 从归档文件中删除文件
        -a [-j(bunzip2) -z(gzip) -lzma(lzma)]
                        # 自动选择压缩算法；tar只归档不压缩  
        --exclude       # 排除文件
        --exclude-vcs   # 排除版本控制相关文件和目录
        -X              # 使用排除文件列表
    ```

2. ```cpio```类似于```tar```

3. ```gzip; gunzip```压缩与解压缩

4. ```zcat```可以直接读取gzip文件

5. ```zip```方便跨文件系统使用

6. ```pbzip2```利用多线程同时压缩多个数据块

7. ```squashfs```一种具有超高压缩率的只读型文件系统

8. ```rsync```同步不同位置上的文件和目录

9. 差异化归档：只保存上次完整备份后发生变化的文件

10. ```fsarchiver```可以将整个磁盘分区中的内容保存成一个压缩归档文件；能够保留文件的拓展属性，可用于将当前文件系统恢复到磁盘中

# chap8

1. ```ifconfig```

2. ```ping```可以ping环回地址确定TTL

3. ```traceroute```跟踪IP路由，```mtr```可能显示实时刷新数据

4. ```fping```可以为多个IP地址生成ICMP分组

5. ```SSH(Secure Shell)```

6. 通过网络传输文件```ftp; lftp; sftp; rsync; scp;```

7. 无线网络```iwconfig; iwlist;```

8. SSH采用给对称加密技术，```ssh-keygen```创建密钥；```ssh-copy-id```将私钥添加到远程服务器

9. 端口转发：```ssh -L 8000:www.kernel.org:80 user@localhost```反向端口转发```-R```

10. ```sshfs -o allow_other user@remotehost:/home/path /mnt/mountpoint```将远程主机上的文件系统挂载到本地挂载点上

11. ```lsof(list open file); netstat;```分析网络流量和端口

12. ```netcat; nc;```可以创建用于在TCP/IP网络传输数据的套接字

13. 网桥：使用MAC地址来传递分组，可以用来连接不可路由的私有网络

14. ```iptables```防火墙和NAT(Network Address Translation)

# chap9

1. ```du(disk usage); df(disk free);```

    ```sh
    du  -a          # 显示各个文件的情况
        -h          # 友好可读格式
        -c          # 文件或目录占用的总空间
        -s          # 只输出总计数据
        -b          # 以字节为单位
        -k          # KB
        -m          # MB
        -B          # 以块为单位
        --exclude   # 排除部分文件
        --max-depth # 遍历层数
    ```

2. ```time```命令执行时间

    ```sh
    ~: time ls

    real	0m0.002s        # 命令从开始执行到结束的时间
    user	0m0.002s        # 进程花费在用户模式中的CPU时间
    sys	    0m0.000s        # 进程花费在内核中的CPU时间
    ```

3. 登录用户/启动日志相关信息

    1. ```who```获取当前登录用户的信息

    2. ```w```有关登录用户更详细的信息

    3. ```users```只列出当前的登录用户列表

    4. ```uptime```查看系统的加电时间

    5. ```last```获取文件/var/log/wtmp中的用户列表，可以指定用户

    6. ```lastb```获取登录失败的用户登录会话信息

4. ```watch```按照指定的时间间隔来执行命令并显示输出

5. ```inotifywait -m -r -e create,move,delete $path -q```监视文件或目录

6. ```logger```可以通过syslogd进行日志记录，记录保存在/var/log/syslog(ubuntu 20)

7. ```logrotate```可以限制日志文件的大小

8. 登录细节记录在/var/log/auth.log或/var/log/secure中

9. 有关用户会话的数据保存在？/var/log/wtmp中

10. ```powertop```查看电源使用情况

11. ```iotop```监视磁盘活动```iotop -p 'pidof cp'```监视指定进程

12. 检查磁盘及文件系统错误
        
    ```sh
    fsck    -A      # 检查/etc/fstab中配置的所有文件系统
                    # /etc/fstab定义了磁盘分区与挂载点之间的映射关系
            -a      # 尝试自动修复
            -N      # 模拟fsck要执行的操作
    ```

13. SMART(Self-Monitoring, Analysis, and Reporting Technology)，可以用```smartctl```来检查磁盘健康情况

14. 获取磁盘统计数据

    ```sh
    hdparm  -I      # 给出设备的基本信息
            -t      # 测试缓冲性能
            -T      # 测试缓存读性能
    ```

# chap10

1. 收集进程信息

    ```sh
    ps  -f                  # 显示多列信息
        -e -ef -ax -axf     # 都能生成包含所有进程的报告
        -o                  # 指定显示哪些数据
        e                   # 显示进程信息
        f                   # 创建进程的树状视图
        --sort              # 输出排序
        -u                  # 指定有效用户列表
        -U                  # 指定真实用户列表
        -t                  # 指定tty列表
        -L                  # 显示出线程有关的信息
        -C                  # 识别出某个命令的PID，还可以用 pgrep cmd
    
    uptime                  # 显示系统平均负载

    top                     # 列出进程列表以及基本的统计信息
    ```

2. ```which```找出某个命令的位置

3. ```whereis```返回命令的路径，打印出其对应的命令手册

4. ```whatis```输出指定命令的一行简短描述

5. ```file```确定文件的类型

6. ```apropos```搜索包含指定关键字的手册业

7. 杀死进程和发送信号
    ```sh
    kill -l       # 列出所有可用的信号```
    
    # 常用信号
    SIGHUP 1        # 挂起检测
    SIGINT 2        # 按下Ctrl+C发送该信号
    SIGKILL 9       # 强行杀死进程
    SIGTERM 15      # 终止进程
    SIGSTP 20       # 按下Ctrl+Z发送该信号

    trap            # 在脚本中用来为信号分配信号处理程序
    ```

8. ```write```向一个用户发送信息；```talk```让两个用户展开对话；```wall```向所有用户发送消息

9. ```proc```文件系统

    1. 一种存在于内存中的伪文件系统
    
    2. 为了可以从用户空间读取Linux内核的内部数据结构

    3. 系统中每一个运行的进程在/proc中都有一个对应的目录，目录名和进程IP相同

10. 收集系统信息

    ```sh
    hostname
    uname
    /proc/cpuinfo
    /proc/meminfo
    /proc/partitions
    lshw
    dmidecode
    ```

11. ```cron```定时任务

    1. ```cron```使用表```crontab```保存需要执行的一系列脚本以及执行时间

    2. 每个表项由6个字段组成```00 5,6,7 * * * cmd```

    3. 以表项创建者身份执行命令，但不执行该用户的```.bashrc```文件，因此环境变量需要在```crontab```中定义

    4. 多个值使用```,```分隔，```*```表示任意时间段

    5. 命令需要使用完整路径

# chap11

1. ```tcpdump```跟踪分组

2. ```ngrep = grep + tcpdump```可以监视网络端口并显示匹配特定模式的分组

3. 使用ip跟踪网络路由

    ```sh
    ip route                # 输出已知的路由
    ip neigh                # 输出IP地址/设备与硬件MAC地址之间的已知关系
    ip route get            # 输出当前主机的下一跳地址
    ```

4. ```strace```可以输出应用程序所用到的系统调用

5. ```ltrace [-S]```跟踪用户空间的动态库调用, -S同时跟踪用户空间和系统空间的函数调用

# chap12

1. ```service --status-all```输出/etc/init.d中定义的全部服务的当前状态

2. ```systemctl```可以启用或禁止服务

3. ```ss [-t] (TCP) [-l] (listen) [-u] UDP```返回套接字统计信息

4. 收集系统I/O使用情况

    ```sh
    dstat   --top-bio           # 执行块I/O最多的进程
            --top-cpu           # 
            --top-io            # 
            --top-latency       # 延迟最高的进程
            --top-mem           # 占用内存最多
    ```

5. 每个进程的统计信息

    ```sh
    pidstat     -d          # 输出I/O统计
                -r          # 输出缺页和内存使用情况
                -u          # 输出CPU使用情况
                -w          # 输出上下文切换情况
    ```

6. ```sysctl```可以修改内核参数

7. /etc目录下有多个文件，控制着系统的配置

8. 可以使用```nice```更改调度器优先级

# chap13

1. Linux容器（lxc）

2. Docker

3. 虚拟机


