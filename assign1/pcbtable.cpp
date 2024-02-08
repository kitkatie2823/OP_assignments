/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Katie Trinh
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
	for(int i = 0; i < size; i++)
	{
		pcbArray.resize(size,NULL);
	}
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   // Delete all the PCBs in the table
	for(PCB* pcb_pointer : pcb)
	{
		if (pcb_pointer != nullptr)
		delete pcb_pointer;
	}
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
	if (idx < pcbArray.size())
	{
		return pcbArray[idx];
	}
	else
	{
		return NULL;
	}
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    // Add a PCB pointer to the PCBTable at index idx.
	if (idx >= pcbArray.size())
	{
		this->pcbArray.resize(idx + 1, NULL);
	}
	pcbArray[idx] = pcb;
}
