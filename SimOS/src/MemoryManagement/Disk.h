/*
 * Disk.h
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#ifndef DISK_H_
#define DISK_H_
#define SIZE 2048
#include <string>

class Disk {
	public:
		void insertNextIndex(std::string data);
		void printDisk();
		void printIndex(int index);
		std::string returnIndex(int index);
	private:
		int getLastIndex(std::string array[]);
		std::string hexCharacters[SIZE] = {""};

};

#endif /* DISK_H_ */
