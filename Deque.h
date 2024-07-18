#pragma once
#include"InNode.h"
#include<iostream>
using namespace std;

class InNode;
class Deque
{
private:
	InNode* sentisel;
	int size;
	int Getre(InNode*code,int index)
public:
	Deque(int item)
	{
		sentisel = new InNode(0);
		sentisel->prev = sentisel;
		sentisel->next = sentisel;
		sentisel->next = new InNode(item, sentisel, sentisel);
		snetisel->prev = sentisel->next;

	}
	Deque() {
		sentisel = new InNode(0);
		sentisel->prev = sentisel;
		sentisel->next = sentisel;
		size = 0;
	}
	void Addfirst(int item)
	{
		sentisel->next = new InNode(item, sentisel, sentisel->next);
		sentisel->next->next->prev = sentisel->next;
		size++;
		return;
	}
	void Addlast(int item)
	{
		sentisel->prev = new InNode(item, sentisel->prev, sentisel);
		sentisel->prev->next = sentisel->prev;
		size++;
	}
	int Get(int index)
	{
		InNode* temp = sentisel;
		int i = -1;
		if (index <= size - 1)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
				i++;
				if (i == index)
				{
					break;
				}
			}
		}
		return temp->item;
	}
	int Getrecusive(int index)
	{
		return Getre(sentisel->next,index);
	}

	int Removefirst()
	{
		InNode* temp = sentisel->next;
		sentisel->next = sentisel->next->next;
		sentisel->next->prev = sentisel;
		return temp->item;
	}
	int Removelast()
	{
		InNode* temp = sentisel->prev;
		sentisel->prev = sentisel->prev->prev;
		sentisel->prev->next = sentisel;
		return temp->item;
	}
};
int Deque::Getre(InNode* code, int index)
{
	if (index==0)
	{
		return code->item;
	}
	return Getre(code->next,index-1);
}