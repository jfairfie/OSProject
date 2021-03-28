/*
 * PageTable.h
 *
 *  Created on: Mar 25, 2021
 *      Author: jfairfie
 */

#ifndef SRC_MEMORYMANAGEMENT_PAGETABLE_H_
#define SRC_MEMORYMANAGEMENT_PAGETABLE_H_
#include <vector>
#include <iostream>

class PageTable {
	public:
		std::vector<int> frames;
		void insert(int frameNumber);
		int returnIndex(int index);
		int returnSize(){return frames.size();}
		void printTable();
	private:
};

#endif /* SRC_MEMORYMANAGEMENT_PAGETABLE_H_ */
