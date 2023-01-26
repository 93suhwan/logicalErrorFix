#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; //required

// template <typename T> using ordered_set =  tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>;

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target(                                                            \
	"sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define mod (998244353)
#define pii pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define f first
#define s second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define print(vec, l, r)                                                       \
	for (int i = l; i <= r; i++)                                               \
		cout << vec[i] << " ";                                                 \
	cout << endl;
#define forf(i, a, b) for (int i = (a); i < (b); i++)
#define forr(i, a, b) for (ll i = (a); i > (b); i -= 1)
#define input(vec, N) for (int i = 0; i < (N); i++) cin >> vec[i];                                            
typedef long long ll;
#define ld long double
const int N = 1e5+50;
const int MAXK = 12;
const ll INF = 1e15;

const int RANDOM =
	chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};


ll expo_pow(ll x, ll y) {
	if (y == 0)
		return 1;
	y = y % (mod - 1);
	x %= mod;
	if (y == 0)
		y = mod - 1;
	ll res = 1;
	while (y) {
		if (y & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}

ll modInverse(ll a, ll m = mod) {
	return expo_pow(a, m - 2);
}






void solve(int te){

    ll p;
    cin>>p;

    cout<<(p-1)<<" "<<(p-1)/2<<'\n';
   
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	// freopen("f.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	cin >> T;
  int t=1;
	// sieve();
	while (t<=T) {
    //cout<<"Case #"<<t<<": ";
		solve(t);
    t++;
	}
}