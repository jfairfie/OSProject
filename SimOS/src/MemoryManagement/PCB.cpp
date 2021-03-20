/*
 * PCB.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include "PCB.h"
#include <iostream>


PCB::~PCB() {
	delete head;
}

void PCB::insertElements(int index, int cpuid, int status, int priority, int codeSize) {
	pcb *tempPCB = new pcb;
	tempPCB->index = index;
	tempPCB->cpuid = cpuid;
	tempPCB->status = status;
	tempPCB->priority = priority;
	tempPCB->codeSize = codeSize;
	tempPCB->next = NULL;

	pcb *last;
	last = head;

	if (last == NULL) {
		head = tempPCB;
	} else {
		while(last->next != NULL) {
			last = last->next;
		}
		last->next = tempPCB;
	}
}

void PCB::printList() {
	pcb* temp = head;
	while (temp != NULL) {
		std::cout << temp->index << " " << temp->priority <<  " " << temp->codeSize << std::endl;
		temp = temp->next;
	}
}
