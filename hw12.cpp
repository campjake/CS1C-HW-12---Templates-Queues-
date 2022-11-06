#include "QueueArray.h"

int main()
{
	QueueArray<int> inAr(5, 0, 1);
	int poppedElem;

	// Test 1) Fill the list
	cout << "An Array-based Queue of integers has been created.\n";

	cout << "Now testing the Enqueue function\n\n";
	
	for(int i = 0; i < 5; i++)
	{
		inAr.Enqueue(2);

		inAr.PrintQueue();
	}

	// Test 1) Add to a full queue
	inAr.Enqueue(8);

	// Test 1) Empty queue
	for(int i = 0; i < 5; i++)
	{
		poppedElem = inAr.Dequeue();
		cout << poppedElem << " was dequeued from the list\n\n";

		inAr.PrintQueue();
	}
	cout << endl;

	// Test 1) Remove from an empty queue
	inAr.Dequeue();

	// Test 2) Test IsEmpty and IsFull
	for(int i = 0; i < 6; i++)
	{
		
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

		inAr.PrintQueue();
		inAr.Enqueue(i);
	}

	// Test Front()
	poppedElem = inAr.Front();
	cout << poppedElem << " is at the front\n\n";
	inAr.PrintQueue();

	cout << "The integer queue was successful... now moving to another data type\n\n";



	QueueArray<double> dbAr(5, 0, 1);
	double poppedElem2;

	// Test 1) Fill the list
	cout << "An Array-based Queue of doubles has been created.\n";

	cout << "Now testing the Enqueue function\n\n";
	
	for(int i = 0; i < 5; i++)
	{
		dbAr.Enqueue(1.11);

		dbAr.PrintQueue();
	}

	// Test 1) Add to a full queue
	dbAr.Enqueue(8.5);

	// Test 1) Empty queue
	for(int i = 0; i < 5; i++)
	{
		poppedElem2 = dbAr.Dequeue();
		cout << poppedElem2 << " was dequeued from the list\n\n";

		dbAr.PrintQueue();
	}
	cout << endl;

	// Test 1) Remove from an empty queue
	dbAr.Dequeue();

	// Test 2) Test IsEmpty and IsFull
	for(int i = 0; i < 6; i++)
	{
		
		if(dbAr.IsEmpty())
		{
			cout << "It's empty!!!!\n\n";
		}
		else
		{
			cout << "It's not empty\n\n";
		}

		if(dbAr.IsFull())
		{
			cout << "It's full!!!!\n\n";
		}
		else
		{
			cout << "It's not full\n\n";
		}

		dbAr.PrintQueue();
		dbAr.Enqueue(i + .01);
	}

	// Test Front()
	poppedElem2 = dbAr.Front();
	cout << poppedElem2 << " is at the front\n\n";
	dbAr.PrintQueue();

	cout << "The doubles queue was successful... now moving to another data type\n\n";



	QueueArray<string> strAr(5, 0, 1);
	string name = "jake";
	string poppedElem3;

	// Test 1) Fill the list
	cout << "An Array-based Queue of strings has been created.\n";

	cout << "Now testing the Enqueue function\n\n";
	
	for(int i = 0; i < 5; i++)
	{
		strAr.Enqueue(name);

		strAr.PrintQueue();
	}

	// Test 1) Add to a full queue
	strAr.Enqueue(name);

	// Test 1) Empty queue
	for(int i = 0; i < 5; i++)
	{
		poppedElem3 = strAr.Dequeue();
		cout << poppedElem3 << " was dequeued from the list\n\n";

		strAr.PrintQueue();
	}
	cout << endl;

	// Test 1) Remove from an empty queue
	strAr.Dequeue();

	// Test 2) Test IsEmpty and IsFull
	for(int i = 0; i < 6; i++)
	{
		
		if(strAr.IsEmpty())
		{
			cout << "It's empty!!!!\n\n";
		}
		else
		{
			cout << "It's not empty\n\n";
		}

		if(strAr.IsFull())
		{
			cout << "It's full!!!!\n\n";
		}
		else
		{
			cout << "It's not full\n\n";
		}
		strAr.PrintQueue();
		strAr.Enqueue(name);
	}

	// Test Front()
	poppedElem3 = strAr.Front();
	cout << poppedElem3 << " is at the front\n\n";
	strAr.PrintQueue();

	cout << "String queue was successful! Goodbye \n\n";

	return 0;
}