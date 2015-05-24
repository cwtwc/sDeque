/*#include "tDeque.h"

// Constructor
template <class T>
Deque<T>::Deque()
{
	cap = 8;								// Initial/minimum size queue
	q = new T[cap];				// Array of the queue
}

// Destructor
template <class T>
Deque<T>::~Deque()
{
	delete[] q;
}

// Inserts an element at the front of the queue 
template <class T>
void Deque<T>::push_front(T item)
{
	for (int i = size() - 1; i >= 0; --i)	// Items move over to the right to make space for item
	{
		q[i + 1] = q[i];
	}
	q[0] = item;							// An item is inserted at the front of the queue
	++qSize;								// Increment element amount in queue
	modifySize();							// Automatically doubles or halves depending if queue is full
}											// or less than 1 / 4 full and not already of minimum size

// Inserts an element at the back of the queue 
template <class T>
void Deque<T>::push_back(T item)
{
	q[size()] = item;						// Insert element at back of queue
	++qSize;								// Increment element amount in queue
	modifySize();							// Automatically doubles or halves depending if queue is full 
}											// or less than 1 / 4 full and not already of minimum size 

// Removes the element at the front of the queue 
template <class T>
T Deque<T>::pop_front()
{
	if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
	{
		// std::cout << "Error: Queue is empty." << std::endl;
		return "Error";
	}
	else									// Otherwise, remove item from the front of the queue 
	{
		remove = q[0];
		--qSize;							// Decrease element amount in queue
		for (int i = 0; i < size(); ++i)	// Items move over to the left
		{
			q[i] = q[i + 1];
		}
		return remove; 						// Return
		modifySize();						// Automatically doubles or halves depending if queue is full 
	}										// or less than 1 / 4 full and not already of minimum size 
}

// Removes the element at the back of the queue 
template <class T>
T Deque<T>::pop_back()
{
	if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
	{
		// std::cout << "Error: Queue is empty." << std::endl;
		return "Error";
	}
	else									// Otherwise, remove item from the back of the queue 
	{
		remove = q[size() - 1]; 			
		--qSize; 							// Decrease element amount in queue
		return remove;						// Return
		modifySize();						// Automatically doubles or halves depending if queue is full 
	}										// or less than 1 / 4 full and not already of minimum size 
}

// Returns the size of the queue
template <class T>
int Deque<T>::size()
{
	return qSize;
}

// Checks to see if the queue is empty 
template <class T>
bool Deque<T>::empty()
{
	if (size() == 0)						// If empty, return true		
	{
		return true;
	}
	else									// Otherwise, return false
	{
		return false;
	}
}

// Checks capacity after each push/pop, then automatically doubles or halves the queue given certain conditions
template <class T>
void Deque<T>::modifySize(void)
{
	if (size() == cap)						// Check if queue is full
	{
		q2 = new T[cap * 2];		// The queue doubles in size when it is full
		cap = cap * 2; 						// New capacity is doubled
		for (int i = 0; i < size(); ++i)	// Iterate so that values in q are acquired by q2
		{
			q2[i] = q[i];
		}
		q = q2; 							// Rename for output
	}										// Check if queue is less than 1/4 full and not already of minimum size
	else if ((size() < (cap / 4)) && (cap > 8))
	{
		q2 = new T[cap / 2];		// The queue becomes half its size
		cap = cap / 2; 						// New capacity is halved
		for (int i = 0; i < size(); ++i)	// Iterate so that values in q are acquired by q2
		{
			q2[i] = q[i];
		}
		q = q2;								// Rename for output
	}
}

// Prints the contents of the queue
template <class T>
std::string Deque<T>::toStr()
{
	std::cout << "Queue size: " << size() << std::endl;
	std::cout << "Queue capacity: " << cap << std::endl;
	for (int i = 0; i < size(); i++)		// Print array of queue followed by new line
	{
		std::cout << q[i] << std::endl;
	}
	return "";								// Return
}*/
