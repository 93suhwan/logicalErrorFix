#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=200005;
int t,n,res;
int a[N],b[N];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);res=1;
		for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
		for(int i=1;i<n;++i)a[i]=b[i+1]-b[i];--n;
		int nowg=1,len=1;
		for(int i=n;i>=1;--i) 
		{
			nowg=__gcd(a[i],nowg);
			if(nowg>1){res=max(res,++len);continue;}
			nowg=a[i];len=1;
			for(int j=i+1;j<=n;++j)
			{
				if(__gcd(a[j],nowg)>1){++len;nowg=__gcd(a[j],nowg);}
				else {res=max(res,len);break;}
			}
		}
		printf("%lld\n",res+1);
	}
	return 0;
}