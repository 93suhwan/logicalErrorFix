/*
           _                   _         _       __  __  _____ 
     /\   | |            /\   | |       | |     |  \/  |/ ____|
    /  \  | |__   ___   /  \  | |__   __| | ___ | \  / | |     
   / /\ \ | '_ \ / _ \ / /\ \ | '_ \ / _` |/ _ \| |\/| | |     
  / ____ \| |_) | (_) / ____ \| |_) | (_| | (_) | |  | | |____ 
 /_/    \_\_.__/ \___/_/    \_\_.__/ \__,_|\___/|_|  |_|\_____|

*/

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
const int N = 100 + 7;

void solve();

int main()
{
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int t = 1;
	 scanf("%d",&t);
	while (t--) solve();
	return 0;
}

int n,k;
vector<int> g[N];
vector<int> tmp;
vector<vector<int> > vec;

void dfs(int u,int p,int d = 0)
{
	tmp[d]++;
	for(int v:g[u])
	{
		if (v == p) continue;
		dfs(v,u,d+1);
	}
}

int add(int x,int y)
{
	int ret = ((ll)x+y+mod)%mod;
	return ret;
}

int mult(int x,int y)
{
	int ret = ((ll)x*y)%mod;
	return ret;
}

void solve()
{
	scanf("%d %d",&n,&k);
	for(int i = 1 ; i <= n ; i++) g[i].clear();
	for(int i = 0 ; i < n-1 ; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	if (k == 2)
	{
		printf("%d\n",n*(n-1)/2);
		return;
	}
	
	int ans = 0;
	for(int root = 1 ; root <= n ; root++)
	{
		vec.clear();
		for(auto u:g[root])
		{
			tmp = vector<int>(n+1,0);
			dfs(u,root);
			vec.pb(tmp);
		}
		for(int i = 0 ; i <= n ; i++)
		{
			int m = g[root].size();
			vector<vector<int> > dp(m,vector<int>(k,0));
			for(int j = 0 ; j < m ; j++)
			{
				dp[j][0] = 1;
				for(int kk = 1 ; kk <= k ; kk++)
				{
					if (j > 0) dp[j][kk] = add(dp[j-1][kk],mult(dp[j-1][kk-1],vec[j][i]));
					else if (kk == 1) dp[j][kk] = vec[j][i];
				}
			}
			ans = add(ans,dp[m-1][k]);
		}
		//cerr << ans << endl;
	}
	printf("%d\n",ans);
}
