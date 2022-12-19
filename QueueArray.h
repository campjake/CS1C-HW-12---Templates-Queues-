#include <string>
#include <iostream>
#include <limits>
#include <memory>
using namespace std;

template <typename T>
class QueueArray
{
	// template <typename U>
	// friend ostream& operator<<(ostream &osObj, const QueueArray<U>& listObj);
	// // Output relevant class attributes to the console
	// // Pre-conditions - listObj is an array of type T elements
	// // Post-conditions - Returns an ostream object to the calling function

	public : 

	/********************************
	 *  CONSTRUCTORS & DESTRUCTORS  *
	*********************************/
	/***************** RULE OF 5 (=default) ******************/
	// 1/5 - Default constructor
	QueueArray() = default;

	// 2/5 - Default Copy Constructor
	QueueArray(const QueueArray<T>& otherObject) = default;

	// 3/5 - Default Copy Assignment
	// QueueArray& operator=(const QueueArray& otherObject) = default;

	// 4/5 Default Move Constructor -- It is noexcept by default
	QueueArray(QueueArray<T>&& otherObject) = default;

	// 5/5 Default Move Assignment -- It is noexcept by default
	// QueueArray& operator=(QueueArray&& tempObj) = default;

	/****************** END DEFAULT RULE OF 5 ****************/

	// Overloaded constructor
	QueueArray(int max, int front, int rear);
	// Pre-conditions - List size - defaults to 5
	// Post-conditions - Creates a valid object

	// Overloaded Copy Constructor
	QueueArray(const QueueArray<T>& otherObject, int foo);
	// Pre-conditions - Another array and an integer
	// Post-conditions - Creates a deep copy of the other object

	// Overloaded Copy Assignment
	const QueueArray<T>& operator=(const QueueArray<T>& otherObject);
	// Pre-conditions - Another array and an integer
	// Post-conditions - Creates a deep copy of the other object

	// Overloaded Move Assignment
	QueueArray<T>& operator=(QueueArray<T>&& otherObject) noexcept;
	// Pre-conditions - Another array and an integer
	// Post-conditions - Moves data of other object into this object, leaving old obj in destructable state

	// Destructor - Performs no specific function because of smart ptrs
	~QueueArray() = default;

	// Copy
	void Copy(const QueueArray<T>& source);




	/********************************
	 *     Main Queue Operations    *
	*********************************/
	void Enqueue(const T& object);
	// Inserts an element at end of queue
	// Pre-conditions - T type object parameter must be defined
	// Post-conditions - None, enqueued in function and returns nothing

	T Dequeue();
	// Removes and returns the element at the front of the queue
	// Pre-conditions - NONE
	// Post-conditions - Returns type T object, use value to inform user of successful dequeue

	T Front() const;
	// Returns the element at the front
	// Pre-conditions - NONE
	// Post-conditions - NONE, but check for empty list in function and output a message if so

	int Size() const;
	// Returns number of elements stored
	// Pre-conditions - NONE
	// Post-conditions - Returns an int representing size of defined(?) elements in array

	bool IsEmpty() const;
	// Tells user if list is empty (true if empty, false if not empty)
	// Pre-conditions - NONE
	// Post-conditions - Returns a bool representing state of list

	bool IsFull() const;
	// Tells user if list is full (true if full, false if not full)
	// Pre-conditions - NONE
	// Post-conditions - Returns a bool representing the state of the list

	void PrintQueue() const;
	// Prints queue to the console
	// Pre-conditions - NONE
	// Post-conditions - NONE


	

	private :
	int maxSize;
	int queueFront;
	int queueRear;				// Index of the next space after currentSize
	int currentSize;			// Index of the last space of defined data
	unique_ptr<T[]> list;		// Use unique_ptr instead of raw ptr

};


// Ctor
template <typename T>
QueueArray<T>::QueueArray(int max, int front, int rear)
	: maxSize{max}, queueFront{front}, queueRear{rear}, currentSize{0}
{
	list = make_unique<T[]>(maxSize);
}

// Copy
template <typename T>
void QueueArray<T>::Copy(const QueueArray<T>& source)
{
	for(int i = 0; i < source.currentSize; i++)
	{
		list[i] = source[i];
	}
}

// Copy Ctor
template <typename T>
QueueArray<T>::QueueArray(const QueueArray<T>& otherObject, int foo)
	: maxSize{otherObject.maxSize}, queueFront{otherObject.queueFront},
		queueRear{otherObject.queueRear}, currentSize{otherObject.currentSize}
{
	list = make_unique<T[]>(otherObject.maxSize);
	Copy(otherObject);
}

