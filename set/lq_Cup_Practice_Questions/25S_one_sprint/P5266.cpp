#include <iostream>
#include <string>
#include <map>
using namespace std;
int q, op;//操作数，选择 
string name;
int score;
map<string, int> mp;//姓名到分数的映射 
int main()
{
	cin >> q;
	while (q--)
	{
		cin >> op;
		switch(op)
		{
			case 1:
				cin >> name >> score;
				mp[name] = score;
				cout << "OK" << endl;
				break;
			case 2:
				cin >> name;
				if (!mp.count(name))cout << "Not found" << endl;
				else
					cout << mp[name] << endl;
				break;
				
			case 3:
				cin >> name;
				if (!mp.count(name))cout << "Not found" << endl;
				else {
					mp.erase(name);
					cout << "Deleted successfully" << endl;
				}
				break;
			case 4:
				cout << mp.size() << endl;
				break;
				
		}
	}
	return 0;
}
