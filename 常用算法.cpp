#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>
using namespace std;
//find查找元素(查找自定义元素:重载==
//find_if按条件查找元素(重载()
//transform前要为目标容器开辟空间 
class m_transform {
public:
	int operator()(int v)
	{
		return v;
	}
};
//for_each
void m_print(int val)
{
	cout << val << " ";
}
class Print {
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
int main() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>v2;
	v2.resize(v.size());
	for_each(v.begin(),v.end(),m_print);
	for_each(v.begin(), v.end(), Print());
	transform(v.begin(), v.end(), v2.begin(), m_transform());
	for_each(v.begin(), v.end(), Print());
	return 0;
}
//void m_print(vector<bool>& v)
//{
//	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//}
//int main()
//{
//	vector<bool>v;
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(false);
//	v.push_back(true);
//	vector<bool>v2(v);
//	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
//	m_print(v);
//	m_print(v2);
//	v.resize(4, false);
//	return 0;
//}