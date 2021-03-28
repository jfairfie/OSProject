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

void PCB::insertElements(int pID, int cpuid, int priority, int codeSize, int inputBuffer, int outputBuffer, int temporaryBuffer) {
	pcb *tempPCB = new pcb;
	tempPCB->pID = pID;
	tempPCB->cpuid = cpuid;
	tempPCB->status = tempPCB->New;
	tempPCB->priority = priority;
	tempPCB->codeSize = codeSize;
	tempPCB->programCounter = "";
	tempPCB->inputBuffer = inputBuffer;
	tempPCB->outputBuffer = outputBuffer;
	tempPCB->temporaryBuffer = temporaryBuffer;
	tempPCB->baseRegister = -1;
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

void PCB::insertElements(pcb *node) {
	pcb *last = head;

	if (last == NULL) {
		head = node;
		head->next = NULL;
	} else {
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = node;
	}
}

void PCB::printList() {
	pcb* temp = head;
	while (temp != NULL) {
		std::cout << temp->pID << " " << temp->priority << " " << temp->baseRegister << std::endl;
		temp = temp->next;
	}
}

void PCB::printTables() {
	pcb* temp = head;
	while (temp != NULL) {
		temp->table.printTable();
		temp = temp->next;
	}
}

pcb* PCB::returnHighestPriority() {
	pcb *last = head;
	pcb *ret = last;
	int priority = last->priority;
	last = last->next;

	while (last != NULL) {
		if (priority > last->priority) {
			priority = last->priority;
			ret = last;
		}
		last = last->next;
	}


	deleteNode(ret);
	ret->next = NULL;
	return ret;
}

pcb* PCB::pop() {
	pcb* ret = head;
	deleteNode(ret);
	ret->next = NULL;
	return ret;
}

int PCB::getSize() {
	pcb *last = head;
	int size = 0;

	while (last != NULL) {
		size++;
		last = last->next;
	}

	return size;
}

void PCB::deleteNode(pcb *node) {
	pcb *last = head;

	if (last == node) {
		head = last->next;
		return;
	}

	while (last != NULL) {
		if (last->next == node) {
			last->next = last->next->next;
		}
		last = last->next;
	}
}

void PCB::getJobIndex() {
	pcb *last = head;
	int offset = 0;

	while (last->next != NULL) {
		offset += last->codeSize + last->inputBuffer + last->outputBuffer + last->temporaryBuffer;
		last = last->next;
	}
	last->jobIndex = offset;
}

int PCB::returnLoadSize() {
	return head->codeSize + head->inputBuffer + head->outputBuffer + head->temporaryBuffer;
}
