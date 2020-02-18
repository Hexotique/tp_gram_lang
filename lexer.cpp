#include "lexer.h"
#include <iostream>

bool Lexer::analyse(string toRead, Expression ** analysedExpr) {
	flux = toRead;
	head = 0;

	bool error = false;

	int curState = 0;
	stateStack.push(curState);

	Symbol* s;
	while(!error && !(*(s = consult()) == FIN && finalStates.find(curState) != finalStates.end())) {
		//cout << curState << " " << s->show() << endl;

		if (trans[curState].find(int(*s)) != trans[curState].end()) {
			int target = abs(trans[curState][int(*s)]);
			if(trans[curState][int(*s)] >= 0) {
				stateStack.push(target);
				symbolStack.push(s);
				advance();
			} else {
				int leftSym = reduceCount[target].first;
				int beta = reduceCount[target].second;
				//cout << "r" << target << endl;

				Symbol * expr;
				if (beta == 1) {
					expr = new ValExpr((Integer *)symbolStack.top());
					symbolStack.pop();
				} else if (beta == 3) {
					Symbol * right = symbolStack.top();
					symbolStack.pop();
					Symbol * middle = symbolStack.top();
					symbolStack.pop();
					Symbol * left = symbolStack.top();
					symbolStack.pop();

					if (*middle == EXPR) {
						expr = new ParExpr((Expression *)middle);
					} else if (*middle == PLUS) {
						expr = new PlusExpr((Expression *)left, (Expression *)right);
					} else if (*middle == MULT) {
						expr = new MultExpr((Expression *)left, (Expression *)right);
					}
				}

				for(int i = 0; i < beta; i++) {
					stateStack.pop();
				}
				symbolStack.push(expr);

				if (trans[stateStack.top()].find(leftSym) != trans[stateStack.top()].end()) {
					stateStack.push(trans[stateStack.top()][leftSym]);
				} else {
					error = true;
				}
			}
			curState = stateStack.top();
		} else {
			error = true;
		}
	}
	*analysedExpr = ((Expression *)symbolStack.top());
	return !error;
}

Symbol* Lexer::consult() {
   	if (!tampon) {
      	if (head == flux.length()) {
         	tampon = new Symbol(FIN);
		} else {
         	switch (flux[head]) {
            	case '(':
               		tampon = new Symbol(OPENPAR);
               		head++;
               		break;
            	case ')':
               		tampon = new Symbol(CLOSEPAR);
               		head++;
               		break;
				case '*':
               		tampon = new Symbol(MULT);
               		head++;
               		break;
            	case '+':
               		tampon = new Symbol(PLUS);
               		head++;
               		break;
            	default:
               		if (flux[head] <= '9' && flux[head] >= '0') {
                  		int result = flux[head] - '0';
                  		int i = 1;
                  		while (flux[head+i] <= '9' && flux[head+i] >= '0') {
                     		result = result * 10 + (flux[head+i] - '0');
                     		i++;
                  		}
                  		head = head+i;
                  		tampon = new Integer(result);
               		} else {
                  		tampon = new Symbol(ERROR);
               		}
         	}
      	}
  	}
   	return tampon;
}

void Lexer::advance() {
	tampon = nullptr;
}

