#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int x;
	Node* next;
	Node* prev;
	Node(int x0)
	{
		x = x0;
		next = NULL;
		prev = NULL;
	}
};
class Box
{
public:
	int x;
	Node* p;
	bool reverse;
	Box()
	{
		Node* dummy = new Node(0);
		p = dummy;
		reverse = false;
	}
};

void put_book(Box* a, Box* b)
{
	// put b in a
	if (b->p->next->x)
	{
		a->p->prev->next = b->p->next;
		b->p->next->prev = a->p->prev;
		b->p->prev->next = a->p;
		a->p->prev = b->p->prev;
		b->p->next = b->p;
		b->p->prev = b->p;
	}
}
int main()
{
	int n, q, a;
	cin >> n >> q;
	string control;
	vector <Box> boxes(n);
	for (int i = 0; i < n; i++)
	{
		boxes[i].x = i+1;
		Node* first = new Node(i+1);
		boxes[i].p->next = first;
		boxes[i].p->prev = first;
		first->next = boxes[i].p;
		first->prev = boxes[i].p;
	}
	vector <int> deleted(n);
	for (int i = 0; i < n; i++)
	{
		deleted[i] = 1;
	}
	while (q--)
	{
		cin >> control;
		if (control == "Put")
		{
			int b;
			cin >> a >> b;
			put_book(&boxes[b-1], &boxes[a-1]);
		}
		else if (control == "Reverse")
		{
			cin >> a;
			Box* b = &boxes[a - 1];
			Node* first = b->p->next;
			while (first->x)
			{
				Node* n_next = first->next;
				swap(first->next, first->prev);
				first = n_next;
			}
			swap(b->p->next, b->p->prev);
		}
		else if (control == "Delete")
		{
			cin >> a;
			deleted[a-1]=0;
		}
	}
	int printed;
	for (int i = 0; i < n; i++)
	{
		printed = 0;
		Node* first = boxes[i].p->next;
		while (first->x)
		{
			if (deleted[first->x - 1])
			{
				cout << first->x << " ";
				printed++;
			}
			first = first->next;
		}
		if (printed)
		{
			cout << endl;
		}
		else
		{
			cout << "Empty" << endl;
		}
	}
}
