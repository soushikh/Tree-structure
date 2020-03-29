#include "lab3_priority_queue.hpp"

using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	heap = new TaskItem*[n_capacity+1];
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
	for(int i = 1; i < n_capacity + 1; i++)
	{
		delete heap[i];
	}
	delete heap;
	heap = NULL;
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	return !size;
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	return (size == n_capacity);
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {
}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
	if(size == 0)
	return TaskItem(-1, "NULL");
	else
	return *heap[1];
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue( TaskItem val ) {
	return false;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {
	if(empty())
		return false();
	if(size == 1)
	{
		delete heap[n_capacity];
	}
	int i = 1;
	int child = 1;
	taskItem* storeVal;
	*heap[i] = *heap[n_capacity];
	delete heap[n_capacity];
	
	while( 2*i+1<n_capacity &&
		(heap[i]->priority < heap[2*i]->priority || heap[i]->priority < heap[2*i + 1]->priority))
	{
		if(heap[2*i]->priority > *heap[2*i+1]->priority)
			child = 2*i;
		else 
			child = 2*i+1;
		
		storeVal = heap[i];
		*heap[i] = *heap[child];
		*heap[child] = *storeVal;
		i = child;
	}		
	return true;
}
