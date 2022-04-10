#include <iostream>
using namespace std;

class que
{
private:
	int arr_size;
	int start;
	int num_elem;
	int arr[100000];
public:
	que();
	que(int n);
	~que();
	void push_back(int input);
	void pop_front();
	int get_front();
	void set_front(int res);
};

que::que()
{
}

que::que(int n)
{
	arr_size = n;
	start = n / 2;
	num_elem = 0;
}

que::~que()
{
}
void que::push_back(int input)
{
	arr[(start + num_elem) % arr_size] = input;
	num_elem++;
}
void que::pop_front()
{
	if (num_elem > 0) 
	{
		start = (start + 1) % arr_size;
		num_elem--;
	}

}
int que::get_front()
{
	return ((num_elem > 0)? arr[start]:0);
}
void que::set_front(int res)
{
	this->arr[start] = res;
}
int main()
{
	int q;
	cin >> q;
	que arr_d(q);
	que arr_t(q);
	while (q--)
	{
		char type;
		cin >> type;
		int t;
		switch (type) {
		case '+':
			int d;
			cin >> d >> t;
			arr_d.push_back(d);
			arr_t.push_back(t);
			break;

		case '-':
			cin >> t;
			while (t > arr_t.get_front())
			{
				t -= arr_t.get_front();
				arr_t.pop_front();
				arr_d.pop_front();
			}

			arr_t.set_front(arr_t.get_front() - t);

			if (!(arr_t.get_front()))
			{
				arr_t.pop_front();
				arr_d.pop_front();
			}

			break;

		case '?':
			if (arr_d.get_front()) cout << arr_d.get_front() << endl;
			else cout << "empty" << endl;
			break;
		}
	}
	return 0;
}
