/*
 * vetor_func.h
 *
 *  Created on: 14/06/2011
 *      Author: arruda
 */
#include "vetor.h"

template<class Type>
vetor<Type>::vetor(int maxsize) :
	Element(new Type[maxsize]), MaxSize(maxsize),ultimaPos(-1) {
}



template<class Type>
bool vetor<Type>::push_back(const Type& value)
{
	if(ultimaPos+1 < MaxSize){
	    this->Element[++ultimaPos] = value;
	    return true;
	}
	return false;
}

template<class Type>
Type vetor<Type>::pop_back()
{
	if(ultimaPos>= 0){
	    return Element[ultimaPos--];
	}
	else return NULL;
}

template<class Type>
int vetor<Type>::size()
{
    return ultimaPos+1;
}


template<class Type>
vetor<Type>::~vetor() {
	delete[] Element;
}

template<class Type>
bool vetor<Type>::empty() {
	if(ultimaPos >= 0)
		return false;

	return true;
}

template<class Type>
vetor<Type> vetor<Type>::operator=(const vetor<Type>& SourceVetor) {
	if (this == &SourceVetor)
		return (*this);
	if (MaxSize != SourceVetor.MaxSize) {
		delete[] Element;
		Element = new Type[SourceVetor.MaxSize];
		MaxSize = SourceVetor.MaxSize;
	}
	ultimaPos = SourceVetor.ultimaPos;
	for (int i = 0; i <= ultimaPos; i++)
		Element[i] = SourceVetor.Element[i];
	return (*this);

}

template<class Type>
bool vetor<Type>::operator == (vetor<Type>& vetComp)
{
	if(ultimaPos != vetComp.ultimaPos)
		return false;
	for(int i=0;i<MaxSize;i++){
		if(Element[i] != vetComp.Element[i])
			return false;
	}
	return true;
}

template<class Type>
int vetor<Type>::Find(const Type& value)
{

	for (int i = 0; i <= ultimaPos; i++)
		if(value == Element[i])
			return i;

	return -1;
}
