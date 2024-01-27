//#define DOOM2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <conio.h>
#include <dos.h>

#include "doomnet.h"      // DOOM网络通信相关头文件
//#include "ipxstr.h"
#include "ipx_frch.h"     // FRENCH VERSION（法语版本）

doomcom_t doomcom;         // DOOM通信结构体
int vectorishooked;         // 中断向量是否挂接的标志
void interrupt (*olddoomvect) (void);  // 保存原始中断向量的函数指针

/*
=============
=
= LaunchDOOM
=
这个函数用于启动 DOOM 游戏，并且在调用之前需要填写 doomcom 结构体的一些字段：

    short     numnodes;      // 控制台始终为节点 0
    short     ticdup;        // 1 = 不复制，2-5 = 慢网的复制
    short     extratics;     // 1 = 在每个数据包中发送备份 tic

    short     consoleplayer; // 0-3 = 玩家编号
    short     numplayers;    // 1-4
    short     angleoffset;   // 1 = 左，0 = 中，-1 = 右
    short     drone;         // 1 = 无人机
=============
*/
void LaunchDOOM(void)
{
    char *newargs[99];        // 存储启动 DOOM 时的命令行参数
    char adrstring[10];       // 存储转换后的地址字符串
    long flatadr;             // 存储线性地址

    // 准备启动 DOOM
    doomcom.id = DOOMCOM_ID;

    // 挂接中断向量
    olddoomvect = getvect(doomcom.intnum);
    setvect(doomcom.intnum, (void interrupt (*)(void))MK_FP(_CS, (int)NetISR));
    vectorishooked = 1;

    // 构建 DOOM 的参数列表，添加一个 -net &doomcom
    memcpy(newargs, _argv, (_argc + 1) * 2);
    newargs[_argc] = "-net";
    flatadr = (long)_DS * 16 + (unsigned)&doomcom;
    sprintf(adrstring, "%lu", flatadr);
    newargs[_argc + 1] = adrstring;
    newargs[_argc + 2] = NULL;

    // 根据是否存在 "doom2.exe" 来选择启动 "doom2" 或 "doom"
    if (!access("doom2.exe", 0))
        spawnv(P_WAIT, "doom2", newargs);
    else
        spawnv(P_WAIT, "doom", newargs);

    #ifdef DOOM2
    printf(STR_RETURNED"\n");
    #else
    printf("Returned from DOOM\n");
    #endif
}
