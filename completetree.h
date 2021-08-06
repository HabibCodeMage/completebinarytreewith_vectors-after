#pragma once
#ifndef COMPLETETREE_H
#define COMPLETETREE_H
#include"vector.h"
#include<cmath>
#include <iostream>
using namespace std;
template<typename E>
class completetree
{
public:
	typedef E* Position;
	typedef const E* const_Position;
private:
	vector<E> V;
protected:
	int idx(const_Position& p)
	{
		return p - V.begin();
	}
	Position pos(int i)
	{
		return  V.begin()+i;
	}
public:
	completetree(){V.push_back(1);}
	// constructor
	int size() const
	{
		return V.size()-1;
	}
	Position left(const_Position p)
	{
		return pos(2 * idx(p));
	}
	Position right(const_Position& p)
	{
		return pos(2 * idx(p) + 1);
	}
	Position parent(const_Position& p)
	{
		return pos(floor(idx(p) / 2));
	}
	bool hasLeft(const_Position& p) const
	{
		return 2 * idx(p) <= size();
	}
	bool hasRight(const_Position& p) const { return 2 * idx(p) + 1 <= size(); }
	bool isRoot(const_Position& p) const
	{
		return idx(p) == 1;
	}
	Position root()
	{
		return pos(1);
	}
	Position last()
	{
		return pos(size());
	}
	void addLast(const E& e)
	{
		V.push_back(e);
	}
	void removeLast()
	{
		V.popback();
	}
	void swap(const_Position& p, const_Position& q)
	{
		E e = *q; *q = *p; *p = e;
	}
	void bredthfirstsearch()
	{
		V.print();
	}
};
#endif // !COMPLETETREE_H