// Copy Assignment
template <typename T>
const QueueArray<T>& QueueArray<T>::operator=(const QueueArray<T>& otherObject)
{
	if (this != &otherObject)
	{
		Copy(otherObject);
	}

	list.reset();
	list = make_unique<T[]>(maxSize);

	return *this;
}

// Move Assignment
template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& otherObject) noexcept
{
	maxSize = std::move(otherObject.maxSize);
	queueFront = std::move(otherObject.queueFront);
	queueRear = std::move(otherObject.queueRear);
	currentSize = std::move(otherObject.currentSize);
	// use unique_ptr move assignment operator
	list = make_unique<T[]>(otherObject.list);

	// 1) Transfers ownership from otherObject to *thi
	// 2) Similar to using reset()
}

// Check if Queue is Empty
template <typename T>
bool QueueArray<T>::IsEmpty() const
{
	bool empty;

	if(currentSize == 0)
	{
		empty = true;
	}
	else
	{
		empty = false;
	}

	return empty;
}

// Check if queue is full
template <typename T>
bool QueueArray<T>::IsFull() const
{
	bool full;

	if(maxSize == queueRear)
	{
		full = true;
	}
	else
	{
		full = false;
	}

	return full;
}

// Get size of queue
template <typename T>
int QueueArray<T>::Size() const
{
	return currentSize;
}

template <typename T>
T QueueArray<T>::Front() const
{
	return list[queueFront];
}
template <typename T>
void QueueArray<T>::Enqueue(const T& object)
{
	if(!IsFull())
	{
			if(currentSize == 0)
			{
				list[currentSize] = object;
			}
			else
			{
				list[queueRear] = object;
				queueRear++;
			}
		cout << "\nElement was succesfully added.\n\n";
		currentSize++;		
	}
	else
	{
		cout << "Sorry, the queue is full\n\n";
	}
}

template <typename T>
T QueueArray<T>::Dequeue()
{
	T tempObj;
	
	if(IsEmpty())
	{
		cout << "ERROR - Cannot dequeue from an empty list.\n\n";
		tempObj = -999;

	}
	else
	{
		tempObj = list[0];

		for(int i = 0; i < currentSize; i++)
		{
			list[i] = list[i + 1];
		}
		if(queueRear > 1)
		{
			queueRear--;
		}
		if(currentSize > 0)
		{
			currentSize--;
		}

	}

	return tempObj;

}


template <typename T>
void QueueArray<T>::PrintQueue() const
{
	cout << left;
	if(IsEmpty())
	{
		cout << "This list is empty, so nothing was printed.\n\n";
	}
	else
	{
		cout << "Printing the list...\n";
		for(int i = 0; i < queueRear; i++)
		{
			cout << "Index #" << i + 1 << ": ";
			cout << list[i] << endl;
		}

		if(IsFull())
		{			
			cout << "This list is currently full at " << maxSize;
			if(maxSize == 1)
			{
				cout << " element.\n\n";
			}
			else
			{
				cout << " elements.\n\n";
			}
		}
		else
		{
			cout << "This list has " << currentSize;
			if(currentSize == 1)
			{
				cout << " element\n";
				
			}
			else
			{
				cout << " elements\n";
			}
			
			cout << "There is/are " << maxSize - currentSize
				<< " space(s) left for further enqueues\n\n";
		}

	}

	cout << right;
}

// template <typename U>
// ostream& operator<<(ostream &osObj, const QueueArray<U>& listObj)
// {
// 	// const int COL_WIDTH = 10;

// 	osObj << left;
	
// 	if(QueueArray<U>::listObj.IsEmpty())
// 	{
// 		osObj << "This list is empty, so nothing was printed.\n\n";
// 	}
// 	else
// 	{
// 		osObj << "Printing the list...\n";
// 			for(int i = 0; i < QueueArray<U>::listObj.queueRear; i++)
// 			{
// 				osObj << "Index #" << i + 1 << ": ";
// 				osObj << QueueArray<U>::listObj.list[i] << endl;
// 			}

// 			if(QueueArray<U>::listObj.IsFull())
// 			{			
// 				osObj << "This list is currently full at " << QueueArray<U>::listObj.maxSize
// 					<< " elements.\n\n";
// 			}
// 			else
// 			{
// 				osObj << "This list has " << QueueArray<U>::listObj.currentSize << " elements\n";
// 				osObj << "There are " << QueueArray<U>::listObj.maxSize - QueueArray<U>::listObj.currentSize
// 					  << " spaces left for further enqueues\n\n";
// 			}
// 	}

// 	osObj << right;

// 	return osObj;
// }