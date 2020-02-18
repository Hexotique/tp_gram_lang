#pragma once

#include <string>
#include <map>
#include <set>
#include <stack>
#include <utility>

#include "symbol.h"
#include "expression.h"
using namespace std;

class Lexer {
   	public:
      	Lexer(map<int, map<int, int>> & t, set<int> & s, map<int, pair<int, int>> & r)
		  	:trans(t), finalStates(s), reduceCount(r), head(0), tampon(nullptr)
	  	{}

      	~Lexer() {}

		bool analyse(string s, Expression ** expr);

   	protected:
		map<int, map<int, int>> trans;
		set<int> finalStates;

		map<int, pair<int, int>> reduceCount;
		stack<int> stateStack;
		stack<Symbol*> symbolStack;

		int head;
	  	Symbol* tampon;
      	string flux;

		Symbol* consult();

		void advance();
};
