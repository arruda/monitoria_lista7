#include "intpost.h"
#include <string>

int main() {
	int rep=4;
	while (rep >0) {

		intpost Postfix;
		Postfix.Read();
		if (Postfix.Evaluate())
			Postfix.PrintAnswer();

		rep--;
	}
	return 0;

}
