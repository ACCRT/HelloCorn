#include"line.h"

void Line::add_dot(int x, int y)
{
	pair<int,int> temp;
	for( vector<pair<int, int>>::iterator ite = dot.begin(); ite !=dot.end(); ite++)
		if (x == ite->first && y == ite->second)
			return;
	temp.first = x;
	temp.second = y;
	dot.push_back(temp);
}

void Line::add_vanish(int x,int y)
{
	pair<int,int> temp;
	for( vector<pair<int, int>>::iterator ite = vanish.begin(); ite !=vanish.end(); ite++)
		if (x == ite->first && y == ite->second)
			return;
	temp.first = x;
	temp.second = y;
	vanish.push_back(temp);
}

int Line::dot_number()
{
	return dot.size();
}

int Line::vanish_number()
{
	return vanish.size();
}

pair<int, int> Line::last_dot()
{
	pair<int,int> temp;
	temp.first = dot.back().first;
	temp.second = dot.back().second;
	return temp;
}

pair<int, int> Line::get_dot(int i)
{
	pair<int, int> temp;
	temp.first = dot[i].first;
	temp.second = dot[i].second;
	return temp;
}
pair<int, int> Line::get_vanish(int i)
{
	pair<int, int> temp;
	temp.first = vanish[i].first;
	temp.second = vanish[i].second;
	return temp;
}

void Line::delete_last_dot()
{
	if(!dot_is_empty())
		dot.pop_back();
}

void Line::delete_last_vanish()
{
	if(!vanish_is_empty())
		vanish.pop_back();
}

void Line::clean_dot()
{
	while(!dot_is_empty())
		delete_last_dot();
}

void Line::clean_vanish()
{
	while(!vanish_is_empty())
		delete_last_vanish();
}

bool Line::compare_last_dot(int x, int y)
{
	return (!dot_is_empty() && dot.back().first == x && dot.back().second == y);
}

bool Line::compare_dot_i(int i,int x,int y)
{
	return (!dot_is_empty() && dot[i].first == x && dot[i].second == y);
}

bool Line::last_round(int x,int y)
{
	if(!dot_is_empty())
		return (abs(dot.back().first - x) <= 1 && abs(dot.back().second - y) <= 1 && !(dot.back().first == x && dot.back().second == y));
	return false;
}

bool Line::dot_is_empty()
{
	return (!dot.size());
}

bool Line::vanish_is_empty()
{
	return (!vanish.size());
}