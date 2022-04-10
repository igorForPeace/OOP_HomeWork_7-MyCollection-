
#pragma once
#include "AllLibraries.h"

class DoubleList :public MyCollection<int>
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;
public:
	DoubleList();
	DoubleList(const DoubleList& original);
	~DoubleList();

	void Add(int number) override;
	void Remove() override;
	void Print_2() override;
	void Search(int value) override;
	void Replace(int value, int index) override;
	void Sort() override;


	void AddToHead(int data);  // добавление элемента к списку
	void AddToTail(int data); // добавление узла к концу списка
	void InsertInto(int data, int position); // добавление узла к списку по номеру позиции
	void DeleteFromHead(); // удалить элемент из начала списка
	void DeleteFromTail(); // удаление из конца списка
	void DeleteByIndex(int position); // удаление по индексу
	void Clear(); // очистка  
	int GetCount() const;   // возврат значения count
	bool IsEmpty();   // проверка на пустоту списка
	void Print() const;   // показ элементов списка
	int IndexOf(int data) const;  // возврат номера элемента 
	void Reverse(); // изменение порядка следования списка
	void SortAsc(); // сортировка по увеличению
	void SortDesc(); // сортировка по убыванию
	void Shuffle(); // случайное перемещение элементов списка
	void SetAt(int index, int number); // установка значения по указанному индексу
	bool Equals(const DoubleList& other); // сравнение двух списков
	DoubleList& Clone(const DoubleList& original); // копирование одного списка в другой
	bool Contains(int number); // проверка на вхождение в списка числа переданного в параметре
	DoubleList& MergeWith(const DoubleList& other); // добавляет в конец нашего списка другой
	int& ToArray(int*& arr); // из списка в массив
	bool operator < (const DoubleList& other);
	bool operator > (const DoubleList& other);
	bool operator <= (const DoubleList& other);
	bool operator >= (const DoubleList& other);
	bool operator == (const DoubleList& other);
	bool operator != (const DoubleList& other);
	DoubleList& operator = (const DoubleList& other);
	int operator [] (int index);
	DoubleList& operator +(const DoubleList& other);
	DoubleList& operator +=(const DoubleList& other);

};



