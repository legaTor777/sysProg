/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Scanner.h"
#include <stdio.h>

Scanner::Scanner() {
	buffer = new Buffer();
	automat = new Automat();
}

Scanner::~Scanner() {
	delete buffer;
	delete automat;
}

void Scanner::nextToken(Token* t) {
	automat->clean();
	bool cont;
	char ch;
	int i = 0;
	do {
		ch = buffer->getChar();
		if (ch != ' '){
		t->content[i] = ch;
		i++;
		}
		cont = automat->testChar(ch);

	} while (cont);

	for (int j = automat->getStepsSinceLastFinalState(); j > 0; j--) {
		if (ch != ' '){
			buffer->ungetChar();
		}
		i--;
		t->content[i] = '\0';

	}
	t->content[i] = '\0';
	t->setSpalte(automat->getSpalte());
	t->setZeile(automat->getZeile());
	t->setTokenType(Integer);
}
