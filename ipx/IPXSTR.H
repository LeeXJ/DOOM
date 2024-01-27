#define STR_NETABORT	"Network game synchronization aborted."
// 网络游戏同步中止。

#define STR_UNKNOWN		"Got an unknown game packet during setup"
// 在设置过程中收到未知的游戏数据包。

#define STR_FOUND		"Found a node!"
// 发现一个节点！

#define STR_LOOKING		"Looking for a node"
// 寻找节点中。

#define STR_MORETHAN	"More than %i players specified!"
// 指定了超过%i个玩家！

#define STR_NONESPEC	"No players specified for game!"
// 未指定玩家参与游戏！

#define STR_CONSOLEIS	"Console is player %i of %i"
// 控制台是%i/%i号玩家。

#define STR_NORESP		"No such response file!"
// 没有这个响应文件！

#define STR_FOUNDRESP   "Found response file"
// 找到响应文件。

#define STR_DOOMNETDRV	"DOOM II NETWORK DEVICE DRIVER"
// DOOM II网络设备驱动程序。

#define STR_VECTSPEC	"The specified vector (0x%02x) was already hooked."
// 指定的向量（0x%02x）已经被挂接。

#define STR_NONULL	\
"Warning: no NULL or iret interrupt vectors were found in the 0x60 to 0x66\n"\
"range.  You can specify a vector with the -vector 0x<num> parameter."
// 警告：在0x60到0x66范围内找不到NULL或iret中断向量。您可以使用 -vector 0x<num> 参数指定一个向量。

#define STR_COMMVECT	"Communicating with interrupt vector 0x%x"
// 与中断向量0x%x进行通信。

#define STR_USEALT		"Using alternate port %i for network"
// 使用备用端口%i进行网络通信。

#define STR_RETURNED	"Returned from DOOM II"
// 从DOOM II返回。

#define STR_ATTEMPT		"Attempting to find all players for %i player net play. "\
						"Press ESC to exit.\n"
// 尝试找到%i个玩家进行网络游戏。按ESC退出。


// 这些字符串似乎是用于在 DOOM 游戏中的网络部分输出不同的信息和警告，涵盖了网络同步、节点发现、响应文件等各个方面的情况。