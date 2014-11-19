/*
 * Information.h
 *
 *  Created on: Nov 6, 2014
 *      Author: marius
 */

#ifndef SYMBOLTABLE_SRC_INFORMATION_H_
#define SYMBOLTABLE_SRC_INFORMATION_H_

class Information {
public:
	Information(char* lex);
	virtual ~Information();
	char* getLexem();
	void setLexem(char* lex);
	bool compareLexem(char* lex);
	Information* getNextInfo();
	void setNextInfo(Information* info);
private:
	char* lexem;
	Information* nextInfo;
};

#endif /* SYMBOLTABLE_SRC_INFORMATION_H_ */
