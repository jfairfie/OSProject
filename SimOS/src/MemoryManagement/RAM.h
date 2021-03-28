/*
 * RAM.h
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#ifndef RAM_H_
#define RAM_H_
#define FRAME_COUNT 16
#define FRAME_SIZE 64
#include <string>
#include <iostream>
#include "PageTable.h"
#include "Disk.h"

class RAM {
	public:
		std::string retrieve(int frame, int index) {return jobs[frame][index]; }
		void insert(int frameNumber, int index, std::string data);
		void emptyFrame(int frameNumber);
		bool enoughSpace(int insertSize);
		int getNextEmpty();
		void printFrame();
	private:
		std::string jobs[FRAME_COUNT][FRAME_SIZE] = {""};
		bool frameUsed(int frameNumber);
		int fullFrames = 0;
};

#endif /* RAM_H_ */
