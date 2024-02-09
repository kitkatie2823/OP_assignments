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
	capacity = 500;
	size_ = 0;
	heap = new PCB*[capacity];
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() 
{
	delete[] heap;
	size_ = 0;
	capacity = 100;
}

/**
 * @brief Swap two different heap objects
 *
 * @param heap1 and heap2 are two PCB objects to swap with each other
 */
void ReadyQueue::swap(PCB* &heap1, PCB* heap2)
{
	PCb* temp = heap1;
	heap1 = heap2;
	heap2 = temp;
}

/**
 * @brief copy constructor
 *
 * @param heap1 and heap2 are two PCB objects to swap with each other
 */
ReadyQueue::ReadyQueue(const ReadyQueue& rq)
{
	capacity = rq.capacity;
	size_ = rq.size_;
	heap = new PCB*[rq];
	for(int i = 0; i < size_; i++)
	{
		heap[i] = new PCB(*(rq.heap[i]));
	}
}

/**
 *@brief operator= checks if PCB objects are the same
*/
ReadyQueue& ReadyQueue::operator=(const ReadyQueue& rq)
{
	if(this == &object)
	{
		return *this;
	}
	
	delete[] heap;
	capacity = rq.capacity;
	size_ = rq.size_;
	heap = new PCb*[capacity];
	
	for (int i = 0; i < size_; i++)
	{
		heap[i] = new PCB(*(rq.heap[i]));
	}

	return *this;
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
 *@brief Swapping current pointer and recursively call trickleUp() in order to find the farIndex
 *
 * @param the current i to find the farIndex
*/
void ReadyQueue::trickleUp(int i)
	{
		int farIndex = (i - 1) / 2;
		if (i <= 0)
		{
			return;
		}
		if (heap[i]->getPriority() > heap[farIndex]->getPriority())
		{
			swap(heap[i], heap[farIndex]);
			trickleUp(farIndex);
		}
	}

/**
 *@brief Swapping current pointer and recursively call trickleDown() in order to find biggest
 *
 * @param the current i to find the bigi or the biggest index
*/
void ReadyQueue::trickleDown(int i)
{
	int leftChild = 2 * i+1;
	int rightChild = 2 * i+2;
	int bigi = i;

	if (leftChild < size_ && heap[leftChild]->getPriority() > heap[bigi]->getPriority())
	{
		bigi = leftChild;
	}

	if (rightChild < size_ && heap[rightChild]->getPriority() > heap[bigi]->getPriority())
	{
		bigi = rightChild;
	}

	if (i != bigi)
	{
		swap(heap[i], heap[bigi]);
		trickleDown(bigi);
	}
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) 
{
    // When adding a PCB to the queue, you must change its state to READY.
	if (isFull())
	{
		cout << "Maximum capacity has been reached\n";
		return;
	}
	else
	{
		heap[size_] = pcbPtr;
		heap[size_]->setState(ProcState::READY);
		trickleUp(size_);
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
    // When removing a PCB from the queue, you must change its state to RUNNING.
	PCB* pcbReturn;
	if (isEmpty())
	{
		cout << "Empty\n";
		return 0;
	}
	else
	{
		heap[0]->setState(ProcState::RUNNING);
		pcbReturn = heap[0];

		if (size_ == 1)
		{
			heap[0] = nullptr;
			size_ = 0;
			return pcbReturn;
		}
		else
		{
			heap[0] = heap[size_-1];
			size_--;
			return pcbReturn;
		}
	}
}

/**
  @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() 
{
	return size_;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() 
{
	if (isEmpty())
	{
		cout << "Displaying  Processes in ReadyQueue:\n EMPTY";
	}
	else
	{
		cout << "Displaying Processes in ReadyQueue:\n";
		for (int i = 0; i < size_; i++)
		{
			heap[i]->display();
		}
		cout << endl;
	}
}
