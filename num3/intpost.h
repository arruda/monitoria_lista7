/*
 * intpost.h
 *
 *  Created on: 15/06/2011
 *      Author: arruda
 */

#ifndef INTPOST_H_
#define INTPOST_H_

#include "stack_func.h"

class intpost
{
private:
int Answer;
// Stores final answer
stack<int> NumStack;// Stack for storing operands
char *PostfixExpr;// Postfix expression
int PostfixExprSize;
// Size of PostfixExpr
// Is token an operator?
bool Operator(char
token) const;

// Apply operator to top 2 operands
// and report errors
bool ApplyOperator(char Operator);
public:
intpost(int StackSize = 10, int postfixexprsize = 50);
~intpost();
void Read();
// Evaluate postfix expression
// and report errors
bool Evaluate();
void PrintAnswer() const;
};

#endif /* INTPOST_H_ */
