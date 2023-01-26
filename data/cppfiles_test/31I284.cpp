#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
ll a[N];
void solve()
{
	int n;
	cin>>n;
	ll sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(!sum)
	{
		for(int i=1;i<=n;i++) cout<<1<<" ";
	}
	else
	{
		ll id,ans=999999999999999;
		for(int i=1;i<=n;i++)
		{
			if(((sum-a[i])/(__gcd(a[i],sum-a[i])))<ans)
			{
				ans =((sum-a[i])/(__gcd(a[i],sum-a[i])));
				id = i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(id==i) cout<<(-ans)<<" ";
			else cout<<a[id]/(__gcd(a[id],sum-a[id]))<<" ";
		}
	}
	cout<<endl;
}
int main()
{
 	int t;
 	cin>>t;
 	while(t--) solve();
} 