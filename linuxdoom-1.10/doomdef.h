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
//  用于几乎所有内部数据结构的内部使用，包括密钥定义等等。
//
//-----------------------------------------------------------------------------

#ifndef __DOOMDEF__
#define __DOOMDEF__

#include <stdio.h>
#include <string.h>

//
// 全局参数/定义。
//
// DOOM版本
enum { VERSION =  110 };

// 游戏模式处理 - 识别IWAD版本
// 以处理IWAD相关的动画等。
typedef enum
{
  shareware,  // DOOM 1共享版，E1，M9
  registered, // DOOM 1注册版，E3，M27
  commercial, // DOOM 2零售版，E1 M34
  // DOOM 2德国版未处理
  retail, // DOOM 1零售版，E4，M36
  indetermined // 嗯，未找到IWAD。
  
} GameMode_t;

// 任务包 - 对于TC项目可能有用？
typedef enum
{
  doom,       // DOOM 1
  doom2,      // DOOM 2
  pack_tnt,   // TNT任务包
  pack_plut,  // Plutonia任务包
  none

} GameMission_t;

// 识别使用的语言，软件本地化。
typedef enum
{
  english,
  french,
  german,
  unknown

} Language_t;

// 如果rangecheck未定义，
// 大多数参数验证调试代码将不会被编译
#define RANGECHECK

// 是否使用外部声音服务器。
// 需要分别运行的sndserver二进制文件
// 由Dave Taylor引入。集成的声音支持是实验性的，
// 且未完成。默认是同步的。
// 实验性的基于定时器的异步处理由SNDINTR处理。
#define SNDSERV  1
//#define SNDINTR  1

// 这个开关在MIT SHM（没有适当的鼠标）
// 和XFree86 DGA（鼠标采样）之间切换。最初的
// linuxdoom使用了SHM，这是默认值。
//#define X11_DGA 1

//
// 用于在游戏开始时调整屏幕大小。
// 它将不能动态工作，请参阅visplanes。
//
#define BASE_WIDTH      320

// 这是教育性的但徒劳的改变
// 比例，例如改为2。状态栏的绘制，
// 菜单等与图形隐含的比例相关联
// 由图形确定。
#define SCREEN_MUL      1
#define INV_ASPECT_RATIO 0.625 // 0.75，理想情况下

// 定义很差。C很差。
// C++可能对OOP来说不好，但它肯定比C更好。
// 所以。
#define SCREENWIDTH  320
//SCREEN_MUL*BASE_WIDTH //320
#define SCREENHEIGHT 200
//(int)(SCREEN_MUL*BASE_WIDTH*INV_ASPECT_RATIO) //200

// 多人游戏/网络的最大玩家数。
#define MAXPLAYERS      4

// 状态更新，每秒的tics数。
#define TICRATE        35

// 游戏的当前状态：我们是否
// 在玩，看插曲屏幕，
// 游戏最终动画，或演示。
typedef enum
{
    GS_LEVEL,
    GS_INTERMISSION,
    GS_FINALE,
    GS_DEMOSCREEN
} gamestate_t;

//
// 难度/技能设置/过滤器。
//

// 技能标志。
#define MTF_EASY        1
#define MTF_NORMAL      2
#define MTF_HARD        4

// 聋子怪物/不对声音做出反应。
#define MTF_AMBUSH      8

typedef enum
{
    sk_baby,
    sk_easy,
    sk_medium,
    sk_hard,
    sk_nightmare
} skill_t;

//
// 钥匙卡。
//
typedef enum
{
    it_bluecard,
    it_yellowcard,
    it_redcard,
    it_blueskull,
    it_yellowskull,
    it_redskull,
    
    NUMCARDS
    
} card_t;

// 定义的武器，
// 包括指示用户未更改武器的标记。
typedef enum
{
    wp_fist,
    wp_pistol,
    wp_shotgun,
    wp_chaingun,
    wp_missile,
    wp_plasma,
    wp_bfg,
    wp_chainsaw,
    wp_supershotgun,

    NUMWEAPONS,
    
    // 没有挂起的武器更改。
    wp_nochange

} weapontype_t;

// 定义的弹药类型。
typedef enum
{
    am_clip,    // 手枪/链枪弹药。
    am_shell,   // 霰弹枪/双管霰弹枪。
    am_cell,    // 等离子枪，BFG。
    am_misl,    // 导弹发射器。
    NUMAMMO,
    am_noammo   // 链锯/拳头无限。
} ammotype_t;

// 强化物品。
typedef enum
{
    pw_invulnerability,
    pw_strength,
    pw_invisibility,
    pw_ironfeet,
    pw_allmap,
    pw_infrared,
    NUMPOWERS
} powertype_t;

//
// 强化物品持续时间，
// 到期的秒数，
// 假设 TICRATE 是每秒 35 次。
//
typedef enum
{
    INVULNTICS  = (30*TICRATE),
    INVISTICS   = (60*TICRATE),
    INFRATICS   = (120*TICRATE),
    IRONTICS    = (60*TICRATE)
} powerduration_t;

//
// DOOM键盘定义。
// 这是由Setup.Exe配置的东西。
// 大多数键数据都是简单的ascii（大写）。
//
#define KEY_RIGHTARROW  0xae
#define KEY_LEFTARROW   0xac
#define KEY_UPARROW     0xad
#define KEY_DOWNARROW   0xaf
#define KEY_ESCAPE      27
#define KEY_ENTER       13
#define KEY_TAB         9
#define KEY_F1          (0x80+0x3b)
#define KEY_F2          (0x80+0x3c)
#define KEY_F3          (0x80+0x3d)
#define KEY_F4          (0x80+0x3e)
#define KEY_F5          (0x80+0x3f)
#define KEY_F6          (0x80+0x40)
#define KEY_F7          (0x80+0x41)
#define KEY_F8          (0x80+0x42)
#define KEY_F9          (0x80+0x43)
#define KEY_F10         (0x80+0x44)
#define KEY_F11         (0x80+0x57)
#define KEY_F12         (0x80+0x58)

#define KEY_BACKSPACE   127
#define KEY_PAUSE       0xff

#define KEY_EQUALS      0x3d
#define KEY_MINUS       0x2d

#define KEY_RSHIFT      (0x80+0x36)
#define KEY_RCTRL       (0x80+0x1d)
#define KEY_RALT        (0x80+0x38)

#define KEY_LALT        KEY_RALT

// DOOM基本类型（布尔值），
// 以及最大/最小值。
//#include "doomtype.h"

// 固定点。
//#include "m_fixed.h"

// 字节序处理。
//#include "m_swap.h"

// 二进制角度，正弦/余弦/反正切查找。
//#include "tables.h"

// 事件类型。
//#include "d_event.h"

// 游戏功能，技能。
//#include "g_game.h"

// 所有外部数据都在这里定义。
//#include "doomdata.h"

// 所有重要的打印字符串。
// 语言选择（消息字符串）。
//#include "dstrings.h"

// Player是一个特殊的演员。
//struct player_s;
//
//#include "d_items.h"
//#include "d_player.h"
//#include "p_mobj.h"
//#include "d_net.h"
//
// PLAY
//#include "p_tick.h"
//
// Header，由声音实用程序生成。
// 该实用程序由Dave Taylor编写。
//#include "sounds.h"

#endif          // __DOOMDEF__
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
