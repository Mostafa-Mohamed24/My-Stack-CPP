#pragma once
#include <iostream>

using namespace std;

template <class T >
class clsDblLinkedList
{

protected :

	int _Size = 0;
public :

	class Node
	{
	public :
		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void PrintList()
	{
		Node* Current = head;
		while (Current != NULL)
		{
			cout << Current->value << "    ";
			Current = Current->next;
		}
	}

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node();

		NewNode->value = Value;
		NewNode->next = head;
		NewNode->prev = NULL;

		if (head != NULL)
			head->prev = NewNode;


		head = NewNode;
		_Size++;
	}

	void InsertAfter(Node* Current, T Value)
	{
		if (Current == NULL)
		{
			cout << "\n\nInvalid Node";
			return;
		}

		Node* NewNode = new Node();

		NewNode->value = Value;
		NewNode->next = Current->next;
		NewNode->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = NewNode;
		}

		Current->next = NewNode;
		
		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* newNode = new Node();

		newNode->value = Value;
		newNode->next = NULL;

		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
			_Size++;
			return;
		}

		Node* Current = head;

		while (Current->next != NULL)
		{
			Current = Current->next;
		}

		Current->next = newNode;

		newNode->prev = Current;
		_Size++;
	}

	Node* Find(T Value)
	{
		Node* Current = head;
		while (Current != NULL)
		{
			if (Current->value == Value)
			{
				return Current;
			}
			Current = Current->next;
		}

		return NULL;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (NodeToDelete == NULL)
			return;

		if (NodeToDelete == head)
			head = NodeToDelete->next;

		if (NodeToDelete->prev != NULL)
			NodeToDelete->prev->next = NodeToDelete->next;

		if (NodeToDelete->next != NULL)
			NodeToDelete->next->prev = NodeToDelete->prev;

		delete NodeToDelete;
		NodeToDelete = NULL;   

		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
			return;

		Node* Temp = head;
		head = Temp->next;

		
		if (Temp->next != NULL )
		{
			Temp->next->prev = NULL;
		}


		delete Temp;
		_Size--;
	}

	void DeleteLastNode()
	{

		// if we don't have any node in the list 
		if (head == NULL)
			return;

		// if we have just one node 
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}


		// We need to find the last node 
		Node* LastNode = head;

		while (LastNode->next != NULL)
		{
			LastNode = LastNode->next;
		}

		// Make the node before last node point to NULL by the next pointer 
		LastNode->prev->next = NULL;

		delete LastNode;
		_Size--;
	}

	// Function to return number of linked list items 
	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size != 0)
		{
			DeleteFirstNode();
		}

		head = NULL;
	}

	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;

		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;

			Current = Current->prev;
		}

		if (temp != nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int Index)
	{
		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Current = head;

		int Counter = 0;

		while (Counter != Index)
		{
			Current = Current->next;
			Counter++;
		}
		return Current;
	}

	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)

			return ItemNode->value;
		else
			return T();
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T Value)
	{
		Node* node = GetNode(Index);
		if (node != NULL)
		{
			InsertAfter(node, Value);
			return true;
		}
		else
			return false;
	}

};

