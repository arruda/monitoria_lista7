#include "intpost.h"
#include <string>

int main() {
	while (1) {

		intpost Postfix;
		Postfix.Read();
		if (Postfix.Evaluate())
			Postfix.PrintAnswer();

	}
	return 0;

}
