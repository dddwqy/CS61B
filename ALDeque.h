#pragma once
#include<iostream>
using  namespace std;
/*该文件使用数组来模拟双端队列*/
/*与队列类似，因此需要有指向结尾的指针，有指向开头的指针，用记录开头索引和结尾索引的方式记录指针*/
/*使用plusone和minusone向后移和向前移动，模拟循环*/
template<class T>
class ALDeque
{
	T* item;//数组的元素
	int size;////记录队列的长度
	int len;//记录数组的长度
	/*队列的长度和数组的长度是不一样的，队列的起始位置不是数组的索引为0处，结束位置也不一定是数组结束位置，起始位放在中间，可以addfirst也可以addlast*/
	/*这两个索引是相当于使用索引来模拟指针，当队列到起始位时可以使用first_prev来移动到移动到最后一个，到最后一个时同理可以使用last-next回到起点，实现循环*/
	int first_prev;//记录队列的最后一个位置
	int last_next;//记录队列的起始点
	int Plusone(int index,int length);//索引往下加一个，因为是模拟队列所以跟原始的加不一样
	int Minusone(int index);//索引往前减一个，同上
public:
	ALDeque() { item = new T[8](0); size = 0; 0_postition = 8 / 2; first_prev = 4, last_next = 4; len = 8; }
	void Addfirst(T x);//在头加
	void Addlast(T x);//在尾巴加
	int size() { return size; }
	void Grow();//队列成长
	T Removefirst();//移除首元素
	T Removelast();//移除尾元素
	T Get(int index);//得到指定索引的值
	void PrintDeque();//打印
	bool Isempty() { return size == 0; };
};
template<class T>
void ALDeque<T>::Addfirst(T x)
{
	if (size==len-1)
	{
		Grow();
	}
	last_next = Minusone(last_next);
	item[last_next] = x;
	size++;
	return;
}
template<class T>
void ALDeque<T>::Addlast(T x)
{
	if (size==len-1)
	{
		Grow();
	}
	front_prev = Plusone(front_next,len);
	item[front_prev] = x;
	size++;
	return;
}
template<class T>
T ALDeque<T>::Removefirst()
{
	if (!Isempty())///取出前判断是否为空
	{
		T temp = item[last_prev];
		last_next = Plusone(last_next,len);
		return temp;
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
		T temp = item[first_next];
		first_prev = Minusone(first_prev);
		return temp;
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
int ALDeque<T>::Plusone(int index, int length)
{
	index %= length;
	if (index==length-1)//往下加，当索引到最后一个时下一个位置回到数组第一个
	{
		return 0;
	}
	return index + 1;
}

template<class T>
int ALDeque<T>::Minusone(int index)
{
	if (index==0)//往前减，理由同上
	{
		return length-1;
	}
	return index - 1;
}
template<class T>
void ALDeque<T>:: Grow()
{
	T*new_item = new T[len * 2](0);
	T* temp=nullptr;
	int ptr1 = last_next;
	int ptr2 = len;

	while (ptr1!=first_prev)
	{
		new_item[ptr2] = item[ptr1];
		ptr1 = Plusone(ptr1,len);
		ptr2 = Plusone(ptr2,len*2);
	}
	new_item[ptr2] = item[ptr1];
	first_prev = ptr2;
	last_next = len;
	temp = item;
	item = new_item;
	delete[]temp;
	return;
}