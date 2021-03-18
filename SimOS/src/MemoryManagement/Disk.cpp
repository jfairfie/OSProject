/*
 * Disk.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: jfairfie
 */

#include <iostream>
#include <string>
#include "Disk.h"

void Disk::printDisk() {
	for (int i = 0; i < getLastIndex(hexCharacters); i++) {
		std::cout << hexCharacters[i] << std::endl;
	}
}

void Disk::insertNextIndex(std::string data) {
	int index = getLastIndex(hexCharacters);
	hexCharacters[index] = data;
}

int Disk::getLastIndex(std::string characters[]) {
	for (int i = 0; i < SIZE; i++) {
		if (characters[i] == "") {
			return i;
		}
	}
	return -1;
}


