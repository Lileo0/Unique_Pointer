
#include "UniquePtr.h"
#include <iostream>

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr& r)
{
	Reset(new T(*r.ptr));
	return *this;
}
template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& i)
{
	this->ptr = i.ptr;
	i.ptr = nullptr;
}
template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& i)
{
	this->ptr = i.ptr;
	i.ptr = nullptr;
	return *this;
}
template<typename T>
void UniquePtr<T>::Reset()
{
	delete[] this->ptr;
	this->ptr = nullptr;
}
template<typename T>
void UniquePtr<T>::Reset(T* other)
{
	delete[] this->ptr;
	this->ptr = other;
}
template<typename T>
T* UniquePtr<T>::Release()
{
	T* toReturn = this->ptr;
	this->ptr = nullptr;
	return toReturn;
}
template<typename T>
void UniquePtr<T>::Swap(T*& other)
{
	T* temp = this->ptr;
	this->ptr = nullptr;
	this->ptr = other;
	other = temp;
	temp = nullptr;
}
template<typename T>
void UniquePtr<T>::Swap(UniquePtr& other)
{
	T* temp = this->ptr;
	this->ptr = nullptr;
	this->ptr = other.ptr;
	other.ptr = temp;
	temp = nullptr;
}
template<typename T>
T* UniquePtr<T>::Get()
{
	return this->ptr;
}
template<typename T>
void UniquePtr<T>::Set(T* pointer)
{
	this->ptr = pointer;
}
