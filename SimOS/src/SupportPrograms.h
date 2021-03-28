/*
 * SupportPrograms.h
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#ifndef SUPPORTPROGRAMS_H_
#define SUPPORTPROGRAMS_H_
#include <string>

class SupportPrograms {
	public:
		std::string hexToBinary(std::string hex);
		int hexToDecimal(std::string hex);
//		int hexToDecimal(char hex[]);
//		int binaryToDecimal(int bin[]);
//		std::string binaryToHex(int bin[]);
//		int decimalToBinary(int dec[]);
//		std::string decimalToHex(int dec[]);
	private:
		std::string hexCharMap(char hexChar);
};

#endif /* SUPPORTPROGRAMS_H_ */
