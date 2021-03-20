/*
 * PCB.h
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#ifndef SRC_PCB_H_
#define SRC_PCB_H_
#include <string>

struct pcb {
	int index;
	int cpuid;
	int status; //0 running, 1 ready, 2 blocked, 3 new
	int priority;
	int codeSize;
	pcb *next;
};

class PCB {
	public:
		PCB() {head = NULL;}
		~PCB();
		void insertElements(int index, int cpuid, int status, int priority, int codeSize);
		void printList();

	private:
		pcb *head;
};

#endif /* SRC_PCB_H_ */
