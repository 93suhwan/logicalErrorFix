#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long a, c;
	while (n--)
	{
		char b[100] = { 0 };
		//char d[100] = { 0 };
		cin >> a >> c;
		long long i = 0;
		bool flag = false;
		long long count = 0;
		long long tempa = a;
		long long tempc = c;
		long long count1 = 0,count2=0;
		while (tempa)
		{
			count1++;
			tempa /= 10;
		}
		while (tempc)
		{
			count2++;
			tempc /= 10;
		}
		while (a!=0||c!=0)
		{
			long long temp1 = a % 10;
			long long temp2 = c % 10;
			if (temp1 > temp2)
			{
				temp2 = c % 100;
				c /= 100;
				a /= 10;
				count++;
			}
			else
			{
				a /= 10;
				c /= 10;
			}
			long long temp3 = temp2 - temp1;
			if (temp3 > 10||temp3<0)
				flag = true;
			b[i] = temp3 + '0';
			i++;
		}

		_strrev(b);
		//cout << count1 << " " << count << " " << count2 << endl;
		if (flag)
			cout << -1 << endl;
		else
		{
			if (b[0] == '0')
			{
				for (int j = 1; j < i; j++)
				{
					cout << b[j];
				}
				cout << endl;
			}
			else
			{
				for (int j = 0; j < i; j++)
				{
					cout << b[j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}