#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;


#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll

#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front

#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second

#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)

#define graph          vector<vector<int>>

#define sz(v) v.size()

typedef  pair<int, int>      pii;
typedef  pair<ll, ll>        pll;
typedef  pair<ll, pll>       plll;

typedef  vector<int>         vi;
typedef  vector<ll>          vll;
typedef  vector<string>      vs;
typedef  vector<double>      vd;
typedef  vector<pii>         vpii;
typedef  vector<pll>         vpll;
typedef  vector<plll>      	 vplll;
typedef  vector<string> 	 vs;
typedef  vector<char>	     vc;
typedef  vector<bool>        vb;

typedef  list<int>         li;
typedef  list<ll>          lll;
typedef  list<string>      ls;
typedef  list<double>      ldd;

typedef  map<string, int>         msi;
typedef  map<int, int>	          mii;
typedef  map<ll, ll>              mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	      mis;

typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;

typedef  priority_queue<pii, vector<pii>, greater<pii> > pqq;

#define setbits(x)      __builtin_popcountll(x)

#define zrobits(x)      __builtin_ctzll(x)

#define mod             1000000007
#define inf             1e18


/*ans=ps(ans,6);
then ans will be 6.784543*/
#define ps(x,y)         fixed<<setprecision(y)<<x

#define mk(arr,n,type)  type *arr=new type[n];

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;





void solve();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin >> t;
	while (t--) {
		solve();
		cout << endl;
	}
	return 0;
}

void swapn(ll *a, ll *b) {
	ll temp = *a;
	*a = *b;
	*b = temp;
}
void solve() {
	ll n, ans = 0;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	while (true) {
		ans++;
		ll swap = 0;
		if (ans % 2 != 0)
			for (ll i = 0; i < n; i = i + 2) {
				if (a[i] > a[i + 1]) {
					swapn(&a[i], &a[i + 1]);
					swap++;
				}
			}
		if (ans % 2 == 0)
			for (ll i = 1; i < n; i = i + 2) {
				if (a[i] > a[i + 1]) {
					swapn(&a[i], &a[i + 1]);
					swap++;
				}
			}
		if (swap == 0) {
			break;
		}
	}
	cout << ans - 1;
}