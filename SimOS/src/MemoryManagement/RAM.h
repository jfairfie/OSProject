/*
 * RAM.h
 *
 *  Created on: Mar 15, 2021
 *      Author: jfairfie
 */

#ifndef RAM_H_
#define RAM_H_

class RAM {
	public:
		RAM();
		const int SIZE;
		char hexCharacters[SIZE];
		char * returnInstruction(int index);
};

#endif /* RAM_H_ */
