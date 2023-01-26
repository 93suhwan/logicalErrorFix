#include <bits/stdc++.h>

// #include "avl.h"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
//auto x = s.find_by_order(2);s.order_of_key(6);

#define fatak                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define newl cout << "\n"
#define prDouble(x) cout << fixed << setprecision(10) << x
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define mid(l, r) (l + (r - l) / 2)

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

// Shortcuts for "common" data types in contests
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using psi = pair<string, int>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;
using vpsi = vector<psi>;

using si = set<int>;
using msi = map<string, int>;

// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define loop(i, a, b) \
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define revloop(i, a, b) \
    for (int i = int(a); i >= int(b); i--) // a to b, and variable i is local!
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvpii(c, it) \
    for (vpii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 1000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127     // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers
//priority_queue<int> q;
// priority_queue<int,vector<int>,greater<int>> q;
const int mod = 1'000'000'007;
const int N = 3e5;
vi g[N];
int a[N];
ll binexp(ll a, ll b);//binary exponentiation
bool comp(pii &a, pii &b); //comaprator
void ipgraph(int n, int m);// input graph edgelist
void dfs(int u, int par);

/* _______________________________________________________________________________ */



void solve()

{
    int n;
    cin >> n;
    string p1,p2;
    cin >> p1 >> p2;
    int ans{};
    loop(i,0,n-1){
        if(p2[i]=='0') continue;
        if(p1[i]=='0') {ans+=1; continue;}
        if(i>=1 && p1[i-1]=='1'){
            ans+=1; p1[i-1]=='2';
            continue;
        }
        if(i<n-1 && p1[i+1]=='1'){ans+=1; p1[i+1]=='2'; continue;}

    }
    cout << ans << endl;


}

int main()
{
    fatak;
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    // t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}

/* ________________________________________________________________________________ */

ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool comp(pii &a, pii &b)
{
    return a.second < b.second;
}
void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/