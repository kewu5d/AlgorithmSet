#include <iostream>
#include <set>
using namespace std;
set<int> se;
int m, op, len;
int main()
{
	cin >> m;
	while(m--)
	{
		cin >> op >> len;
		if (op == 1)
		{
			if (se.find(len) == se.end())
				se.insert(len);//find找不到就会返回end迭代器 
			else cout << "Already Exist" << '\n';
		}
		else {
			if (se.size() == 0) cout << "Empty" << '\n';
			else if (se.find(len) != se.end())
			{//找的到 
				cout << len << '\n';
				se.erase(se.find(len));
			}
			else 
			{//找不到 
				set<int>::iterator it, itl, itr;
				it = itl = itr = se.lower_bound(len);
				if (it == se.end())
				{//均小于 
					itl--;
					cout << *itl << '\n';
					se.erase(itl);
				}
				else if (it == se.begin())
				{//均大于 
					cout << *it << '\n';
					se.erase(it);
				}
				else 
				{
					itl--;
					if (*itr-len < len-*itl)
					{
						cout << *itr << '\n';
						se.erase(itr);
					}
					else
					{
						cout << *itl << '\n';
						se.erase(itl);
					}
				} 
			}
		}
	}
	return 0;
}
