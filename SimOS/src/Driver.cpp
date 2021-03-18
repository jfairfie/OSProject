/*
 * Driver.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include "Driver.h"
#include "MemoryManagement/Disk.h"
#include "PCB.h"
#include <iostream>
#include <cstdio>

using namespace std;

Driver::Driver() {
	// TODO Auto-generated constructor stub

}

void Driver::RUN() {
	Disk disk;
	PCB pcbList;

	cout << "...Loading Data Into Disk..." << endl;

	//Loader
	Loader(disk);
	pcbList.insertElements(0, 1, 0, 2, 14);
	pcbList.insertElements(1, 1, 0, 5, 4);
	pcbList.printList();
	pcbList.insertElements(2, 1, 0, 3, 2);
	pcbList.insertElements(3, 2, 1, 5, 17);
	std::cout << " " << endl;
	pcbList.printList();
	//Loop

	//Scheduler
	//Dispatcher
	//CPU
	//WaitforInterrupt

	//Endloop

}

//Loader loads information from file into disk
//Filename is DataFile
void Driver::Loader(Disk disk) {
	freopen("DataFile.txt", "rb", stdin);
	string command;

	while (getline(cin, command)) {
		//Inserting instructions
		if (command[0] != '/') {
			disk.insertNextIndex(command.substr(2));
		} /* Else instert into PCB */
	}
}
