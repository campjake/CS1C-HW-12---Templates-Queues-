#include "QueueArray.h"

// Ctor
template <typename T>
QueueArray<T>::QueueArray(int max, int front, int rear)
	: maxSize{max}, queueFront{front}, queueRear{rear}, currentSize{0}
{
	list = make_unique<T[]>(maxQueueSize);
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
		cout << "Enter a new element: ";

		if constexpr (std::is_same_v<T, std::string>)
		{
			if(currentSize == 0)
			{
				std::getline(cin, list[queueFront]);
			}
			else
			{
				std::getline(cin, list[queueRear++]);
			}
			
		}
		else
		{
			if(currentSize == 0)
			{
				cin >> list[queueFront];
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				cin >> list[queueRear++];
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
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
	if(IsEmpty())
	{
		cout << "ERROR - Cannot dequeue from an empty list.\n\n";
	}
	else
	{
		T tempObj = list[0];

		for(int i = 0; i < currentSize; i++)
		{
			list[i] = list[i + 1];
		}

		queueRear--;
		currentSize--;
	}

	return tempObj;
}

template <typename T>
ostream& operator<<(ostream &osObj, const QueueArray<T>& listObj)
{
	const int COL_WIDTH = 10;

	osObj << left;
	
	if(listObj.IsEmpty)
	{
		osObj << "This list is empty, so nothing was printed.\n\n";
	}
	else
	{
		osObj << "Printing the list...\n"
			for(int i = 0; i < listObj.queueRear; i++)
			{
				osObj << "Index #" << i + 1 << ": ";
				osObj << listObj.list[i] << endl;
			}

			if(listObj.IsFull())
			{			
				osObj << "This list is currently full at " << listObj.maxSize
					<< " elements.\n\n";
			}
			else
			{
				osObj << "This list has " << listObj.currentSize << " elements\n";
				osObj << "There are " << listObj.maxSize - listObj.currentSize
					  << " spaces left for further enqueues\n\n";
			}
	}

	osObj << right;

	return osObj;
}