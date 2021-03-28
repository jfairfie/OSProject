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

std::string SupportPrograms::hexToBinary(std::string hex) {
	std::string binary = "";
	for (int i = 0; i < hex.length(); i++) {
		binary += hexCharMap(hex[i]) + " ";
	}
	return binary;
}

std::string SupportPrograms::hexCharMap(char hexChar) {
	switch(hexChar) {
	case '0':
		return "0000";
	case '1':
		return "0001";
	case '2':
		return "0010";
	case '3':
		return "0011";
	case '4':
		return "0100";
	case '5':
		return "0101";
	case '6':
		return "0110";
	case '7':
		return "0111";
	case '8':
		return "1000";
	case '9':
		return "1001";
	case 'A':
		return "1010";
	case 'B':
		return "1011";
	case 'C':
		return "1100";
	case 'D':
		return "1101";
	case 'E':
		return "1110";
	case 'F':
		return "1111";
	}
	return "";
}

//int hexToDecimal(char hex[]);
//int binaryToDecimal(int bin[]);
//std::string binaryToHex(int bin[]);
//int decimalToBinary(int dec[]);
//std::string decimalToHex(int dec[]);


