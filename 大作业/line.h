#ifndef LINE_H
#define LINE_H

#include<vector>
#include<map>
#include<math.h>
using namespace std;

class Line
{
private:
	vector<pair<int,int>> dot;        // dot��¼������ĵ�E
	vector<pair<int,int>> vanish;     // vanish��¼�������ĵ㣨����������Ч�����������ĵ㲻һ���Ǳ�����ģ�
public:
	void add_dot(int x, int y);       // ��ȁE�����ĵ�x��y
	void add_vanish(int x,int y);     // ��ȁE������ĵ�x��y

	int dot_number();        // ���ر�����ĵ������
	int vanish_number();     // ���ر������ĵ������

	pair<int, int> last_dot();        // ��������һ��������ĵ������E
	pair<int, int> get_dot(int i);    // ȡ�õ�i��������ĵ������E
	pair<int, int> get_vanish(int i); // ȡ�õ�i���������ĵ������E

	void delete_last_dot();     // ɾ������һ��������ĵ�E
	void delete_last_vanish();  // ɾ������һ���������ĵ�E

	void clean_dot();       // ������еı�����ĵ�E
	void clean_vanish();    // ������еı������ĵ�E
	
	bool compare_last_dot(int x, int y);          // ӁE���һ����������λ�ñȽϣ����һ��������true
	bool compare_dot_i(int i,int x,int y);        // ӁE�i����������λ�ñȽϣ����һ��������true

	bool last_round(int x,int y);     // ���Ϊ����һ�������Χ8��������true
	
	bool dot_is_empty();     // ��E������Ƿ�Ϊ�?
	bool vanish_is_empty();  // ��E������Ƿ�Ϊ�?
};

#endif