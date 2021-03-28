/*
 * RAM.cpp
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#include "RAM.h"

void RAM::insert(int frame, int index, std::string data) {
	jobs[frame][index] = data;
}

void RAM::emptyFrame(int frameNumber) {
	for (int i = 0; i < FRAME_SIZE; i++) {
		jobs[frameNumber][i] = "";
	}
	fullFrames--;
}

int RAM::getNextEmpty() {
	for (int i = 0; i < FRAME_COUNT; i++) {
		if (frameUsed(i) == false) {
			fullFrames++;
			return i;
		}
	}
}

bool RAM::enoughSpace(int insertSize) {
	if (insertSize < (FRAME_COUNT -fullFrames)) {
		return true;
	}
	return false;
}

bool RAM::frameUsed(int frameNumber) {
	if (jobs[frameNumber][0].compare("") == 0) {
		return false;
	}
	return true;
}

void RAM::printFrame() {
	for (int i = 0; i < FRAME_COUNT; i++) {
		if (frameUsed(i)) {
			std::cout << "FRAME -- " << i << std::endl;
//			for (int j = 0; j < FRAME_SIZE; j++) {
//				std::cout << jobs[i][j] << std::endl;
//			}
			for (auto x : jobs[i]) {
				if (x.compare("") != 0) {
					std::cout << x << std::endl;
				}
			}
			std::cout << std::endl;
		}
	}
}
