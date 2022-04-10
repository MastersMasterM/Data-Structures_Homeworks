#include <iostream>
#include<string>
using namespace std;

int elem=0;
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

Node Dummy(0);
Node* middle;
void add_middle(int x)
{
	Node* u = new Node(x);
	Node* p=middle;
	u->next = p->next;
	u->prev = p;
	p->next->prev = u;
	p->next = u;
	if (elem % 2 == 0)
	{
		middle = middle->next;
	}
	elem++;

}
void add_front(int x)
{
	Node* u = new Node(x);
	u->next = Dummy.next;
	Dummy.next->prev = u;
	u->prev = &Dummy;
	Dummy.next = u;
	if (elem % 2 == 1)
	{
		middle = middle->prev;
	}
	elem++;
}
void add_Back(int x)
{
	Node* u = new Node(x);
	u->next = &Dummy;
	u->prev = Dummy.prev;
	Dummy.prev->next = u;
	Dummy.prev = u;
	if (elem % 2 == 0)
	{
		middle = middle->next;
	}
	elem++;
}

void print_all()
{
	Node* p;
	p = Dummy.next;
	while (p->x != 0)
	{
		cout << p->x << " ";
		p = p->next;
	}
}

int main()
{
	Node* one = new Node(1);
	Dummy.next = one;
	Dummy.prev = one;
	one->next = &Dummy;
	one->prev = &Dummy;
	elem = 1;
	middle = one;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		string a;
		cin >> a;
		if (a == "Front")
		{
			add_front(i + 1);
		}
		else if(a =="Back")
		{
			add_Back(i + 1);
		}
		else if(a=="Middle")
		{
			elem == 1 ? add_Back(i + 1) : add_middle(i + 1);
		}
	}
	print_all();
	return 0;
}
