#include "symbol.h"

string Symbol::show() {
   return Tags[ident];
}

string Integer::show() {
   return "-" + value;
}

int Integer::getValue() {
	return value;
}
