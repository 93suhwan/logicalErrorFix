#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,n;
		cin>>n;
		for(int i=6;i<=n;i++)
		{
			if(n%i==0)
			{
				c=n/i;
			for(int j=2;j<=(i-1)/2;j++)
			{
				if(__gcd(j,i-1-j)==1)
				{
					printf("%d %d %d\n",c*j,c*i-1-j,c);
					break;
				}
			}
			break;
			}
		}
	}
	return 0;
}
