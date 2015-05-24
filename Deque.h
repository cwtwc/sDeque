#include <iostream>
#include <string>
using namespace std;

class Deque{
private:
	// Private data to implement the deque
	int cap, qSize;
	std::string *q, remove, *q2;
	
public:
	// Constructor
	Deque()
	{
		cap = 8;								// Initial/minimum size queue
		q = new std::string[cap];				// Array of the queue
	}

	// Destructor
	~Deque()
	{
		delete[] q;
	}

	// Inserts the element at the front of the queue.
	void push_front(std::string item)
	{
		for (int i = qSize - 1; i >= 0; --i)	// Items move over to the right to make space for item
		{
			q[i + 1] = q[i];
		}
		q[0] = item;							// An item is inserted at the front of the queue
		++qSize;								// Increment element amount in queue
		modifySize();							// Automatically doubles or halves depending if queue is full
	}											// or less than 1 / 4 full and not already of minimum size

	// Inserts the element at the back of the queue
	void push_back(std::string item)
	{
		q[qSize] = item;						// Insert element at back of queue
		++qSize;								// Increment element amount in queue
		modifySize();							// Automatically doubles or halves depending if queue is full 
	}											// or less than 1 / 4 full and not already of minimum size 

	// Removes and returns the element at the front of the queue.
	std::string pop_front()
	{
		if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
		{
			// std::cout << "Error: Queue is empty." << std::endl;
			return "";
		}
		else									// Otherwise, remove item from the front of the queue 
		{
			remove = q[0];
			--qSize;							// Decrease element amount in queue
			for (int i = 0; i < qSize; ++i)	// Items move over to the left
			{
				q[i] = q[i + 1];
			}
			return remove; 						// Return
			modifySize();						// Automatically doubles or halves depending if queue is full 
		}										// or less than 1 / 4 full and not already of minimum size 
	}

	// Removes and returns the element at the back of the queue.
	std::string pop_back()
	{
		if (empty())							// If element == 0, then return Error; items cannot be removed from an empty queue
		{
			// std::cout << "Error: Queue is empty." << std::endl;
			return "";
		}
		else									// Otherwise, remove item from the back of the queue 
		{
			remove = q[qSize - 1];
			--qSize; 							// Decrease element amount in queue
			return remove;						// Return
			modifySize();						// Automatically doubles or halves depending if queue is full 
		}										// or less than 1 / 4 full and not already of minimum size 
	}

	// Returns the size of the queue.
	int size()
	{
		return cap;
	}

	// Tells whether the queue is empty or not.
	bool empty()
	{
		if (qSize == 0)						// If empty, return true		
		{
			return true;
		}
		else									// Otherwise, return false
		{
			return false;
		}
	}

	// Either doubles or halves container size
	void modifySize(void)
	{
		if (qSize == cap)						// Check if queue is full
		{
			q2 = new std::string[cap * 2];		// The queue doubles in size when it is full
			cap = cap * 2; 						// New capacity is doubled
			for (int i = 0; i < qSize; ++i)	// Iterate so that values in q are acquired by q2
			{
				q2[i] = q[i];
			}
			q = q2; 							// Rename for output
		}										// Check if queue is less than 1/4 full and not already of minimum size
		else if ((qSize < (cap / 4)) && (cap > 8))
		{
			q2 = new std::string[cap / 2];		// The queue becomes half its size
			cap = cap / 2; 						// New capacity is halved
			for (int i = 0; i < qSize; ++i)	// Iterate so that values in q are acquired by q2
			{
				q2[i] = q[i];
			}
			q = q2;								// Rename for output
		}
	}

	/* Prints the contents of the queue from front to back
	* to stdout with one string per line followed by a blank line
	*/
	std::string toStr()
	{
		for (int i = 0; i < qSize; i++)		// Print array of queue followed by new line
		{
			std::cout << q[i] << std::endl;
		}
		return "";								// Return
	}
};
