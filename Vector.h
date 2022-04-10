#pragma once
#include "AllLibraries.h"


class Vector : public MyCollection<int>
{
private:
	int* date;
	unsigned int size;
	unsigned int capacity;
	void EnsureCapacity(int count);  // увеличения памяти 
public:
	Vector();
	Vector(unsigned int capacity);
	Vector(const Vector& original);
	~Vector();

	
	void Add(int number) override;
	void Remove() override;
	void Print_2() override;
	void Search(int value) override;
	void Replace(int value, int index) override;
	void Sort() override;

	int GetSize() const;
	int GetCapacity() const;
	void SetCapacity(unsigned int capacity); // установка для значения памяти
	void Print(); // вывод элементов массива
	void Print(int index);
	void ShowInfo(); // показ информации про вектор + элементы
	void PushBack(int number); // добавление элемента в конец массива
	void PushFront(int number); //добавление одного элемента в начало массива
	void Insert(unsigned int index, int number); //вставка числа по индексу
	void RemoveAt(unsigned int inde); // удаление по индексу
	void Remove(int number); // удаление из массива всех элементов number
	void PopFront(); // удаление первого элемента из массива
	void PopBack(); // удаление последнего элемента из массива
	void Clear(); // обнуление всех элементов до 0
	bool IsEmpty(); // метод возвращает true, если size = 0, и false в обратном случае
	void TrimToSize(); // метод подгоняет значение capacity под size, естественно с перевыделением памяти
	int IndexOf(int number);  //(линейный поиск слева направо первого вхождения в массив указанного значения.
			//В результате работы вернуть индекс найденного элемента, а eсли ничего не найдено, вернуть - 1)
	int LastIndexOf(int number);

	void Reverse(); // переворачивание массива
	void SortAsc(); // быстрая сортировка по возрастанию
	void SortDesc(); // быстрая сортировка по убыванию
	void Shuffle(); //случайное перемешивание элементов массива
	void RandomFill(); // заполнение массива случайными числами
	bool Equals(const Vector& other); // сравнение двух массивов
	int GetElementAt(int index);
	Vector& Clone(const Vector& other); // Возвращает клон другого вектора
	Vector& operator = (const Vector& other);
	int operator [] (int index);
	bool operator == (const Vector& other);
	/*friend ostream& operator<<(ostream& os, const Vector& vector);
	friend istream& operator>>(istream& is, Vector& vector);*/
};

