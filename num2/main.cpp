#include "stack_func.h"
#include <string>


int main() {
	string str;
	cout << "Entre com uma string: " << endl;

	bool palindromo = true;

	getline(cin, str);
	stack<char> expInf(str.size());

	for(int i =0;i<str.size();i++){
		expInf.Push(str[i]);
	}

	for(int j =0;j<str.size();j++){
		char temp;
		expInf.Pop(temp);

		if(temp != str[j]){

			cout <<"Nao palindromo"<<endl;
			palindromo=false;
			break;
		}
	}
	if(palindromo){
		cout << "Palindromo"<<endl;
	}


	return 0;
}
