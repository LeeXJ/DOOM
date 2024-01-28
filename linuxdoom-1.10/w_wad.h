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
