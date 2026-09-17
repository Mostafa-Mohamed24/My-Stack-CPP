#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack <int> Stack;

	Stack.push(10);
	Stack.push(20);
	Stack.push(30);
	Stack.push(40);
	Stack.push(50);


	cout << "\nStack : " << endl;
	Stack.Print();

	cout << "\n\nStack Size : " << Stack.Size();
	cout << "\nStack Top : " << Stack.Top();
	cout << "\nStack Bottom : " << Stack.Bottom();


	Stack.pop();

	cout << "\n\nStack after pop() : " << endl;
	Stack.Print();

	// Extension 1 
	cout << "\n\nItem(2) : " << Stack.GetItem(2);

	// Extension 2
	Stack.Reverse();
	cout << "\n\nStack After Reverse : \n";
	Stack.Print();

	// Extension 3 
	Stack.UpdateItem(2, 300);
	cout << "\n\nStack After Updating Item 2 : \n";
	Stack.Print();

	// Extension 4 
	Stack.InsertAfter(2, 400);
	cout << "\n\nStack After Insert After Item 2 : \n";
	Stack.Print();

	// Extension 5
	Stack.InsertAtFront(100);
	cout << "\n\nStack After Insert At Top :\n";
	Stack.Print();

	// Extension 6
	Stack.InsertAtBack(600);
	cout << "\n\nStack After Insert At Bottom : \n";
	Stack.Print();

	// Extension 7
	Stack.Clear();
	cout << "\n\nStack After Clear() : \n";
	Stack.Print();



	Stack.Print();

	system("pause>0");
	return  0;
}