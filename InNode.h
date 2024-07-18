#pragma once
#include<iostream>
using namespace std;

class InNode
{
	friend class Deque;
private:
	int item;
	InNode* prev;
	InNode* next;
public:
	InNode(int mitem, InNode* mprev = nullptr,InNode*mnext=nullptr):item(mitem),prev(mprev),next(mnext) {}
};
