#ifndef FILE_H
#define FILE_H

#include<fstream>
#include<string>

using namespace std;

// File类用来柄婢文件输葋E涑隽鳎丒募薪换ィ娲⒁约岸寥?
class File
{
private:
	ofstream save;        // 用来存储的羴E
	ifstream load;        // 用来读取的羴E
	ofstream record;      // 用来记录视频的羴E
	ifstream review;      // 用来回放视频的羴E

	bool is_recording;    // 柄婢是否在记录
	bool is_reviewing;    // 柄婢是否在回放
public:
	File();     // 构詠E丒

	void read_map(int i);   // 读取地图数据
	void read_best_score(); // 读取置成绩

	void open_record();     // 打开记录视频文件
	void close_record();    // 关闭记录视频文件
	void open_review();     // 打开回放视频文件
	void close_review();    // 关闭回放视频文件

	void write_file(string filemane);    // 向filename文件中写葋E衩仔畔?
	void read_file(string filename);     // 从filename文件中读取玉米信息
	void record_file();     // 记录当前视频信息
	void review_file();     // 回放当前视频信息

	void write_best_score();// 写葋E殉杉?

	bool get_is_recording();// 取得是否在记录
	bool get_is_reviewing();// 取得是否在回放
	void set_is_recording(bool b);       // 设置是否在记录状态为b
	void set_is_reviewing(bool b);       // 设置是否在回放状态为b
};

extern File* file;

#endif