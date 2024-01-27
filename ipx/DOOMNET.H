// doomnet.h

// 定义 VGA 寄存器端口
#define PEL_WRITE_ADR   0x3c8
#define PEL_DATA        0x3c9

// 定义设置颜色为黑色的宏
#define I_ColorBlack(r, g, b) {outp(PEL_WRITE_ADR, 0); outp(PEL_DATA, r); outp(PEL_DATA, g); outp(PEL_DATA, b);}

// 定义网络相关的常量
#define MAXNETNODES 8      // 最多的计算机数
#define MAXPLAYERS 4       // 4个玩家最多 + 无人机

#define CMD_SEND 1
#define CMD_GET  2

#define DOOMCOM_ID 0x12345678l

// 定义结构体 doomcom_t 用于 DOOM 和驱动之间的通信
typedef struct
{
    long id;
    short intnum;      // DOOM 执行的中断来发送命令

    // 与 DOOM 和驱动之间的通信
    short command;      // CMD_SEND 或 CMD_GET
    short remotenode;   // 发送的目标，由 get 设置 (-1 = 没有数据包)
    short datalength;   // 发送的 doomdata 的字节数 / 读取的字节数

    // 所有节点共有的信息
    short numnodes;     // 控制台始终为节点 0
    short ticdup;       // 1 = 不复制，2-5 = 慢网的复制
    short extratics;    // 1 = 在每个数据包中发送备份 tic
    short deathmatch;   // 1 = 死亡竞赛
    short savegame;     // -1 = 新游戏，0-5 = 加载存档
    short episode;      // 1-3
    short map;          // 1-9
    short skill;        // 1-5

    // 特定节点的信息
    short consoleplayer; // 0-3 = 玩家编号
    short numplayers;    // 1-4
    short angleoffset;   // 1 = 左，0 = 中，-1 = 右
    short drone;         // 1 = 无人机

    // 要发送的数据包数据
    char data[512];
} doomcom_t;

// 声明全局变量
extern doomcom_t doomcom;
extern void interrupt (*olddoomvect)(void);
extern int vectorishooked;

// 函数声明
int CheckParm(char *check);
void LaunchDOOM(void);
void interrupt NetISR(void);
