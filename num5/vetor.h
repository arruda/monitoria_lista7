/*
 * vetor.h
 *
 *  Created on: 14/06/2011
 *      Author: arruda
 */

#ifndef VETOR_H_
#define VETOR_H_

#include <iostream>
using namespace std;

template<class Type> class vetor {
protected:
	Type *Element;
	int MaxSize;
	int ultimaPos;
public:
	bool empty();
	bool IsFull() const;
	vetor(int maxsize = 10);
	 ~vetor();

	int size();
	bool push_back(const Type& value);

    Type pop_back();

    vetor operator=(const vetor<Type>& SourceVetor);
    bool operator == (vetor<Type>& vetComp);
    int Find(const Type& value);

};



#endif /* STACK_H_ */
