#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define kyou using
#define mo namespace
#define kawaii std
#define chisai chrono
#define dekai __gnu_pbds;

kyou mo kawaii;
kyou mo chisai;
kyou mo dekai;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl "\n"
#define ohamachi cin.tie(0) -> sync_with_stdio(0)
#define otsumachi exit(0)
#define ll long long
#define ld double
const int MX = 200005;
const int LG = 30;
const int BLOCK = 330;
const int inf = 1e9 + 69;
const ll mod = 1e9 + 7;
const ll inv2 = (mod + 1) / 2ll;
const ll infll = 4e18 + 6969;
const short dx[] = {0, 1, 0, -1};
const short dy[] = {1, 0, -1, 0};
const ld eps = 1e-6;

class timer: high_resolution_clock{
	const time_point start_time;
public:
	timer():start_time(now()){}
	rep elapsed_time() const{ 
		return duration_cast<milliseconds>(now() - start_time).count(); 
 	}
};

int n, k, sz[MX], wt[MX];
vector<pair<int, int> > adj[MX];
bitset<MX> used;
ll ans = 0ll;

void dfs_sz(int nw, int bf){
	sz[nw] = 1;
	for(auto nx : adj[nw]) if(nx.first != bf && !used[nx.first]){
		dfs_sz(nx.first, nw);
		sz[nw] += sz[nx.first];
	}
}

int get_centroid(int nw){
	dfs_sz(nw, nw);

	int szt = sz[nw] / 2;
	for(bool f = 0; !f;){
		f = 1;
		for(auto nx : adj[nw]) if(!used[nx.first] && sz[nx.first] <= sz[nw])
			if(sz[nx.first] > szt / 2){
				f = 0;
				nw = nx.first; break;
			}
	}

	return nw;
}

struct BIT{
	pair<ll, ll> fwt[MX];
	void clear(){
		memset(fwt, 0, sizeof(fwt));
	}

	void upd(int ps, pair<ll, ll> val){
		for(ps ++; ps < MX; ps += ps & -ps){
			(fwt[ps].first += val.first) %= mod;
			if(fwt[ps].first < 0) fwt[ps].first += mod;
			fwt[ps].second += val.second;
		}
	}
	pair<ll, ll> que(int ps){
		pair<ll, ll> r = {0, 0};
		for(ps ++; ps > 0; ps -= ps & -ps){
			(r.first += fwt[ps].first) %= mod;
			if(r.first < 0) r.first += mod;
			r.second += fwt[ps].second;
		}
		return r;
	}
} fwt[2];

void solve(int nw = 1){
	nw = get_centroid(nw);
	int cent = nw;

	vector<pair<ll, pair<ll, ll> > > op;
	for(auto nx : adj[nw]) if(!used[nx.first]){
		vector<pair<int, int> > candidates;

		function <void(int, int, int, int, ll)> dfs = [&](int nw, int bf, int cl, int dp, ll wtg){
			if(dp <= k) (ans += wtg + wt[cent]) %= mod;
			candidates.push_back({dp, wtg});
			for(auto nx : adj[nw]) if(nx.first != bf && !used[nx.first])
				dfs(nx.first, nw, nx.second, dp + (cl != nx.second), wtg + wt[nx.first]);
		};

		dfs(nx.first, nw, nx.second, 0, wt[nx.first]);
		for(auto e : candidates){
			if(k >= e.first){
				pair<ll, ll> tmp = fwt[nx.second].que(k - e.first);
				(ans += tmp.first) %= mod;
				(ans += (tmp.second * 1ll * ((e.second + wt[nw]) % mod)) % mod) %= mod;
			}
			if(k >= e.first + 1){
				pair<ll, ll> tmp = fwt[1 - nx.second].que(k - e.first - 1);
				(ans += tmp.first) %= mod;
				(ans += (tmp.second * 1ll * ((e.second + wt[nw]) % mod)) % mod) %= mod;
			}
		}

		for(auto e : candidates){
			fwt[nx.second].upd(e.first, {e.second, 1});
			op.push_back({e.first, {e.second, nx.second}});
		}
	}

	for(auto i : op)
		fwt[i.second.second].upd(i.first, {-i.second.first, -1});

	used[nw] = 1;
	for(auto nx : adj[nw]) if(!used[nx.first])
		solve(nx.first);
}

int main(){
	ohamachi;

	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> wt[i];
		(ans += wt[i]) %= mod;
	}
	for(int u, v, w, i = 1; i < n; i ++){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	solve();
	cout << ans << endl;
	
	otsumachi;
}