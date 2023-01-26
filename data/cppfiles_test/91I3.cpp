#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<map>
using namespace std;
using namespace __gnu_pbds;
const int mod=998244353;
#define INF 0x3f3f3f3f
#define ll long long
#define in(a) a=read()
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define drep(i,k,n) for(int i=k;i>=n;i--)
#define cl(a) memset(a,0,sizeof(a))
#define mk make_pair
#define pb push_back
#define ls(x) x<<1
#define rs(x) x<<1|1
#define debug cout<<"!!!"<<endl;
typedef pair<int,int>PII;
inline long long readll(){
    long long x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
const int maxn=1e5+7;
int a[maxn];
void solve()
{
	ll ans=0;
	int n;n=read();
	rep(i,1,n) a[i]=read();
	gp_hash_table<int,int> dp;
	for(int i=n;i>=1;--i)
	{
		gp_hash_table<int,int> &&dp2={};
		dp2[a[i]]=1;
		for(auto x:dp)
		{
			int t=(a[i]+x.first-1)/x.first;
			dp2[a[i]/t]+=x.second;
			ans=ans+(1ll)*i*x.second%mod*(t-1)%mod;
		}
		dp=move(dp2);
	}
	printf("%d\n",ans);
	return;
}
signed main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}