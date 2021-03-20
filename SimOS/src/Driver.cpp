/*
 * Driver.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include "Driver.h"
#include "MemoryManagement/Disk.h"
#include "MemoryManagement/PCB.h"
#include "SupportPrograms.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void Driver::RUN() {
	Disk disk;
	PCB pcbList;

	cout << "...Loading Data Into Disk..." << endl;

	//Loader, loads data from Datafile.txt into Disk and PCB
	Loader(disk, pcbList);

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
			string word;

			for (int i = 0; i < 3; i++) {
				int index = job.find(' ');

				if (index == -1) {
					word = job;
					int j = word.length() - 1;
					while (isalnum(word[j]) == 0) {
						j--;
					}
					word = word.substr(0, j+1);
					jobTokens.push_back(word);
				} else {
					jobTokens.push_back(job.substr(0, index));
				}

				job = job.substr(index + 1);
			}

		} else if (command[3] == 'D') {
			string job = command.substr(8);
			string word;

			for (int i = 0; i < 3; i++) {
				int index = job.find(' ');

				if (index == -1) {
					word = job;
					int j = word.length() - 1;
					while (isalnum(word[j]) == 0) {
						j--;
					}
					word = word.substr(0, j+1);
					dataTokens.push_back(word);
				} else {
					dataTokens.push_back(job.substr(0, index));
				}

				job = job.substr(index + 1);
			}

			int index = support.hexToDecimal(jobTokens[0]);
			int cpuid = 1;
			int status = 0;
			int priority = support.hexToDecimal(jobTokens[2]);
			int codeSize = support.hexToDecimal(jobTokens[1]);
			int inputBuffer = support.hexToDecimal(dataTokens[0]);
			int outputBuffer = support.hexToDecimal(dataTokens[1]);
			int temporaryBuffer = support.hexToDecimal(dataTokens[2]);

			pcbList.insertElements(index, cpuid, status, priority, codeSize);

			jobTokens.clear();
			dataTokens.clear();
		}
	}
}
