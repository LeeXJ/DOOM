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
// 描述：
//	Gamma校正查找表（LUT）。
//	直接向屏幕绘制补丁的功能（通过post）。
//	将块复制到屏幕的功能。
//
//-----------------------------------------------------------------------------

#ifndef __V_VIDEO__
#define __V_VIDEO__

#include "doomtype.h"

#include "doomdef.h"

// 因为我们引用了patches，所以需要包含。
#include "r_data.h"

//
// VIDEO
//

#define CENTERY			(SCREENHEIGHT/2)


// 屏幕0是由I_Update screen更新的屏幕。
// 屏幕1是一个额外的缓冲区。

extern byte* screens[5];     // 屏幕缓冲区数组，可以有多个屏幕
extern int dirtybox[4];      // 脏矩形的坐标 [x, y, width, height]
extern byte gammatable[5][256]; // Gamma校正查找表，用于颜色校正
extern int usegamma;          // 是否使用Gamma校正

// 分配缓冲屏幕，必须在R_Init之前调用。
void V_Init(void);

// 复制矩形区域
void V_CopyRect(int srcx, int srcy, int srcscrn, int width, int height, int destx, int desty, int destscrn);

// 绘制贴图补丁到屏幕
void V_DrawPatch(int x, int y, int scrn, patch_t* patch);

// 直接绘制贴图补丁到屏幕
void V_DrawPatchDirect(int x, int y, int scrn, patch_t* patch);

// 绘制线性像素块到视图缓冲区
void V_DrawBlock(int x, int y, int scrn, int width, int height, byte* src);

// 从视图缓冲区读取线性像素块
void V_GetBlock(int x, int y, int scrn, int width, int height, byte* dest);

// 标记矩形区域为脏矩形
void V_MarkRect(int x, int y, int width, int height);

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
