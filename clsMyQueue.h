#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _Queue;

public :

	void Push(T Value)
	{
		_Queue.InsertAtEnd(Value);
	}

	void Print()
	{
		_Queue.PrintList();
	}

	int Size()
	{
		return _Queue.Size();
	}

	T front()
	{
		return _Queue.GetItem(0);
	}

	T back()
	{
		return _Queue.GetItem(Size() - 1);
	}

	void pop()
	{
		_Queue.DeleteFirstNode();
	}

	bool IsEmpty()
	{
		return _Queue.IsEmpty();
	}

	T GetItem(int Index)
	{
		return _Queue.GetItem(Index);
	}

	void Reverse()
	{
		_Queue.Reverse();
	}

	void UpdateItem(int Index,T NewValue)
	{
		_Queue.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T Value)
	{
		_Queue.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_Queue.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		Push(Value);
	}

	void Clear()
	{
		_Queue.Clear();
	}
};

