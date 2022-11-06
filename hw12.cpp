#include "QueueArray.h"

int main()
{
	QueueArray<int> inAr(5, 0, 1);
	int poppedElem;

	// Test 1) Fill the list
	for(int i = 0; i < 6; i++)
	{
		inAr.Enqueue(2);

		cout << inAr;
	}

	// Test 1) Add to a full queue
	inAr.Enqueue(8);

	// Test 1) Empty queue
	for(int i = 0; i < 6; i++)
	{
		poppedElem = inAr.Dequeue();
		cout << poppedElem << " was dequeued from the list\n\n";

		cout << inAr;
	}
	cout << endl;

	// Test 1) Remove from an empty queue
	inAr.Dequeue();

	// Test 2) Test IsEmpty and IsFull
	for(int i = 0; i < 6; i++)
	{
		inAr.Enqueue(i);
		
		if(inAr.IsEmpty())
		{
			cout << "It's empty!!!!\n\n";
		}
		else
		{
			cout << "It's not empty\n\n";
		}

		if(inAr.IsFull())
		{
			cout << "It's full!!!!\n\n";
		}
		else
		{
			cout << "It's not full\n\n";
		}

		cout << inAr;
	}

	// Test Front()
	poppedElem = inAr.Front();
	cout << poppedElem << " is at the front\n\n";
	cout << inAr;







	return 0;
}