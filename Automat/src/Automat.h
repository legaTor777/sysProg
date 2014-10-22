/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

enum State
{
	Start, Number
};

enum EingabeType{
	Zahl, Leerzeichen, Buchstabe, Plus, Minus
};

class Automat {
public:
	Automat();
	virtual ~Automat();
	State getLastFinalState();
	int getStepsSinceLastFinalState();
	bool testChar(char c);

private:
	State lastFinalState;
	int stepsSinceLastFinalState;
	State stateMatrix[2][10];
};

#endif /* Automat_H_ */
