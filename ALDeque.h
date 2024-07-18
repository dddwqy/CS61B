#pragma once
#include<iostream>
using  namespace std;
/*该文件使用数组来模拟双端队列*/
template<class T>
class ALDeque
{
	T* item;//数组的元素
	int size;////记录队列的长度
	int len;//记录数组的长度
	/*队列的长度和数组的长度是不一样的，队列的起始位置不是数组的索引为0处，结束位置也不一定是数组结束位置，起始位放在中间，可以addfirst也可以addlast*/
	int 0_position;//在数组中队列的起始位置的索引
	/*这两个索引是相当于使用索引来模拟指针，当队列到起始位时可以使用first_prev来移动到移动到最后一个，到最后一个时同理可以使用last-next回到起点，实现循环*/
	int first_prev;//记录队列的最后一个位置
	int last_next;//记录队列的起始点
public:
	ALDeque() { item = new T[8](0); size = 0; 0_postition = 8 / 2; first_prev = 0, last_next = 0; len = 8; }
	ALDeque(T mitem) { item = new T[8](0); item[0] = mitem; size = 1; 0_postiton = 8 / 2; item[0_positin] = mitem; first_prev = 0_posision + size - 1; last_next = 0_position; len = 8; }
	void Addfirst(T x);//在头加
	void Addlast(T x);//在尾巴加
	int size() { return size; }
	void Update_size();//更新数组的长度
	void Update() {//更新first_prev和last_next的指向，每次操作完要更新
		first_prev = 0_position + size - 1;
		last_next = 0_position;
	}
	T Removefirst();//移除首元素
	T Removelast();//移除尾元素
	T Get(int index);//得到指定索引的值
	void PrintDeque();//打印
	bool Isempty() { return size == 0; };
};
template<class T>
void ALDeque<T>::Addfirst(T x)
{
	if (0_position-1>=0)//添加首元素前判断队列的首位置的索引是否往前加会超过数组的0位置
	{
		0_position--;
		size++;
		Update();
		item[0_position] = x;
	}
	else {//是的话更新大小，再次添加；
		Update_size();
		Addfirst(x);
	}
	
	return;
}
template<class T>
void ALDeque<T>::Addlast(T x)
{
	if (size+1<len)
	{
		size++;
		Update();
		item[first_prev] = x;
	}
	else {
		Update_size();
		Addlast(x);
	}
	return;
}
template<class T>
T ALDeque<T>::Removefirst()
{
	if (!Isempty())///取出前判断是否为空
	{
		int temp = 0_position;
		0_position++;
		size--;
		Update();
		return item[0_position];
	}
	else {
		cout<<"链表为空" << endl;
	}
	
}
template<class T>
T ALDeque<T>::Removelast()
{
	if (!Isempty())
	{
		int temp = 0_position;
		size--;
		Update();
		return itme[0_position];
	}
	else
	{
		cout<<"链表为空" << endl;
	}
	
}
template<class T>
T ALDeque<T>::Get(int index)
{
	return item[0_position+index];
}
template<class T>
void ALDeque<T>::PrintDeque()
{
	int temp = 0_position;
	int i = 1;
	while (i<=size)
	{
		cout<<item[0_position]<<' ';
		temp++;
		i++;
	}
	return;
}
template<class T>
void ALDeque<T>::Update_size()
{
	T* new_item = new T[size*3](0);//添加3倍的大小，那么向前加和向后加都可以加size大小
	int i = size;
	int j = 0_posiiton;
	for (i;i<size*2;i++)
	{
		new_item[i] = item[j];
		j++;
	}
	0_position = size;
	Update();
	T* temp = item;
	item = new_item;
	delete[]new_item;
	return;
}