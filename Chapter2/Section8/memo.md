# Chapter 2
## Section 8
### Thread の確認方法について
```sh
kei2003730@JikuPC ~/A/i/Chapter2 (main)> ./Section4/firstThread4 10000
I'm main: 0
I'm threadFunc 0
I'm main: 1
I'm threadFunc 1
```

```sh
kei2003730@JikuPC ~/A/i/Chapter2 (main) [1]> ps -C firstThread4
    PID TTY          TIME CMD
 680713 pts/7    00:00:00 firstThread4
```

```sh
kei2003730@JikuPC ~/A/i/Chapter2 (main)> ps -C firstThread4 -T
    PID    SPID TTY          TIME CMD
 680713  680713 pts/7    00:00:00 firstThread4
 680713  680714 pts/7    00:00:00 firstThread4
```


```sh
kei2003730@JikuPC ~/A/i/Chapter2 (main)> top -p 680713
top - 17:19:38 up 1 day,  6:32,  1 user,  load average: 0.11, 0.13, 0.13
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.4 us,  0.4 sy,  0.0 ni, 99.0 id,  0.0 wa,  0.0 hi,  0.2 si,  0.
MiB Mem :   7853.2 total,   3065.8 free,   4172.4 used,    822.2 buff/cache
MiB Swap:   2048.0 total,   2042.7 free,      5.3 used.   3680.8 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+
 680713 kei2003+  20   0   10876   1664   1664 S   0.0   0.0   0:00.01
```

```sh
kei2003730@JikuPC ~/A/i/Chapter2 (main)> top -p 680713 -H
top - 17:19:54 up 1 day,  6:32,  1 user,  load average: 0.16, 0.14, 0.13
Threads:   2 total,   0 running,   2 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.4 us,  0.6 sy,  0.0 ni, 98.8 id,  0.1 wa,  0.0 hi,  0.1 si,  0.
MiB Mem :   7853.2 total,   3063.0 free,   4175.2 used,    822.2 buff/cache
MiB Swap:   2048.0 total,   2042.7 free,      5.3 used.   3678.0 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+
 680714 kei2003+  20   0   10876   1664   1664 S   0.3   0.0   0:00.01
 680713 kei2003+  20   0   10876   1664   1664 S   0.0   0.0   0:00.00
```

Linux内部では、Threadはプロセスの一部として扱われる。
逆に、Processは、Threadの集合体である。
PIDはProcess IDで、SPIDはThread IDである。
