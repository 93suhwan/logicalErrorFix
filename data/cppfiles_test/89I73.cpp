#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int leaf[200001];
vi adj[200001];

void dfs(int cur = 1, int par = 0)
{
	leaf[cur] = 1;

	for (int ch : adj[cur])
		if (ch != par)
		{
			dfs(ch, cur);

			if (leaf[ch])
				leaf[cur] = 0;
		}
}

int32_t main()
{
	FIO;
	w(t)
	{
		int n; cin >> n;

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int u = 1; u <= n - 1; ++u)
		{
			int i, j; cin >> i >> j;
			adj[i].pb(j);
			adj[j].pb(i);
		}

		dfs();

		int b = 0, l = 0;

		for (int i = 2; i <= n; ++i)
			if (leaf[i])
				l++;
			else
				b++;

		int direct_l = 0;

		for (int i : adj[1])
			direct_l += leaf[i];

		if (direct_l)
			cout << l - b << '\n';

		else
			cout << l - b + direct_l << '\n';
	}
	return 0;
}