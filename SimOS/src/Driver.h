/*
 * Driver.h
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#ifndef DRIVER_H_
#define DRIVER_H_
#include "MemoryManagement/Disk.h"
#include "MemoryManagement/PCB.h"
#include "MemoryManagement/RAM.h"
#include "MemoryManagement/PageTable.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <math.h>
#include "SupportPrograms.h"

using namespace std;
class Driver {
	public:
		void RUN();
	private:
		void Loader(Disk &disk, PCB &pcbList);
		void tokenize(string job, vector<string> &tokens);
		void LTSchedule(Disk disk, PCB &pcbList, PCB &readyQueue, RAM &ram);
};

#endif /* DRIVER_H_ */
