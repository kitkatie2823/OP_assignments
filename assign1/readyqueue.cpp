#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  
{
     //TODO: add your code here
	capacity = 500;
	size_ = 0;
	front = 0;
	rear = -1;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() 
{
    //TODO: add your code to release dynamically allocate memory
}

void ReadyQueue::swap(int loc1, int loc2)
{
	int temp = heap[loc1];
	heap[loc1] = heap[loc2];
	heap[loc2] = temp;
}

/**
 * @brief Checks if the PCB is empty to return true, otherwise false
 *
 *
 */
bool ReadyQueue::isEmpty()
{
	if (size_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

   /**
     * @brief Checks if the PCB is full to return true, otherwise false
     *
     *
     */
bool ReadyQueue::isFull()
{
	if (size_ == capacity-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) 
{
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
	if (isFull())
	{
		return "Full";
	}
	else
	{
		heap[size_] = pcbPtr;
		heap[size_]->setState(ProcState::READY);
		size_++;
	}
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() 
{
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
	if (isEmpty())
	{
		return "Empty";
	}
	else
	{
		heap[size_] = pcbPtr;
                heap[size_]->setState(ProcState::RUNNING);
                size_++;
	}
}

/**
  @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() 
{
    //TODO: add your code here
	return size_;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() 
{
    //TODO: add your code here
	if (isEmpty())
	{
		cout << " EMPTY " << endl;
	}
	else
	{
		int j = front;
		for (int i = 1; i <= size_; i++)
		{
			cout << heap[i] << endl;
		}
	}
}
