// Emacs样式的模式选择   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// $Id:$
//
// 版权所有 (C) 1993-1996，id Software，Inc。
//
// 本源码仅在DOOM源代码许可下可用于分发和/或修改，
// 该许可由id Software发布。保留所有权利。
//
// 该源码被分发，希望它会有用，
// 但是没有任何保证；甚至没有适用于特定目的的暗示的保证。
// 有关更多详细信息，请参阅DOOM源代码许可。
//
// 描述：
//      区域内存分配，可能是受到了NeXT ObjectiveC的启发。
//      注意：根据John Carmack的说法，这可能是Quake中唯一有用的东西。
//
//---------------------------------------------------------------------

#ifndef __Z_ZONE__
#define __Z_ZONE__

#include <stdio.h>

//
// 区域内存
// PU - 清理标签。
// 标签<100在被释放之前不会被覆盖。
#define PU_STATIC       1   // 整个执行时间都是静态的
#define PU_SOUND        2   // 在播放时静态
#define PU_MUSIC        3   // 在播放时静态
#define PU_DAVE         4   // Dave希望是静态的其他任何东西
#define PU_LEVEL        50  // 直到退出关卡时是静态的
#define PU_LEVSPEC      51  // 关卡中的特殊思考者
// 标签>=100可以在需要时清除。
#define PU_PURGELEVEL   100
#define PU_CACHE        101

// 初始化内存分配器
void    Z_Init(void);

// 分配内存
void*   Z_Malloc(int size, int tag, void* ptr);

// 释放内存
void    Z_Free(void* ptr);

// 根据标签释放内存
void    Z_FreeTags(int lowtag, int hightag);

// 打印指定标签的堆信息
void    Z_DumpHeap(int lowtag, int hightag);

// 将堆信息输出到文件
void    Z_FileDumpHeap(FILE* f);

// 检查堆的一致性
void    Z_CheckHeap(void);

// 更改内存块的标签
void    Z_ChangeTag2(void* ptr, int tag);

// 释放所有内存
int     Z_FreeMemory(void);

// 内存块的结构体
typedef struct memblock_s
{
    int             size;   // 包括头部和可能的小碎片
    void**          user;   // 如果是自由块则为NULL
    int             tag;    // 清理级别
    int             id;     // 应该是ZONEID
    struct memblock_s* next; // 下一个内存块
    struct memblock_s* prev; // 上一个内存块
} memblock_t;

// 宏定义，用于修改内存块的标签
#define Z_ChangeTag(p,t) \
{ \
    if ((((memblock_t*)((byte*)(p) - sizeof(memblock_t)))->id) != 0x1d4a11) \
        I_Error("Z_CT at "__FILE__":%i", __LINE__); \
    Z_ChangeTag2(p,t); \
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
