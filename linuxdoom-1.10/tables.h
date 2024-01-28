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
//	查找表。
//	请不要尝试查找它们 :-)
//	按照出现的顺序：
//
//	int finetangent[4096]	- Tangens查找表。
//	 应该与BAM相当好地配合使用（12位中的16位，
//      通过位移实现有效）。
//
//	int finesine[10240]		- 正弦查找表。
//	 猜猜，也可作为余弦表使用。
//	 有趣的是，如何使用BAM（Binary Angle Measument）？ 
//
//	int tantoangle[2049]	- ArcTan查找表，
//	  将tan(angle)快速映射到angle。得搜索。
//    
//-----------------------------------------------------------------------------


#ifndef __TABLES__
#define __TABLES__



#ifdef LINUX
#include <math.h>
#else
#define PI				3.141592657
#endif


#include "m_fixed.h"
	
#define FINEANGLES		8192
#define FINEMASK		(FINEANGLES-1)


// 0x100000000 to 0x2000
#define ANGLETOFINESHIFT	19		

// 有效大小是10240。
extern  fixed_t		finesine[5*FINEANGLES/4];   // 正弦查找表，用于加速正弦计算

// 重用数据，只是PI/2相位移位。
extern  fixed_t*	finecosine;                  // 余弦查找表，与正弦表共享数据，相位差PI/2

// 有效大小是4096。
extern fixed_t		finetangent[FINEANGLES/2];  // Tangens查找表，用于加速正切计算

// 二进制角度测量，BAM。
#define ANG45			0x20000000
#define ANG90			0x40000000
#define ANG180		0x80000000
#define ANG270		0xc0000000


#define SLOPERANGE		2048
#define SLOPEBITS		11
#define DBITS			(FRACBITS-SLOPEBITS)

typedef unsigned angle_t;


// 有效大小是2049；
// +1的大小是为了处理x==y的情况
// 无需额外的检查。
extern angle_t		tantoangle[SLOPERANGE+1];   // ArcTan查找表，将tan(angle)映射到angle

// 实用函数，
// 由R_PointToAngle调用。
int
SlopeDiv
( unsigned	num,
  unsigned	den);


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
