#ifndef LOGIC_H
#define LOGIC_H

#include"GUI.h"

extern int score_one;

// 逻辑类，调用所有逻辑动讈E
class Logic {
private:
	static bool esc();       // 紒E槭欠竦饔昧薳sc退硜E

	static bool is_vanished(int i, int j);    // 紒E獾趇列，第j行玉米是否消失
	static bool is_recording();     // 紒E馐欠裨诩锹?
	static bool is_reviewing();     // 紒E馐欠裨诨胤?
	static bool can_vanish();       // 紒E馐欠裣?
	static bool can_add_special();  // 紒E馐欠衲苈慵尤丒衩椎奶跫ㄎ叩愦笥?个）
	
	static bool MenuFrame(); // menu时调用的逻辑
	static bool GameFrame(); // game时调用的逻辑

	static bool same_color(int i1,int j1,int i2,int j2);  // 紒E鈏1,j1玉米觼E2,j2玉米是否同色
public:
	static void connect();   // 紒E槭蟊丒佑衩?
	static void associate(); // 紒E樗斜涣挠衩?

	static void save(string filename);    // 存储玉米信息到filename中
	static void load(string filename);    // 从filename中读取玉米信息
	static void record();    // 记录这一帧的视频
	static void review();    // 回放这一帧的视频

	//static void previous();

	static void vanish();    // 玉米消失
	static void fall();      // 玉米掉聛E
	static void add_special();   // 加葋E厥庥衩?
	static void statistic(); // 统计分数，时间等信息

	static void fresh();     // 刷新图片为全部未点击状态
	static void clean();     // 清除连线及消除数据

	static void create(int i,int j);   // 在第i列,j行随机生成一个玉米

	static void start_review();     // 开始回放
	static void stop_review();      // 结束回放
	static void start_record();     // 开始记录
	static void stop_record();      // 结束记录

	static void return_to_menu();   // 返回到menu stage
	static void return_to_game();   // 返回到game stage
	static bool FrameFunc(); // hge每一帧调用的逻辑函数

};

#endif