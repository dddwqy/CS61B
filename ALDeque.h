#pragma once
#include<iostream>
using  namespace std;
/*���ļ�ʹ��������ģ��˫�˶���*/
/*��������ƣ������Ҫ��ָ���β��ָ�룬��ָ��ͷ��ָ�룬�ü�¼��ͷ�����ͽ�β�����ķ�ʽ��¼ָ��*/
/*ʹ��plusone��minusone����ƺ���ǰ�ƶ���ģ��ѭ��*/
template<class T>
class ALDeque
{
	T* item;//�����Ԫ��
	int size;////��¼���еĳ���
	int len;//��¼����ĳ���
	/*���еĳ��Ⱥ�����ĳ����ǲ�һ���ģ����е���ʼλ�ò������������Ϊ0��������λ��Ҳ��һ�����������λ�ã���ʼλ�����м䣬����addfirstҲ����addlast*/
	/*�������������൱��ʹ��������ģ��ָ�룬�����е���ʼλʱ����ʹ��first_prev���ƶ����ƶ������һ���������һ��ʱͬ�����ʹ��last-next�ص���㣬ʵ��ѭ��*/
	int first_prev;//��¼���е����һ��λ��
	int last_next;//��¼���е���ʼ��
	int Plusone(int index,int length);//�������¼�һ������Ϊ��ģ��������Ը�ԭʼ�ļӲ�һ��
	int Minusone(int index);//������ǰ��һ����ͬ��
public:
	ALDeque() { item = new T[8](0); size = 0; 0_postition = 8 / 2; first_prev = 4, last_next = 4; len = 8; }
	void Addfirst(T x);//��ͷ��
	void Addlast(T x);//��β�ͼ�
	int size() { return size; }
	void Grow();//���гɳ�
	T Removefirst();//�Ƴ���Ԫ��
	T Removelast();//�Ƴ�βԪ��
	T Get(int index);//�õ�ָ��������ֵ
	void PrintDeque();//��ӡ
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
	if (!Isempty())///ȡ��ǰ�ж��Ƿ�Ϊ��
	{
		T temp = item[last_prev];
		last_next = Plusone(last_next,len);
		return temp;
	}
	else {
		cout<<"����Ϊ��" << endl;
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
		cout<<"����Ϊ��" << endl;
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
	if (index==length-1)//���¼ӣ������������һ��ʱ��һ��λ�ûص������һ��
	{
		return 0;
	}
	return index + 1;
}

template<class T>
int ALDeque<T>::Minusone(int index)
{
	if (index==0)//��ǰ��������ͬ��
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