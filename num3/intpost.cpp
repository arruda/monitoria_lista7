/*
 * intpost.cpp
 *
 *  Created on: 15/06/2011
 *      Author: arruda
 */

#include "intpost.h"
//incluido para usar o pow
#include <math.h>

intpost::intpost(int StackSize, int postfixexprsize) :
	NumStack(StackSize), PostfixExpr(new char[postfixexprsize]),
			PostfixExprSize(postfixexprsize) {
}
intpost::~intpost() {
	delete[] PostfixExpr;
}
// Read in the postfix expression to be evaluated
void intpost::Read() {
	cout << "Enter postfix expression: ";
	cin.getline(PostfixExpr, PostfixExprSize);
}
// Test if current token is an operator
bool intpost::Operator(char token) const {
	if (token == '*' || token == '+' || token == '-' || token == '/')
		return true;
	return false;
}
// Apply operator to top two stack tokens
// Return true if operation successful,
// false if insufficient operands on stack
bool intpost::ApplyOperator(char Operator) {
	int operand1, operand2;
	// Pop two operands off stack
	if (!NumStack.Pop(operand1))
		return false;
	if (!NumStack.Pop(operand2))
		return false;

	int tempInteger;
	switch (Operator) {
	case '*':
		tempInteger = operand2 * operand1;
		NumStack.Push(tempInteger);
		break;
	case '+':
		tempInteger = operand2 + operand1;
		NumStack.Push(tempInteger);
		break;
	case '/':
		tempInteger = operand2 / operand1;
		NumStack.Push(tempInteger);
		break;
	case '-':
		tempInteger = operand2 - operand1;
		NumStack.Push(tempInteger);
		break;
	default:
		return false;
	}
	return true;
}
bool intpost::Evaluate() {
	int token = 0;
	int longNumber=0;
	int numDigitos=0;
	while (PostfixExpr[token]) {
		if (Operator(PostfixExpr[token])) {
			if (!ApplyOperator(PostfixExpr[token])) {
				cout << "Error: too few operands\n";
				return false;
			}
		} else if (int(PostfixExpr[token]) >= int('0')
				&& int(PostfixExpr[token]) <= int('9')) {

			int tempInteger = int(PostfixExpr[token]) - int('0');


			longNumber = tempInteger + (longNumber * pow(10, numDigitos));
			numDigitos++;
			//se for o ultimo digito do numero inclui o mesmo na pilha
			if (PostfixExpr[token + 1] == ' ') {
				NumStack.Push(longNumber);
			}
		}else{
			//zera as variaveis auxiliares de numero ja que ele terminou de ler um numero ou
			//terminou de ler um operador.
			numDigitos=0;
			longNumber=0;
		}
		token++;
	}
	if (!NumStack.Pop(Answer)) {
		cout << "Error popping answer.\n";
		return false;
	} else if (!NumStack.IsEmpty()) {
		cout << "Error: too many operands.\n";
		return false;
	}
	return true;
}
void intpost::PrintAnswer() const {
	cout << "Answer = " << Answer << endl;
}
