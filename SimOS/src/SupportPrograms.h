/*
 * SupportPrograms.h
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#ifndef SUPPORTPROGRAMS_H_
#define SUPPORTPROGRAMS_H_

class SupportPrograms {
	public:
		SupportPrograms();
		int * hexToBinary(char hex[]);
		int * hexToDecimal(char hex[]);
		int * binaryToDecimal(int bin[]);
		char * binaryToHex(int bin[]);
		int * decimalToBinary(int dec[]);
		char * decimalToHex(int dec[]);
};

#endif /* SUPPORTPROGRAMS_H_ */
