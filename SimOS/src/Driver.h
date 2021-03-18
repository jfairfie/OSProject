/*
 * Driver.h
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#ifndef DRIVER_H_
#define DRIVER_H_
#include "MemoryManagement/Disk.h"

class Driver {
	public:
		Driver();
		void RUN();
	private:
		void Loader(Disk disk);
};

#endif /* DRIVER_H_ */
