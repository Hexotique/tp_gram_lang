#pragma once

#include <string>
using namespace std;

enum Identifiers { INT, PLUS, MULT, OPENPAR, CLOSEPAR, FIN, EXPR, ERROR};

const string Tags[] = { "INT", "PLUS", "MULT", "OPENPAR", "CLOSEPAR", "FIN", "EXPR", "ERROR" };

class Symbol {
   public:
      Symbol(int i) :
		  ident(i) { }

	  virtual ~Symbol() { }

      operator int() const {
		  return ident;
	  }

	  virtual string show();

   protected:
      int ident;
};

class Integer : public Symbol {
   public:
      Integer(int v)
		  : Symbol(INT), value(v) {}

	  ~Integer() {}

	  virtual string show();

	  int getValue();

   protected:
      int value;
};

