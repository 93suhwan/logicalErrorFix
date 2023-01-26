#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define FOR(i,f,n) for(int i=f;i<n;i++)
#define FORI(i,f,n) for(int i=f;i>=n;i--)
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
#define alli(a) (a).rbegin(),(a).rend()
#define approx(a) fixed<<setprecision(a)
#define trav(a,x) for(auto& a : x)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,bool> pib;
typedef pair<ll,bool> plb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <class T> void ckmax(T &a, const T &b) { a = max(a, b); }
 
template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T> void read(T &x) {cin>>x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {trav(x, v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
 
template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout<<x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {trav(x, v) pr(x, ' '); ps();}
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

void solve(){
	int n; read(n);
	vi v(n); read(v);
	int ans = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if(cur < v[i] - 1){
			ans += v[i] - cur - 1;
		}
		cur = v[i];
	}
	ps(ans);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}

