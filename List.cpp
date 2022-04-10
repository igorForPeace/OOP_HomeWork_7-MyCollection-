#include "List.h"

void List::Add(int number)
{
	List::AddToHead(number);
}

void List::Remove()
{
	List::DeleteFromTail();
}

void List::Print_2()
{
	List::Print();
}

void List::Search(int value)
{
	List::IndexOf(value);
}

void List::Replace(int value, int index)
{
	List::DeleteByIndex(index);
	List::InsertInto(value, index);
}
void List::Sort()
{
	List::SortAsc();
}

List::List()
{
	this->count = 0;
	head = nullptr;
}

List::List(const List& original)
{
	Node* current = new Node;
	current = original.head;
	count = 0;

	for (int i = 0; i < original.count; i++)
	{
		this->AddToHead(current->data);
		current = current->next;
		count++;
	}
	this->Reverse();
	delete current;
}

List::~List()
{
	Clear();
}

void List::AddToHead(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	newElem->next = head;
	if (head == nullptr)
	{
		tail = newElem;
	}
	head = newElem;
	count++;
}

void List::AddToTail(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	if (head == nullptr)
	{
		tail = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}

void List::InsertInto(int data, int position)
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
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i != position)
	{
		beforeNew = beforeNew->next;
		++i;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;
	count++;
}

void List::DeleteFromHead()
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

void List::DeleteFromTail()
{
	if (count == 0) {
		// cout << "Empty list!\n";
		return;
	}
	DeleteByIndex(count - 1);
}

void List::DeleteByIndex(int position)
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
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

void List::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}

void List::Print() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int List::GetCount() const
{
	return count;
}

int List::IndexOf(int data) const
{
	if (count == 0)
	{
		// cout << "Empty list!\n";
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

bool List::IsEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::Reverse()
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
	head = prev;
}

void List::SortAsc()
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

void List::SortDesc()
{
	SortAsc();
	Reverse();
}

void List::Shuffle()
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

void List::SetAt(int index, int number)
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

bool List::Equals(const List& other)
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

List& List::Clone(const List& original)
{
	this->Clear();
	Node* head = new Node;
	Node* current_original = new Node;
	current_original = original.head;
	for (int i = 0; i < original.count; i++)
	{
		this->AddToHead(current_original->data);
		current_original = current_original->next;
		this->count++;
	}
	delete current_original;
	this->Reverse();
	return *this;
}

bool List::Contains(int number)
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

List& List::MergeWith(const List& other)
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

int& List::ToArray(int*& arr)
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

bool List::operator<(const List& other)
{
	return (this->count < other.count);
}

bool List::operator>(const List& other)
{
	return (this->count > other.count);
}

bool List::operator<=(const List& other)
{
	return (this->count <= other.count);
}

bool List::operator>=(const List& other)
{
	return (this->count >= other.count);
}

bool List::operator==(const List& other)
{
	return (this->count == other.count);
}

bool List::operator!=(const List& other)
{
	return (this->count != other.count);
}

int List::operator[](int index)
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

List& List::operator = (const List& other)
{
	if (this != &other)
	{
		this->List::Clear();
		this->List::List(other);
	}
	return *this;
}

List& List::operator +(const List& other)
{
	this->MergeWith(other);
	return *this;
}

List& List::operator +=(const List& other)
{
	this->MergeWith(other);
	return *this;
}
