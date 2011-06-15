/*
 * stack_func.h
 *
 *  Created on: 14/06/2011
 *      Author: arruda
 */
#include "stack.h"

template<class Type>
stack<Type>::stack(int maxsize) :
	Element(new Type[maxsize]), MaxSize(maxsize), StackPointer(-1) {
}

//template<class Type>
//stack<Type>::stack() :
//	MaxSize(10), Element(new Type[10]), StackPointer(-1) {
//}
//
//

template<class Type>
bool stack<Type>::Pop(Type& TopElem) {
	if (IsEmpty()) {
		return false;
	}
	TopElem = Element[StackPointer--];
	return true;
}

template<class Type>
bool stack<Type>::Push(Type& NewElem) {
	if (!IsFull()) {
		Element[++StackPointer] = NewElem;
		return true;
	} else {
		cout << "Stack full: push failed.\n";
		return false;
	}
}

template<class Type>
stack<Type>::~stack() {
	delete[] Element;
}
template<class Type>
bool stack<Type>::IsEmpty() const {
	return StackPointer == -1 ? true : false;
}

template<class Type>
bool stack<Type>::IsFull() const {
	return StackPointer == MaxSize - 1 ? true : false;
}
