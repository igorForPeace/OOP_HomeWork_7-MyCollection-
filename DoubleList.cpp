#include "DoubleList.h"

void DoubleList::Add(int number)
{
	DoubleList::AddToHead(number);
}

void DoubleList::Remove()
{
	DoubleList::DeleteFromTail();
}

void DoubleList::Print_2()
{
	DoubleList::Print();
}

void DoubleList::Search(int value)
{
	DoubleList::IndexOf(value);
}

void DoubleList::Replace(int value, int index)
{
	DoubleList::DeleteByIndex(index);
	DoubleList::InsertInto(value, index);
}
void DoubleList::Sort()
{
	DoubleList::SortAsc();
}

DoubleList::DoubleList()
{
	this->count = 0;
	head = nullptr;
}

DoubleList::DoubleList(const DoubleList& original)
{
	Clone(original);
}

DoubleList::~DoubleList()
{
	Clear();
}

void DoubleList::AddToHead(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	if (IsEmpty())
	{
		tail = temp;
	}
	else
	{
		head->prev = temp;
	}
	head = temp;
	count++;
}

void DoubleList::AddToTail(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->prev = tail;
	if (IsEmpty())
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	count++;
}

void DoubleList::InsertInto(int data, int position)
{
	if (position >= count)
	{
		AddToTail(data);
		return;
	}
	else if (position <= 0)
	{
		AddToHead(data);
		return;
	}
	Node* newElem = new Node();
	Node* beforeNew = new Node();
	newElem->data = data;
	beforeNew = head;
	int i = 1;
	while (i != position)
	{
		beforeNew = beforeNew->next;
		++i;
	}
	newElem->next = beforeNew->next;
	newElem->prev = beforeNew;
	beforeNew->next = newElem;
	count++;
}

void DoubleList::DeleteFromHead()
{
	if (count == 0)
	{
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	count--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}

void DoubleList::DeleteFromTail()
{
	if (count == 0) {
		cout << "Empty list!\n";
		return;
	}
	DeleteByIndex(count - 1);
}

void DoubleList::DeleteByIndex(int position)
{
	if (position <= 0)
	{
		DeleteFromHead();
		return;
	}
	if (position >= count)
	{
		position = count - 1;
	}
	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
		beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	sacrifice->next = beforeDel;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

void DoubleList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}

int DoubleList::GetCount() const
{
	return count;
}

bool DoubleList::IsEmpty()
{
	return count == 0;
}

void DoubleList::Print() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = new Node;
	current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
	delete current;
}

int DoubleList::IndexOf(int data) const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return -1;
	}
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}
	return -1;
}

void DoubleList::Reverse()
{
	Node* current = head;
	Node* prev = nullptr;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	tail = head;
	head = prev;
}

void DoubleList::SortAsc()
{
	Node* current = head;
	Node* temp = new Node;

	for (int i = 0; i < count - 1; i++)
	{
		while (current->next != nullptr)
		{
			if (current->data > current->next->data)
			{
				temp->data = current->data;
				current->data = current->next->data;
				current->next->data = temp->data;
			}
			current = current->next;
		}
		current = head;
	}
	delete temp;
}

void DoubleList::SortDesc()
{
	SortAsc();
	Reverse();
}

void DoubleList::Shuffle()
{
	Node* current = new Node;
	current = head;
	for (int i = 0; i < count; i++)
	{
		int j = rand() % count;
		if (i != j)
		{
			SetAt(j, current->data);
		}
		current = current->next;
	}
}

void DoubleList::SetAt(int index, int number)
{
	Node* current = head;
	for (int i = 0; i < count; i++)
	{
		if (i == index)
		{
			current->data = number;
		}
		current = current->next;
	}
}

bool DoubleList::Equals(const DoubleList& other)
{
	if (this->count == other.count)
	{
		Node* current = new Node;
		Node* current_other = new Node;
		current = head;
		current_other = other.head;
		for (int i = 0; i < count; i++)
		{
			if (current->data == current_other->data)
			{
				current = current->next;
				current_other = current_other->next;
				continue;
			}
			else
			{
				delete current;
				delete current_other;
				return false;
			}
			delete current;
			delete current_other;
			return true;
		}
	}
	else
	{
		return false;
	}
}

DoubleList& DoubleList::Clone(const DoubleList& original)
{
	this->Clear();
	Node* head = new Node;
	Node* current_original = new Node;
	current_original = original.head;
	for (int i = 0; i < original.count; i++)
	{
		if (current_original != nullptr)
		{
			this->AddToHead(current_original->data);
			current_original = current_original->next;
			this->count++;
		}
	}
	delete current_original;
	this->Reverse();
	return *this;
}

bool DoubleList::Contains(int number)
{
	int result = this->IndexOf(number);
	if (result >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

DoubleList& DoubleList::MergeWith(const DoubleList& other)
{
	Node* current_other = new Node;
	current_other = other.head;

	while (current_other != nullptr)
	{
		this->AddToTail(current_other->data);
		current_other = current_other->next;
	}
	return *this;
}

int& DoubleList::ToArray(int*& arr)
{
	Node* current = new Node;
	current = head;
	for (int i = 0; i < this->count; i++)
	{
		arr[i] = current->data;
		current = current->next;
	}
	delete current;
	return *arr;
}

bool DoubleList::operator<(const DoubleList& other)
{
	return (this->count < other.count);
}

bool DoubleList::operator>(const DoubleList& other)
{
	return (this->count > other.count);
}

bool DoubleList::operator<=(const DoubleList& other)
{
	return (this->count <= other.count);
}

bool DoubleList::operator>=(const DoubleList& other)
{
	return (this->count >= other.count);
}

bool DoubleList::operator==(const DoubleList& other)
{
	return (this->count == other.count);
}

bool DoubleList::operator!=(const DoubleList& other)
{
	return (this->count != other.count);
}

int DoubleList::operator[](int index)
{
	Node* current = new Node;
	current = head;
	for (int i = 0; i < this->count; i++)
	{
		if (i == index)
		{
			return current->data;
		}

		current = current->next;
	}
	delete current;
	return -1;
}

DoubleList& DoubleList::operator = (const DoubleList& other)
{
	if (this != &other)
	{
		this->DoubleList::Clear();
		this->DoubleList::DoubleList(other);
	}
	return *this;
}

DoubleList& DoubleList::operator +(const DoubleList& other)
{
	this->MergeWith(other);
	return *this;
}

DoubleList& DoubleList::operator +=(const DoubleList& other)
{
	this->MergeWith(other);
	return *this;
}



