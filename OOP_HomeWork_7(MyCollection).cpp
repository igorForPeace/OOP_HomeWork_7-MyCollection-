#include "AllLibraries.h"




int main()
{
	srand(time(0));

	MyCollection<int>* vec = new Vector;
	vec->Add(10);
	vec->Add(3);
	vec->Add(4);
	vec->Add(8);
	vec->Add(8);
	vec->Add(1);
	vec->Print_2();
	vec->Sort();
	cout << endl;
	vec->Print_2();
	cout << endl;
	
	cout << "===================================" << endl;

	MyCollection<int>* list = new List;
	for (int i = 0; i < 10; i++)
	{
		list->Add(rand() % 10);
	}
	list->Print_2();
	list->Sort();
	cout << endl;
	list->Print_2();
	list->Replace(99, 1);
	list->Print_2();
	list->Remove();
	list->Print_2();
	
	cout << "===================================" << endl;

	MyCollection<int>* dlist = new DoubleList;
	for (int i = 0; i < 10; i++)
	{
		dlist->Add(rand() % 10);
	}
	dlist->Print_2();
	dlist->Sort();
	cout << endl;
	dlist->Print_2();
	dlist->Replace(99, 1);
	dlist->Print_2();
	dlist->Remove();
	dlist->Print_2();
	dlist->Remove();
	dlist->Print_2();

	delete dlist;
	delete vec;
	delete list;
	return 0;
}