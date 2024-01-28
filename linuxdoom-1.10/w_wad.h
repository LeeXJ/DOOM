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
//	WAD I/O功能。
//
//-----------------------------------------------------------------------------

#ifndef __W_WAD__
#define __W_WAD__

#ifdef __GNUG__
#pragma interface
#endif

//
// 类型
//

// WAD文件信息
typedef struct
{
    char	identification[4]; // 文件标识符，应该是"IWAD"或"PWAD"
    int		numlumps;           // WAD文件中的Lump数量
    int		infotableofs;       // Lump信息表的偏移量
    
} wadinfo_t;

// Lump信息
typedef struct
{
    int		filepos;            // Lump在文件中的位置
    int		size;               // Lump的大小
    char	name[8];             // Lump的名称
    
} filelump_t;

//
// WADFILE I/O相关的内容。
//
typedef struct
{
    char	name[8];             // Lump的名称
    int		handle;             // 文件句柄
    int		position;           // 当前文件读写位置
    int		size;               // 文件大小
} lumpinfo_t;

// Lump缓存
extern void** lumpcache;

// Lump信息数组
extern lumpinfo_t* lumpinfo;

// Lump数量
extern int numlumps;

// 初始化多个WAD文件
void W_InitMultipleFiles(char** filenames);

// 重新加载WAD文件
void W_Reload(void);

// 检查Lump名称对应的Lump编号
int W_CheckNumForName(char* name);

// 根据Lump名称获取Lump编号
int W_GetNumForName(char* name);

// 获取指定Lump编号的Lump长度
int W_LumpLength(int lump);

// 读取指定Lump编号的数据到目标缓冲区
void W_ReadLump(int lump, void *dest);

// 缓存指定Lump编号的数据，并使用指定标签
void* W_CacheLumpNum(int lump, int tag);

// 缓存指定Lump名称的数据，并使用指定标签
void* W_CacheLumpName(char* name, int tag);

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

// WAD（Where's All the Data）文件在Doom中具有重要作用，主要用于存储游戏所需的各种数据，包括地图、图形、音频、以及其他资源。以下是WAD文件在Doom中的几个关键作用：
// 地图数据存储： WAD文件包含了游戏地图的数据，这些数据描述了关卡的布局、物体位置、地形等。Doom的地图文件通常以.wad为扩展名，其中包含了用于构建关卡的信息。
// 图形和纹理： WAD文件存储了游戏中使用的图形和纹理。这些资源包括怪物、武器、墙壁、地板和天花板的纹理等。WAD文件确保了游戏可以快速地访问和加载这些图形元素。
// 音频资源： 游戏中的音效和音乐也存储在WAD文件中。这包括了玩家的动作声音、怪物的叫声、背景音乐等。WAD文件充当了音频数据的容器。
// 游戏数据： WAD文件还包含了一些与游戏逻辑相关的数据，例如敌人的属性、物品的效果、以及其他游戏元素的定义。这些数据确保了游戏的一致性和可玩性。
// 自定义内容支持： Doom的WAD文件还允许玩家或关卡设计者创建自定义内容。这使得玩家可以创造自己的地图、添加自定义图形和音频资源，以及修改游戏逻辑。
// 总的来说，WAD文件是Doom游戏的核心数据容器，包含了使游戏正常运行所需的所有关键信息。通过WAD文件，Doom提供了可扩展性和定制性，使玩家能够创建和分享自己的游戏内容。