// 这段代码是关于Zone Memory Allocation（内存分配）的实现，可能受到了NeXT ObjectiveC的启发。
// 这段代码实现了一套内存分配和释放的机制，包含了一些用于标记和控制内存的宏定义和函数。注释提供了对代码整体结构和目的的概述。
// Emacs风格的模式选择   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// 版权所有 (C) 1993-1996 由id Software，Inc.提供。
//
// 本源代码仅在DOOM源代码许可协议规定的条件下可用于分发和/或修改，
// 该协议由id Software发布。保留所有权利。
//
// 描述：
//      区域内存分配，可能受到了NeXT ObjectiveC的启发。
//	备注：根据John Carmack的说法，这可能是唯一对Quake有用的东西。
//
//---------------------------------------------------------------------



#ifndef __Z_ZONE__
#define __Z_ZONE__

#include <stdio.h>

//
// ZONE MEMORY
// PU - 清除标签。
// 标签<100的内容直到释放时都不会被覆盖。
#define PU_STATIC		1	// 整个执行时间都是静态的
#define PU_SOUND		2	// 在播放时是静态的
#define PU_MUSIC		3	// 在播放时是静态的
#define PU_DAVE		4	// Dave想要的任何其他静态的
#define PU_LEVEL		50	// 直到退出关卡都是静态的
#define PU_LEVSPEC		51      // 关卡中的特殊处理器
// 标签>=100的内容在需要时可以被清除。
#define PU_PURGELEVEL	100
#define PU_CACHE		101


void	Z_Init (void);
void*	Z_Malloc (int size, int tag, void *ptr);
void    Z_Free (void *ptr);
void    Z_FreeTags (int lowtag, int hightag);
void    Z_DumpHeap (int lowtag, int hightag);
void    Z_FileDumpHeap (FILE *f);
void    Z_CheckHeap (void);
void    Z_ChangeTag2 (void *ptr, int tag);
int     Z_FreeMemory (void);


typedef struct memblock_s
{
    int			size;	// 包括头部和可能的微小片段
    void**		user;	// 如果是空闲块，则为NULL
    int			tag;	// 清除级别
    int			id;	// 应为ZONEID
    struct memblock_s*	next;
    struct memblock_s*	prev;
} memblock_t;

//
// 这用于在实际调用相关函数之前，从CPP中获取本地的FILE:LINE信息。
//
#define Z_ChangeTag(p,t) \
{ \
      if (( (memblock_t *)( (byte *)(p) - sizeof(memblock_t)))->id!=0x1d4a11) \
	  I_Error("Z_CT at "__FILE__":%i",__LINE__); \
	  Z_ChangeTag2(p,t); \
};



#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
