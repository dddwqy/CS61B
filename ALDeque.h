#pragma once
#include<iostream>
using  namespace std;
/*���ļ�ʹ��������ģ��˫�˶���*/
template<class T>
class ALDeque
{
	T* item;//�����Ԫ��
	int size;////��¼���еĳ���
	int len;//��¼����ĳ���
	/*���еĳ��Ⱥ�����ĳ����ǲ�һ���ģ����е���ʼλ�ò������������Ϊ0��������λ��Ҳ��һ�����������λ�ã���ʼλ�����м䣬����addfirstҲ����addlast*/
	int 0_position;//�������ж��е���ʼλ�õ�����
	/*�������������൱��ʹ��������ģ��ָ�룬�����е���ʼλʱ����ʹ��first_prev���ƶ����ƶ������һ���������һ��ʱͬ�����ʹ��last-next�ص���㣬ʵ��ѭ��*/
	int first_prev;//��¼���е����һ��λ��
	int last_next;//��¼���е���ʼ��
public:
	ALDeque() { item = new T[8](0); size = 0; 0_postition = 8 / 2; first_prev = 0, last_next = 0; len = 8; }
	ALDeque(T mitem) { item = new T[8](0); item[0] = mitem; size = 1; 0_postiton = 8 / 2; item[0_positin] = mitem; first_prev = 0_posision + size - 1; last_next = 0_position; len = 8; }
	void Addfirst(T x);//��ͷ��
	void Addlast(T x);//��β�ͼ�
	int size() { return size; }
	void Update_size();//��������ĳ���
	void Update() {//����first_prev��last_next��ָ��ÿ�β�����Ҫ����
		first_prev = 0_position + size - 1;
		last_next = 0_position;
	}
	T Removefirst();//�Ƴ���Ԫ��
	T Removelast();//�Ƴ�βԪ��
	T Get(int index);//�õ�ָ��������ֵ
	void PrintDeque();//��ӡ
	bool Isempty() { return size == 0; };
};
template<class T>
void ALDeque<T>::Addfirst(T x)
{
	if (0_position-1>=0)//�����Ԫ��ǰ�ж϶��е���λ�õ������Ƿ���ǰ�ӻᳬ�������0λ��
	{
		0_position--;
		size++;
		Update();
		item[0_position] = x;
	}
	else {//�ǵĻ����´�С���ٴ���ӣ�
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
	if (!Isempty())///ȡ��ǰ�ж��Ƿ�Ϊ��
	{
		int temp = 0_position;
		0_position++;
		size--;
		Update();
		return item[0_position];
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
		int temp = 0_position;
		size--;
		Update();
		return itme[0_position];
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
void ALDeque<T>::Update_size()
{
	T* new_item = new T[size*3](0);//���3���Ĵ�С����ô��ǰ�Ӻ����Ӷ����Լ�size��С
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