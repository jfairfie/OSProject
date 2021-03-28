/*
 * PCB.h
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#ifndef SRC_PCB_H_
#define SRC_PCB_H_
#include <string>
#include "PageTable.h"

struct pcb {
	int pID;
	int cpuid;
	enum STATES {New=0, Ready=1, Run=2, Wait=3, Terminate=4}; //0 new, 1 ready, 2 running, 3 waiting
	int status;
	int priority;
	int codeSize;
	int inputBuffer;
	int outputBuffer;
	int temporaryBuffer;
	int jobIndex;
	int baseRegister;
	PageTable table;
	std::string programCounter;
	pcb *next;
};

class PCB {
	public:
		PCB() {head = NULL;}
		~PCB();
		void insertElements(int pID, int cpuid, int priority, int codeSize, int inputBuffer, int outputBuffer, int temporaryBuffer);
		void insertElements(pcb *node);
		pcb* returnHighestPriority();
		pcb* pop(); //Pops first index
		void printList();
		void printTables();
		int getSize();
		void getJobIndex();
		void setBaseRegister(int baseRegister);
		int returnLoadSize(); //Returns load size of head
	private:
		pcb *head;
		void deleteNode(pcb *node);
};

#endif /* SRC_PCB_H_ */
