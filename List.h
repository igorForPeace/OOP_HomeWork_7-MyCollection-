#pragma once
#include "AllLibraries.h"

class List:public MyCollection<int>
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
	};
private:
	Node* head = nullptr;
	Node* tail = nullptr;

	int count = 0;
public:
	List();
	List(const List& original);
	~List();

	void Add(int number) override;
	void Remove() override;
	void Print_2() override;
	void Search(int value) override;
	void Replace(int value, int index) override;
	void Sort() override;

	void AddToHead(int data); // добавление узла к голове списка
	void AddToTail(int data); // добавление узла к концу списка
	void InsertInto(int data, int position); // добавление узла к списку по номеру позиции
	void DeleteFromHead(); // удалить элемент из начала списка
	void DeleteFromTail(); // удаление из конца списка
	void DeleteByIndex(int position); // удаление по индексу
	void Clear(); // очистка  
	void Print() const;
	int GetCount() const;
	int IndexOf(int data) const;
	bool IsEmpty();
	void Reverse(); // изменение порядка следования списка
	void SortAsc(); // сортировка по увеличению
	void SortDesc(); // сортировка по убыванию
	void Shuffle(); // случайное перемещение элементов списка
	void SetAt(int index, int number); // установка значения по указанному индексу
	bool Equals(const List& other); // сравнение двух списков
	List& Clone(const List& original); // копирование одного списка в другой
	bool Contains(int number); // проверка на вхождение в списка числа переданного в параметре
	List& MergeWith(const List& other); // добавляет в конец нашего списка другой
	int& ToArray(int*& arr); // из списка в массив
	//перегрузки операторов сравнения 
	bool operator < (const List& other);
	bool operator > (const List& other);
	bool operator <= (const List& other);
	bool operator >= (const List& other);
	bool operator == (const List& other);
	bool operator != (const List& other);
	List& operator = (const List& other);
	int operator [] (int index);
	List& operator +(const List& other);
	List& operator +=(const List& other);


};



