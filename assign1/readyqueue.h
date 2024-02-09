/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author Cherishma Jalaparti and Katie Trinh
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code
#pragma once

#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */
class ReadyQueue {
private:
    // choose a data structure for the ReadyQueue. No STL class is allowed.
	PCB** heap;
	int capacity;
	int size_;
public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue();

    /**
     * @brief Destructor
     */
    ~ReadyQueue();

	// You may add additional member functions, but don't change the definitions of the following four member functions.

	ReadyQueue(const ReadyQueue& rq);
	
    /**
    *@brief operator= checks if PCB objects are the same
    */
	ReadyQueue& operator=(const ReadyQueue& rq);   

   /**
     * @brief Checks if the PCB is empty to return true, otherwise false
     *
     *
     */
	bool isEmpty();

   /**  
     * @brief Checks if the PCB is full to return true, otherwise false
     *
     *
     */
	bool isFull();

    /**
    *@brief Swapping current pointer and recursively call trickleDown() in order to find biggest
    *
    * @param the current i to find the bigi or the biggest index
    */
	void trickleDown(int i);

    /**
    *@brief Swapping current pointer and recursively call trickleUp() in order to find the farIndex
    *
    * @param the current i to find the farIndex
    */
	void trickleUp(int i);

    /**
    * @brief Swap two different heap objects
    *
    * @param heap1 and heap2 are two PCB objects to swap with each other
    */
	void swap(PCB* &heap1, PCB* &heap2);

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
	void addPCB(PCB* pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
	PCB* removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
	int size();

     /**
      * @brief Display the PCBs in the queue.
      */
	void displayAll();

};
