#include "vetor_func.h"
#include <string>


int main() {
	vetor<string> strs2(3);
	vetor<string> strs(3);

	strs.push_back("a");
	strs.push_back("b");
	strs.push_back("c");

	strs2 = strs;

	cout << strs.pop_back()<<endl;
	cout << strs2.pop_back()<<endl;



	cout << (strs == strs2)<<endl;
	cout << "====="<<endl;
	cout <<strs.Find("c")<<endl;
	cout << "====="<<endl;
	cout <<strs.size()<<endl;

	return 0;
}
