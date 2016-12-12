#ifndef FILE_H
#define FILE_H

#include<fstream>
#include<string>

using namespace std;

// File����������ļ���ȁE������ӁEļ����н������洢�Լ����?
class File
{
private:
	ofstream save;        // �����洢����E
	ifstream load;        // ������ȡ����E
	ofstream record;      // ������¼��Ƶ����E
	ifstream review;      // �����ط���Ƶ����E

	bool is_recording;    // ����Ƿ��ڼ�¼
	bool is_reviewing;    // ����Ƿ��ڻط�
public:
	File();     // ��ԁE�E

	void read_map(int i);   // ��ȡ��ͼ����
	void read_best_score(); // ��ȡ���óɼ�

	void open_record();     // �򿪼�¼��Ƶ�ļ�
	void close_record();    // �رռ�¼��Ƶ�ļ�
	void open_review();     // �򿪻ط���Ƶ�ļ�
	void close_review();    // �رջط���Ƶ�ļ�

	void write_file(string filemane);    // ��filename�ļ���дȁE������?
	void read_file(string filename);     // ��filename�ļ��ж�ȡ������Ϣ
	void record_file();     // ��¼��ǰ��Ƶ��Ϣ
	void review_file();     // �طŵ�ǰ��Ƶ��Ϣ

	void write_best_score();// дȁE��ѳɼ?

	bool get_is_recording();// ȡ���Ƿ��ڼ�¼
	bool get_is_reviewing();// ȡ���Ƿ��ڻط�
	void set_is_recording(bool b);       // �����Ƿ��ڼ�¼״̬Ϊb
	void set_is_reviewing(bool b);       // �����Ƿ��ڻط�״̬Ϊb
};

extern File* file;

#endif