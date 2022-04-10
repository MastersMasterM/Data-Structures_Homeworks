#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	int n,q;
	string req;
	unordered_map<int,int> arr;
	cin >> n;
	while (n--)
	{
		cin >> req;
		if (req == "Add")
		{
			cin >> q;
			auto search = arr.find(q);
			if (search == arr.end())
			{
				arr[q] = 1;
			}
			else
			{
				search->second = search->second + 1;
			}
				
		}
		else if (req == "Remove")
		{
			cin >> q;
			auto search = arr.find(q);
			if (search != arr.end())
			{
				search->second = search->second - 1;
				if(search->second ==0)
					arr.erase(q);
			}
				
		}
		else if (req == "Count")
		{
			cin >> q;
			auto search = arr.find(q);
			if (search != arr.end())
			{
				cout << search->second << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}
}

