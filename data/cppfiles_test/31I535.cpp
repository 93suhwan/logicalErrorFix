#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define closeSync ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define multiCase int TT;scanf("%d",&TT);for(int tt=1;tt<=TT;tt++)
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define ll long long
#define P pair<int,int>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5+5;
ll n;
ll a[maxn];
ll ans[maxn];
ll vis[200005];
ll lcm(ll a,ll b)
{
	return a*b/__gcd(a,b);
}
vector<ll>v[10005];
int main()
{
	closeSync;
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		rep(i,1,10000)
		{
			v[i].clear();
		}
		rep(i,1,n)
		{
			vis[i]=0;
			cin>>a[i];
			ans[i]=0;
			if(n%2)
			{
				ll q=a[i];
				if(q<0)q=-q;
				for(ll j=2;j<=sqrt(q);j++)
				{
					if(q%j==0)
					{
						v[j].pb(i);
						while(q%j==0)
						{
							q/=j;
						}
					}
					if(q<=1)break;
				}
				v[q].pb(i);
			}
		}
		if(n%2==0)
		{
			rep(i,1,n/2)
			{
				ll flag1=0,flag2=0;
				if(a[i]<0)a[i]=-a[i],flag1=1;
				if(a[n-i+1]<0)a[n-i+1]=-a[n-i+1],flag2=1;
				ll g=lcm(a[i],a[n-i+1]);
				ans[i]=g/a[i];
				ans[n-i+1]=g/a[n-i+1];
				if(flag1==flag2)ans[i]=-ans[i];
			}
		}
		else
		{
			rep(i,2,10000)
			{
				if(v[i].size()>=3)
				{
					//cout<<i<<endl;
					rep(j,0,2)
					{
						vis[v[i][j]]=1;
						//cout<<v[i][j]<<' ';
					}
					//cout<<endl;
					ll flag1=0,flag2=0,flag3=0;
					if(a[v[i][0]]<0)a[v[i][0]]=-a[v[i][0]],flag1=1;
					if(a[v[i][1]]<0)a[v[i][1]]=-a[v[i][1]],flag2=1;
					if(a[v[i][2]]<0)a[v[i][2]]=-a[v[i][2]],flag3=1;
					ll g=lcm(a[v[i][0]],a[v[i][1]]);
					g=lcm(g,a[v[i][2]]);
					ans[v[i][2]]=g/__gcd(a[v[i][2]],g)*2;
					ans[v[i][0]]=g/__gcd(a[v[i][0]],g);
					ans[v[i][1]]=g/__gcd(a[v[i][1]],g);
					if(flag1==1)ans[v[i][0]]=-ans[v[i][0]];
					if(flag2==1)ans[v[i][1]]=-ans[v[i][1]];
					if(flag3==0)ans[v[i][2]]=-ans[v[i][2]];
					break;
				}
			}
			ll l=1,r=n;
			//cout<<vis[1]<<endl;
			while(l<r)
			{
				//cout<<l<<' '<<r<<endl;
				while(vis[l])
				{
					l++;
					//cout<<l<<endl;
				}
				while(vis[r])
				{
					r--;
				}
				if(l>=r)break;
				//cout<<l<<' '<<r<<endl;
				ll flag1=0,flag2=0;
				if(a[l]<0)a[l]=-a[l],flag1=1;
				if(a[r]<0)a[r]=-a[r],flag2=1;
				ll g=lcm(a[l],a[r]);
				ans[l]=g/a[l];
				ans[r]=g/a[r];
				if(flag1==flag2)ans[l]=-ans[l];
				l++;
				r--;
			}
		}
		rep(i,1,n)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}