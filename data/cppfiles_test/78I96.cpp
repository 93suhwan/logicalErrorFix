#include <bits/stdc++.h>
using namespace std;

set<int> countFactor(long long int n)
{
	set<int> s1;
	while(n%2 == 0)
	{
		s1.insert(2);
		s1.insert(n);
		n = n/2;
	}

	for(long long int i = 3; i*i <= n; i = i+2)
	{
		if(n%i == 0)
		{
			while(n%i == 0)
			{
				s1.insert(i);
				s1.insert(n);
				n = n/i;
			}
		}
	}
	if(n != 1) s1.insert(n);
	s1.insert(1);
	return s1;
}
int main()
{

	#ifndef ONLINE_JUDGE

	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);

	#endif
	
	long long int ntc; cin >> ntc;

	while(ntc--)
	{
		long long int n; cin >> n;
		long long int arr[n];

		for(long long int i = 0; i < n; i++) cin >> arr[i];

		long long int hcf = 0;

		for(long long int i = 0; i <= 30; i++)
		{
			long long int temp = 0;
			for(long long int j = 0; j < n; j++)
			{
				if(arr[j] & (1 << i)) temp++;
			}
			hcf = __gcd(temp, hcf);
		}

		if(hcf == 0)
		{
			for(int i = 1; i <= n; i++) cout << i << " ";
			cout << endl;
		}
		else
		{
			set<int> s1;
			s1 = countFactor(hcf);

			for(auto it = s1.begin(); it != s1.end(); it++) cout << *it << " ";
			cout << endl;
		}
		

	}


	return 0;
}