#pragma once

#include "symbol.h"

class Expression : public Symbol {
	public:
		Expression()
			: Symbol(EXPR) {}

		virtual int evaluate() = 0;
};

class PlusExpr : public Expression {
	public:
		PlusExpr(Expression * left, Expression * right)
			: leftExpr(left), rightExpr(right) {}

		virtual int evaluate();

	protected:
		Expression * leftExpr;
		Expression * rightExpr;
};

class MultExpr : public Expression {
	public:
		MultExpr(Expression * left, Expression * right)
			: leftExpr(left), rightExpr(right) {}

		virtual int evaluate();

	protected:
		Expression * leftExpr;
		Expression * rightExpr;
};

class ParExpr : public Expression {
	public:
		ParExpr(Expression * inner)
			: expr(inner) {}

		virtual int evaluate();

	protected:
		Expression * expr;
};

class ValExpr : public Expression {
	public:
		ValExpr(Integer * i)
			: val(i) {}

		virtual int evaluate();

	protected:
		Integer * val;
};
