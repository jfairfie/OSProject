/*
 * SupportPrograms.cpp
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#include "SupportPrograms.h"
#include <iostream>

int SupportPrograms::hexToDecimal(std::string hex) {
	int base = 1;
	int dec = 0;

	for (int i = hex.length() - 1; i >= 0; i--) {
			if (hex[i] >= '0' && hex[i] <= '9') {
				dec += (hex[i] - 48) * base;
			} else {
				dec += (hex[i] - 55) * base;
			}
			base *= 16;
	}
	return dec;
}

//int hexToDecimal(char hex[]);
//int binaryToDecimal(int bin[]);
//std::string binaryToHex(int bin[]);
//int decimalToBinary(int dec[]);
//std::string decimalToHex(int dec[]);


