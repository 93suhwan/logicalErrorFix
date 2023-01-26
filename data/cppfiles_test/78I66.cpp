//#pragma comment(linker, "/STACK:102400000,102400000")
//#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef __int64 i64;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second

typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef multiset<int> msii;
typedef multiset<ll> msll;
typedef set<int> sii;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<pll> spll;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define it_ iterator
#define r_it_ reverse_iterator



#define putt(x) cout<<#x<<" = "<<(x)<<endl;
#define MAX 100007
const ll MOD = 1000000007;	//模数,常用的还有 998244353;
const double eps = 1e-8;	//保留6位小数的精度,保留k位小数时一般取1e-(k+2);





int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	
	ll T=1;
	scanf("%lld",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		vll a(n+1),b(33);
		bool all0=true;
		ll xr=0;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			for(ll j=0;j<=30;j++)
			{
				if(a[i]&(1<<j))
					b[j]++;
			}
			if(a[i])
				all0=false;
			// cout<<(bitset<32>(a[i]))<<endl;
		}
		bool pd=false;
		// if(all0)
		// {
		// 	for(ll i=1;i<=n;i++)
		// 	{
		// 		if(pd)putchar(' ');
		// 		printf("%lld",i);
		// 		pd=true;
		// 	}
		// }
		// else
		{
			ll anss=b[0];
			for(ll j=1;j<=30;j++)
			{
				// putt(b[j]);
				if(b[j]==0)
					continue;
				if(anss==0)
					anss=b[j];
				else
					anss=__gcd(b[j-1],b[j]);
			}
			// printf(">>> %lld\n",anss);
			for(ll i=1;i<=n;i++)
			{
				if(anss%i==0)
				{
					if(pd)putchar(' ');
					printf("%lld",i);
					pd=true;
				}
			}
		}
		putchar('\n');
	}
	

	return 0;
}
/*

*/