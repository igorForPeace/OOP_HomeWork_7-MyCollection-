#include "Vector.h"

void Vector::Add(int number) 
{
	Vector::PushBack(number);
}
void Vector::Remove()
{
	Vector::PopBack();
}

void Vector::Print_2()
{
	Vector::Print();
}

void Vector::Search(int value)
{
	Vector::IndexOf(value);
}

void Vector::Replace(int value, int index)
{
	Vector::RemoveAt(index);
	Vector::Insert(index, value);
}

void Vector::Sort()
{
	Vector::SortAsc();
}


Vector::Vector(unsigned int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->date = new int[capacity];
}

Vector::Vector() :Vector(10) {}

Vector::Vector(const Vector& original)
{
	Clone(original);
}

Vector::~Vector()
{
	if (date != nullptr)
	{
		delete[] date;
	}
}

int Vector::GetSize() const
{
	return size;
}

int Vector::GetCapacity() const
{
	return capacity;
}

void Vector::SetCapacity(unsigned int capacity)
{
	this->capacity = capacity;
}

void Vector::Print()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << date[i] << "  ";
	}
}

void Vector::Print(int index)
{
	for (int i = 0; i < this->size; i++)
	{
		if (i == index)
		{
			cout << date[i] << endl;
		}
	}
}

void Vector::ShowInfo()
{
	cout << "Elements of arrey: ";
	for (int i = 0; i < this->size; i++)
	{
		cout << date[i] << "  ";
	}
	cout << endl;
	cout << "Size of arrey: " << GetSize() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}

void Vector::EnsureCapacity(int count)
{
	if (count >= this->capacity)
	{
		this->capacity = count * 1.5 + 1;
		int* temp = new int[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->date[i];
		}
		delete[] this->date;
		this->date = new int[this->capacity];
		for (int i = 0; i < size; i++)
		{
			this->date[i] = temp[i];
		}
	}
}

void Vector::PushBack(int number)
{
	if (this->size + 1 > this->capacity)
	{
		this->capacity *= 2;
	}
	int* temp = new int[this->capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->date[i];
	}
	temp[size] = number;
	delete[] this->date;
	this->date = temp;
	this->size++;
}

void Vector::PushFront(int number)
{
	if (this->size + 1 > this->capacity)
	{
		this->capacity *= 2;
	}
	int* temp = new int[this->capacity];
	for (int i = 1; i < size + 1; i++)
	{
		temp[i] = this->date[i - 1];
	}
	temp[0] = number;
	delete[] this->date;
	this->date = temp;
	this->size++;
}

void Vector::Insert(unsigned int index, int number)
{
	if (index > this->size)
	{
		throw "OPPS!";
	}
	else
	{
		if (this->size + 1 > capacity)
		{
			capacity *= 2;
		}
		int* temp = new int[this->size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			if (i == index)
			{
				temp[i] = number;
				for (int i = index; i < size; i++)
				{
					temp[i + 1] = this->date[i];
				}
				break;
			}
			temp[i] = this->date[i];
		}
		delete[] this->date;
		this->date = temp;
		++size;
	}
}

void Vector::RemoveAt(unsigned int index)
{
	if (index > this->size)
	{
		throw "OPPS!";
	}
	else
	{
		int* temp = new int[this->size - 1];
		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				for (int i = index + 1; i < size; i++)
				{
					temp[i - 1] = this->date[i];

				}
				break;
			}
			temp[i] = this->date[i];
		}
		delete[] this->date;
		this->date = temp;
		--size;
	}
}

void Vector::Remove(int number)
{
	int temp_length = 0;
	for (int i = 0; i < size; i++)
	{
		if (this->date[i] == number)
		{
			++temp_length;
		}
	}
	int* temp = new int[size - temp_length];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (this->date[i] == number)
		{
			i++;
			temp[j] = this->date[i];
			j++;
			continue;
		}
		temp[j] = this->date[i];
		j++;
	}
	delete[] this->date;
	this->date = temp;
	size -= temp_length;
}

void Vector::PopFront()
{
	int* temp = new int[this->size - 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->date[i + 1];
	}
	delete[] this->date;
	this->date = temp;
	--size;
}

void Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = this->date[i];
	}
	delete[] this->date;
	this->date = temp;
	--size;
}

void Vector::Clear()
{
	int* temp = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = 0;
	}
	delete[] this->date;
	this->date = temp;
	size = 0;
}

bool Vector::IsEmpty()
{
	return (this->size == 0 ? 1 : 0);
}

void Vector::TrimToSize()
{
	int* temp = new int[this->size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->date[i];
	}
	delete[] this->date;
	this->date = temp;
	this->capacity = this->size;
}

int Vector::IndexOf(int number)
{
	for (int i = 0; i < size; i++)
	{
		if (this->date[i] == number)
		{
			return i;
		}
	}
	return -1;
}

int Vector::LastIndexOf(int number)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (this->date[i] == number)
		{
			return i;
		}
	}
	return -1;
}

void Vector::Reverse()
{
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->date[size - i - 1];
	}
	delete[] this->date;
	this->date = temp;
}

void Vector::SortAsc()
{
	sort(this->date, this->date + this->size);
}

void Vector::SortDesc()
{
	sort(this->date, this->date + this->size);
	Reverse();
}

void Vector::Shuffle()
{
	for (int i = 0; i < size; i++)
	{
		int j = rand() % size;
		if (i != j)
		{
			int temp = this->date[i];
			this->date[i] = this->date[j];
			this->date[j] = temp;
		}
	}
}

void Vector::RandomFill()
{
	delete[] this->date;
	date = new int[capacity];
	size = capacity;
	for (int i = 0; i < size; i++)
	{
		this->date[i] = rand() % 10;
	}
}

bool Vector::Equals(const Vector& other)
{
	if (this->size == other.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->date[i] == other.date[i])
			{
				continue;
			}
			else
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int Vector::GetElementAt(int index)
{
	if (index < size)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				return this->date[i];
			}
		}
	}
	else
	{
		return -1;
	}
}

Vector& Vector::Clone(const Vector& other)
{
	if (this->date != nullptr)
	{
		delete[] this->date;
	}
	this->date = new int[other.capacity];
	this->size = other.size;
	this->capacity = other.capacity;
	for (int i = 0; i < size; i++)
	{
		this->date[i] = other.date[i];
	}
	return *this;
}

Vector& Vector:: operator = (const Vector& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	if (this->date != nullptr)
	{
		delete[] this->date;
	}
	this->date = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->date[i] = other.date[i];
	}
	return *this;
}

int Vector::operator [] (int index)
{
	return GetElementAt(index);
}

bool Vector::operator== (const Vector& other)
{
	return Equals(other);

}

