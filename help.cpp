#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cont = 0;
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < t.size(); i++)
	{
		int j = 0;
		while(j < s.size())
		{
			if(t[i] == s[j])
			{
				cont++;
			}
			j++;

		}
		if (cont == 0)
		{
			break;
		}
	
	}
	if(cont >= t.size())
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}