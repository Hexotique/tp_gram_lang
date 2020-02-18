#include "expression.h"
#include <iostream>

using namespace std;


int PlusExpr::evaluate() {
	return leftExpr->evaluate() + rightExpr->evaluate();
}

int MultExpr::evaluate() {
	return leftExpr->evaluate() * rightExpr->evaluate();
}

int ParExpr::evaluate() {
	return expr->evaluate();
}

int ValExpr::evaluate() {
	return val->getValue();
}
