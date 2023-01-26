#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define all(...) begin(__VA_ARGS__) , end(__VA_ARGS__)
#define boost {ios_base::sync_with_stdio(false); cin.tie(); cout.tie();}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
constexpr ll nax = 2e5+6969, INF = 2e9+6969;

int qq;

int main()
{
	scanf("%d", &qq);
	while(qq--)
	{
		int n;
		vi v;
		scanf("%d", &n);
		v.resize(n);
		for(auto &e: v) scanf("%d", &e);
		int sum = 0;
		for(auto e: v) sum += e;
		bool ok = 1;
		for(int i=2;i*i<=sum;i++)
		{
			if(sum % i == 0)
			{
				ok = 0;
				break;
			}
		}
		if(!ok)
		{
			printf("%d\n", n);
			for(int i=1;i<=n;i++) printf("%d ", i);
			puts("");
		}
		else
		{
			printf("%d\n", n - 1);
			for(int i=1;i<=n;i++) 
			{
				if(v[i]&1)
				{
					if(ok) 
					{
						ok = 0; 
						continue;
					}
					printf("%d ", i);
				}
				else printf("%d ", i);
			}
			puts("");
		}
		
	}
	return 0;
}
