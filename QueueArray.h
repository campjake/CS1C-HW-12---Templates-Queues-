#include <string>
#include <iostream>
#include <limits>
using namespace std;

template <typename T>
class QueueArray
{
	public : 

	friend ostream& operator<<(ostream &osObj, const QueueArray& listObj);
	// Output relevant class attributes to the console
	// Pre-conditions - listObj is an array of type T elements
	// Post-conditions - Returns an ostream object to the calling function

	/********************************
	 *  CONSTRUCTORS & DESTRUCTORS  *
	*********************************/
	/***************** RULE OF 5 (=default) ******************/
	// 1/5 - Default constructor
	QueueArray() = default;

	// 2/5 - Default Copy Constructor
	QueueArray(const QueueArray& otherObject) = default;

	// 3/5 - Default Copy Assignment
	// QueueArray& operator=(const QueueArray& otherObject) = default;

	// 4/5 Default Move Constructor -- It is noexcept by default
	QueueArray(QueueArray&& otherObject) = default;

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


	

	private :
	int maxSize;
	int queueFront;
	int queueRear;				// Index of the next space after currentSize
	int currentSize;			// Index of the last space of defined data
	unique_ptr<T[]> list;		// Use unique_ptr instead of raw ptr

};