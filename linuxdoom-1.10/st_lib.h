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
// 	状态栏小部件代码。
//
//-----------------------------------------------------------------------------

#ifndef __STLIB__
#define __STLIB__

// 我们在引用patches。
#include "r_defs.h"

//
// 背景和前景屏幕编号
//
#define BG 4
#define FG 0

//
// 小部件的typedef
//

// 数字小部件
typedef struct
{
    // 右上角数字的位置（右对齐）
    int x;
    int y;

    // 数字中的最大位数
    int width;

    // 上一个数字值
    int oldnum;

    // 指向当前值的指针
    int* num;

    // 指向布尔值的指针，表示是否更新数字
    boolean* on;

    // 0-9的贴图列表
    patch_t** p;

    // 用户数据
    int data;

} st_number_t;

// 百分比小部件（数字小部件的“子”部件，
// 更确切地说，包含数字小部件。）
typedef struct
{
    // 数字信息
    st_number_t n;

    // 百分号图形
    patch_t* p;

} st_percent_t;

// 多图标小部件
typedef struct
{
    // 图标的中心对齐位置
    int x;
    int y;

    // 上一个图标编号
    int oldinum;

    // 指向当前图标的指针
    int* inum;

    // 指向布尔值的指针，表示是否更新图标
    boolean* on;

    // 图标列表
    patch_t** p;

    // 用户数据
    int data;

} st_multicon_t;

// 二进制图标小部件
typedef struct
{
    // 图标的中心对齐位置
    int x;
    int y;

    // 上一个图标值
    int oldval;

    // 指向当前图标状态的指针
    boolean* val;

    // 指向布尔值的指针，表示是否更新图标
    boolean* on;

    patch_t* p; // 图标
    int data;   // 用户数据

} st_binicon_t;

//
// 小部件的创建、访问和更新例程
//

// 初始化小部件库。
// 更确切地说，初始化STMINUS，
// 其他所有都是在其他地方完成的。
void STlib_init(void);

// 数字小部件例程
void
STlib_initNum
( st_number_t* n,
  int x,
  int y,
  patch_t** pl,
  int* num,
  boolean* on,
  int width );

void
STlib_updateNum
( st_number_t* n,
  boolean refresh );

// 百分比小部件例程
void
STlib_initPercent
( st_percent_t* p,
  int x,
  int y,
  patch_t** pl,
  int* num,
  boolean* on,
  patch_t* percent );

void
STlib_updatePercent
( st_percent_t* per,
  int refresh );

// 多图标小部件例程
void
STlib_initMultIcon
( st_multicon_t* mi,
  int x,
  int y,
  patch_t** il,
  int* inum,
  boolean* on );

void
STlib_updateMultIcon
( st_multicon_t* mi,
  boolean refresh );

// 二进制图标小部件例程
void
STlib_initBinIcon
( st_binicon_t* b,
  int x,
  int y,
  patch_t* i,
  boolean* val,
  boolean* on );

void
STlib_updateBinIcon
( st_binicon_t* bi,
  boolean refresh );

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

// 这段代码定义了几个结构体（st_number_t、st_percent_t、st_multicon_t、st_binicon_t）来表示
// 不同类型的状态栏小部件，例如数字、百分比、多图标和二进制图标。还提供了一些初始化和更新例程，用
// 于管理这些小部件的状态。整个代码似乎是嵌入在DOOM游戏引擎中的一部分，用于处理状态栏的显示。