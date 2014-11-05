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

bool Scanner::nextToken(Token* t) {
	automat->clean();
	bool cont;
	char ch;
	while (t->content->isEmpty()) {
		do {
			ch = buffer->getChar();
			if (ch != ' ' && ch != '\n' && ch != '\t') {
				t->content->push(ch);
			}
			cont = automat->testChar(ch);
		} while (cont);

		for (int j = automat->getStepsSinceLastFinalState(); j > 0; j--) {
			if (ch != ' ' && ch != '\n' && ch != '\t') {
				buffer->ungetChar();
			}
			t->content->pop();

		}
	}
	t->setSpalte(automat->getSpalte());
	t->setZeile(automat->getZeile());
	t->setTokenType(Unknown);
	return buffer->hasCharLeft();
}
