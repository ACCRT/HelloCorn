#ifndef LINE_H
#define LINE_H

#include<vector>
#include<map>
#include<math.h>
using namespace std;

class Line
{
private:
	vector<pair<int,int>> dot;        // dot记录被连起的祦E
	vector<pair<int,int>> vanish;     // vanish记录被消除的点（由于有特殊效果，被消除的点不一定是被连起的）
public:
	void add_dot(int x, int y);       // 加葋E涣鸬牡鉿，y
	void add_vanish(int x,int y);     // 加葋E幌牡鉿，y

	int dot_number();        // 返回被连起的点的数量
	int vanish_number();     // 返回被消除的点的数量

	pair<int, int> last_dot();        // 返回煮一个被连起的点的坐眮E
	pair<int, int> get_dot(int i);    // 取得第i个被连起的点的坐眮E
	pair<int, int> get_vanish(int i); // 取得第i个被消除的点的坐眮E

	void delete_last_dot();     // 删除煮一个被连起的祦E
	void delete_last_vanish();  // 删除煮一个被消除的祦E

	void clean_dot();       // 清除所有的被连起的祦E
	void clean_vanish();    // 清除所有的被消除的祦E
	
	bool compare_last_dot(int x, int y);          // 觼E笠桓霰涣鸬愕奈恢帽冉希绻谎祷豻rue
	bool compare_dot_i(int i,int x,int y);        // 觼E趇个被连起点的位置比较，如果一样，返回true

	bool last_round(int x,int y);     // 如果为煮一个点的周围8个，返回true
	
	bool dot_is_empty();     // 紒E饬呤欠裎?
	bool vanish_is_empty();  // 紒E庀欠裎?
};

#endif