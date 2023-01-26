#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
ll a[N];
void solve()
{
	int n;
	scanf("%d",&n);
	ll sum = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(sum==0)
	{
		for(int i=1;i<=n;i++) printf("1 ");
	}
	else
	{
		ll id,ans=999999999999999999;
		for(int i=1;i<=n;i++)
		{
			if(((sum-a[i])/(__gcd(a[i],sum-a[i])))<ans)
			{
				if(((sum-a[i])/(__gcd(a[i],sum-a[i])))==0) continue;
				ans =((sum-a[i])/(__gcd(a[i],sum-a[i])));
				id = i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(id==i) printf("%lld ",-ans);
			else printf("%lld ",a[id]/(__gcd(a[id],sum-a[id])));
		}
	}
	printf("\n");
}
int main()
{
 	int t;
 	scanf("%d",&t);
 	while(t--) solve();
} 