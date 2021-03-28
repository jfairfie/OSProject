/*
 * Driver.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include "Driver.h"

using namespace std;

void Driver::RUN() {
	Disk disk;
	RAM ram;
	PCB pcbList;
	PCB readyList; //Ready Queue
	PCB sortedList;
	SupportPrograms support;

	cout << "...Loading Data Into Disk..." << endl;

	//Loader, loads data from Datafile.txt into Disk and PCB
	Loader(disk, pcbList);

	//Sorting list into priority first

//FIFO loading
//	string data = disk.returnIndex(0);
	cout << "...Scheduling Processes..." << endl;
	LTSchedule(disk, pcbList, readyList, ram);


//Priority loading
//	while (pcbList.getSize() > 0) {
//		tempPcb = pcbList.returnHighestPriority();
//		sortedList.insertElements(tempPcb);
//	}
//	pcbList = sortedList;
//

	//Loop

	//Scheduler
	//Dispatcher
	//CPU
	//WaitforInterrupt

	//Endloop

}

//Loader loads information from file into disk
//Filename is DataFile
void Driver::Loader(Disk &disk, PCB &pcbList) {
	freopen("DataFile.txt", "rb", stdin);
	SupportPrograms support;
	string command;
	vector <string> jobTokens;
	vector <string> dataTokens;

	while (getline(cin, command)) {
		//Inserting instructions
		if (command[0] != '/') {
			disk.insertNextIndex(command.substr(2));
		}
		/* Else insert attributes into PCB */
		else if (command[3] == 'J') {
			string job = command.substr(7);
			tokenize(job, jobTokens);

		} else if (command[3] == 'D') {
			string job = command.substr(8);
			tokenize(job, dataTokens);

			int index = support.hexToDecimal(jobTokens[0]);
			int cpuid = 1;
			int priority = support.hexToDecimal(jobTokens[2]);
			int codeSize = support.hexToDecimal(jobTokens[1]);
			int inputBuffer = support.hexToDecimal(dataTokens[0]);
			int outputBuffer = support.hexToDecimal(dataTokens[1]);
			int temporaryBuffer = support.hexToDecimal(dataTokens[2]);

			pcbList.insertElements(index, cpuid, priority, codeSize, inputBuffer, outputBuffer, temporaryBuffer);
			pcbList.getJobIndex();
			jobTokens.clear();
			dataTokens.clear();
		}
	}

	cout << "LOAD SUCCESS" << endl;
}


void Driver::tokenize(string job, vector<string> &tokens) {
	string word = "";
	for (int i = 0; i < 3; i++) {
		int index = job.find(' ');

		if (index == -1) {
			word = job;
			int j = word.length() - 1;
			while (isalnum(word[j]) == 0) {
				j--;
			}
			word = word.substr(0, j+1);
			tokens.push_back(word);
		} else {
			tokens.push_back(job.substr(0, index));
		}

		job = job.substr(index + 1);
	}
}

void Driver::LTSchedule(Disk disk, PCB &pcbList, PCB &readyQueue, RAM &ram) {
	while (true) {
		float loadSize = pcbList.returnLoadSize(); //Gets length of first job
		int load = ceil(loadSize / 64);

		if (ram.enoughSpace(load) == true) {
			pcb* head = pcbList.pop();
			PageTable table;
			int diskIndex = head->jobIndex;
			int frameNum;
			int count = 0;

			//Loading information into RAM
			while (count < load) {
				frameNum = ram.getNextEmpty();
				int index = 0;

				if (head->baseRegister == -1) {
					head->baseRegister = frameNum * 64;
				}

				while (index < loadSize && index < FRAME_SIZE) {
					ram.insert(frameNum, index, disk.returnIndex(diskIndex));
					diskIndex++;
					index++;
				}

				//Creating page table
				table.insert(frameNum);

				loadSize -= 64;
				count++;
			}

			head->table = table;
			readyQueue.insertElements(head);
		} else {
			return;
		}
	}
}
