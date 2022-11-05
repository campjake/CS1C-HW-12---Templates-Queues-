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
const QueueArray<T>& QueueArray<T>::operator=(const QueueArray<T>& otherObject, int foo)
{
	if (this != &otherObject)
	{
		Copy(otherObject);
	}

	return *this;
}

// Move Assignment
template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& otherObject, int foo) noexcept
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
void QueueArray<T>::Enqueue(T object)
{
	if(!IsEmpty())
	{
		cout << "Enter a new element: ";

		if constexpr (std::is_same_v<T, std::string>)
		{
			std::getline(cin, list[++queueRear]);
		}
		else
		{
			cin >> list[++queueRear];
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		if(currentSize < maxSize)
		{
			// do some dequeue stuff here
		}
	}
}