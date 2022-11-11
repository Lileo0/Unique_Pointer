#pragma once
#include <iostream>
template <typename T>
class UniquePtr
{
public:
	// Sprint 1
	explicit UniquePtr(T* p = 0) : ptr(p) {}
	~UniquePtr() { delete ptr; }

	//Copy Assignment
	UniquePtr& operator=(const UniquePtr& r);

	//Copy constructor
	UniquePtr(const T i) : ptr(new T(i)) {}
	UniquePtr(const UniquePtr& a) : ptr(new T(*a.ptr)) {}

	//Move Constructor
	UniquePtr(UniquePtr&& i);
	//Move Assignment
	UniquePtr& operator=(UniquePtr&& i);

	//Sprint 2
	T* Release();
	void Swap(T*& other);
	void Reset();
	void Reset(T* other);

	//Sprint 3
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
	explicit operator bool() { if (ptr)return true; return false; };


	//Tools
	T* Get();
	void Set(T* pointer);
	T* ptr;//sollte private sein müssen? ansonsten gibts probleme beim swap weil es die get funktion nicht annimmt.
private:

};



