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
#include <vector>


using namespace std;
class Driver {
	public:
		void RUN();
	private:
		void Loader(Disk &disk, PCB &pcbList);
};

#endif /* DRIVER_H_ */
