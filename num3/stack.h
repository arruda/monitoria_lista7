/*
 * stack.h
 *
 *  Created on: 14/06/2011
 *      Author: arruda
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using namespace std;

template<class Type> class stack {
protected:
	Type *Element;
	int MaxSize;
	int StackPointer;
public:
	bool IsEmpty() const;
	bool IsFull() const;
//	stack();
	stack(int maxsize = 10);
	 ~stack();
	bool Pop(Type&);
	bool Push(Type&);
};



#endif /* STACK_H_ */
