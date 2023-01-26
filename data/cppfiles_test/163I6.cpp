#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define int long long
#define ld long double

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

#define vl vector<ll>
#define vi vector<int>
#define vd vector<ld>
#define vpi vector<pi>
#define vpl vector<pl>
#define vpd vector<pd>

template<class T> using pq = priority_queue<T>;
template<class T> using pqr = priority_queue<T, vector<T>, greater<T>>;

#define pb push_back
#define loop(i,a,b) for(ll i =a; i<b; ++i)
#define loop1(i,a,b) for(ll i=a; i>b; --i)
#define ff first
#define ss second
#define mk make_pair
#define trac(a,v) for(auto& a:v)
#define trav(a,v) for(auto a:v)
#define endl '\n'

const int mod = 1e9+7;
const int mod1 = 998244353;

int power(int x, int y)
{
    int res = 1;

    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

int powermod(ll x, ll y, ll mod)
{
    int res = 1;

    while (y > 0) {
        if (y & 1)
            res = (res * x)%mod;
        y = y >> 1;
        x = (x * x)%mod;
    }
    return res;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
string direct = "DRUL";

void arigato(int test) {

	int n,m,a,b,c,d,p;
	cin>>n>>m>>a>>b>>c>>d>>p;

	p = (p * powermod(100,mod-2,mod))%mod;

	set<pair<pi,pi>> mp;
	vector<pair<pi,pi>> state;

	int dr = 1;
	int dc = 1;

	mp.insert({{a,b},{dr,dc}});
	state.pb({{a,b},{dr,dc}});

	while (true) {
		a += dr;
		b += dc;

		if (a > n) {
			a -= 2;
			dr = -1;
		}
		if (a <= 0) {
			a += 2;
			dr = 1;
		}
		if (b > m) {
			b -= 2;
			dc = -1;
		}
		if (b <= 0) {
			b += 2;
			dc = 1;
		}

		if (mp.count({{a,b},{dr,dc}})) break;

		mp.insert({{a,b},{dr,dc}});
		state.pb({{a,b},{dr,dc}});
	}

	pair<pi,pi> cur = {{a,b},{dr,dc}};

	vector<pair<pi,pi>> pth,cyc;
	int fl = 0;

	loop(i,0,state.size()) {
		if (cur == state[i])
			fl = 1;

		if (fl)
			cyc.pb(state[i]);
		else
			pth.pb(state[i]);
	}

	int r = 1;
	ll ans = 0;

	loop(i,0,pth.size()) {
		if (pth[i].ff.ff == c || pth[i].ff.ss == d) {
			ans += (r * p * i)%mod;
			ans %= mod;
			r = (r * ((mod + 1 - p)%mod))%mod;
		}
	}



	int r1 = 1;
	ll ans1 = 0;
    loop(i,0,cyc.size()) {
		if (cyc[i].ff.ff == c || cyc[i].ff.ss == d) {
			ans1 += (r1 * p * i)%mod;
			ans1 %= mod;
			r1 = (r1 * ((mod + 1 - p)%mod))%mod;
		}
	}

	ans1 = (ans1 + (cyc.size() * r1)%mod)%mod;
    ans1 = (ans1 * powermod((mod + 1 - r1)%mod,mod-2,mod))%mod;

	ll tot = (ans + (r * (pth.size() + ans1)%mod)%mod)%mod;

	cout<<tot<<endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    int test = t;
    while (t--) {
        arigato(test - t);
        //cout<<endl;
    }

	return 0;
}
