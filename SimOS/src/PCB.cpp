/*
 * PCB.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include "PCB.h"
#include <iostream>


void PCB::insertElements(int index, int cpuid, int status, int priority, int codeSize) {
	pcb *tempPCB = new pcb;
	tempPCB->index = index;
	tempPCB->cpuid = cpuid;
	tempPCB->status = status;
	tempPCB->priority = priority;
	tempPCB->codeSize = codeSize;

	if (head == NULL) {
		head = tempPCB;
	} else {
		pcb* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = tempPCB;
	}
}

void PCB::printList() {
	pcb* temp = head;
	while (temp != NULL) {
		std::cout << temp->index << " " << std::endl;
		temp = temp->next;
	}
}
