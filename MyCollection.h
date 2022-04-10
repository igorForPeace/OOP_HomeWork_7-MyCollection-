#pragma once
#include "AllLibraries.h"

template <class T>
class MyCollection
{
private:
	int count;

public:

	int GetCount() const 
	{
		return count;
	}
	virtual void Add(T value) {}
	virtual void Remove() {}
	virtual void Print_2() {}
	virtual void Search(T value) {}
	virtual void Replace(T value, int index) {}
	virtual void Sort() {}
};