/*
 * PageTable.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: jfairfie
 */

#include "PageTable.h"

void PageTable::insert(int frameNumber) {
	frames.push_back(frameNumber);
}

int PageTable::returnIndex(int index) {
	return frames.at(index);
}

void PageTable::printTable() {
	for (int i = 0; i < frames.size(); i++) {
		std::cout << frames.at(i) << " ";
	}
	std::cout << std::endl;
}
