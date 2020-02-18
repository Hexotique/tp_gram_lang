#include <iostream>
#include "lexer.h"

int main(void) {
	string toRead("(1+34)*123");

	set<int> s({1});
	map<int, map<int, int>> t;

	t[0][0] = 3;
	t[0][3] = 2;
	t[0][6] = 1;

	t[1][1] = 4;
	t[1][2] = 5;

	t[2][0] = 3;
	t[2][3] = 2;
	t[2][6] = 6;

	t[3][1] = -5;
	t[3][2] = -5;
	t[3][4] = -5;
	t[3][5] = -5;

	t[4][0] = 3;
	t[4][3] = 2;
	t[4][6] = 7;

	t[5][0] = 3;
	t[5][3] = 2;
	t[5][6] = 8;

	t[6][1] = 4;
	t[6][2] = 5;
	t[6][4] = 9;

	t[7][1] = -2;
	t[7][2] = 5;
	t[7][4] = -2;
	t[7][5] = -2;

	t[8][1] = -3;
	t[8][2] = -3;
	t[8][4] = -3;
	t[8][5] = -3;

	t[9][1] = -4;
	t[9][2] = -4;
	t[9][4] = -4;
	t[9][5] = -4;

	map<int, pair<int, int>> r;
	r[1] = make_pair(EXPR, 1);
	r[2] = make_pair(EXPR, 3);
	r[3] = make_pair(EXPR, 3);
	r[4] = make_pair(EXPR, 3);
	r[5] = make_pair(EXPR, 1);

	Lexer l(t, s, r);
	Expression * expr = nullptr;
	if (l.analyse(toRead, &expr)) {
		cout << expr->evaluate() << endl;
	} else {
		cout << "no" << endl;
	}

   	return 0;
}

