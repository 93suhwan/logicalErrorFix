#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
#define ar array
#define pb push_back
#define fi first
#define se second
#define sz size
#define mp make_pair
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define int_max numeric_limits<int>::max()
#define int_min numeric_limits<int>::min()
#define ll_max numeric_limits<ll>::max()
#define ll_min numeric_limits<ll>::min()

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define im(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// custom sort example
//sort(all(a), [ ]( const auto& c, const auto& d) {
	//if (c.fi.se != d.fi.se) {
		//return c.fi.se < d.fi.se; // lower first
	//}
	//if (c.fi.fi != d.fi.fi) {
		//return c.fi.fi > d.fi.fi; // higher first
	//}
	//return c.se > d.se; // higher first
//});

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int minCutBfs(vector<int> adj[], int s, int t, vector<int>& parent, int n, map<pii, int>& m) {
    queue <int> q;
    q.push(s);
    set<int> vis;
    vis.insert(s);
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j : adj[u]) {
			if (vis.find(j) == vis.end() && m[{u, j}] > 0) {
				q.push(j);
                parent[j] = u;
                vis.insert(j);
			}
		}
    }
    return vis.find(t) != vis.end();
}

void minCutDfs(vector<int> adj[], int s, vector<bool>& visited, map<pii, int>& m) {
    visited[s] = true;
	for (int j : adj[s]) {
		if (!visited[j] && m[{s, j}] > 0) {
			minCutDfs(adj, j, visited, m);
		}
	}
}

void minCut(vector<int> adj[], int s, int t, int n, map<pii, int>& m2) {
    int u, v, res = 0;
    vector<pii> resv;
    map<pii, int> m = m2;
    vector<int> parent(t + 5);
    while (minCutBfs(adj, s, t, parent, n, m)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, m[{u, v}]);
        }
		res = res + path_flow;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            m[{u, v}] -= path_flow;
            m[{v, u}] += path_flow;
        }
    }
    vector<bool> visited(n);
    minCutDfs(adj, s, visited, m);
	for (auto it = m2.begin(); it != m2.end(); it++) {
		if (visited[it->fi.fi] && !visited[it->fi.se] && it->se > 0) {
			resv.pb(it->fi);
		}
	}
	debug() << res;
	debug() << resv;
    return;
}

vector<int> sieve(int n) {
	n = n + 5;
	vector<int> spf(n);
    for (int i = 1; i < n; i++) {
        spf[i] = i;
	}
    for (int i = 4; i < n; i += 2) {
        spf[i] = 2;
	}
    for (int i = 3; i * i < n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
				}
			}
        }
    }
    return spf;
} 
  
vector<int> getFactorization(int x, vector<int>& spf) { 
    vector<int> ret;
    while (x != 1) {
		ret.pb(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

struct Node {
	int x, y, k, val;
	bool operator<(const Node& rhs) const {
        return val < rhs.val;
    }
};

template <class T>
auto lbf(const std::set<std::pair<T, T>>& s, T first)
{
   static constexpr T min = std::numeric_limits<T>::min();

   return s.lower_bound({first, min});
}

int find_set(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
	}
    return parent[v] = find_set(parent[v], parent);
}
 
void union_sets(int a, int b, vector<int>& parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        parent[b] = a;
	}
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

ll MOD = 10000000007;

ll pw(ll n, ll k) {
	ll r = 1;
	for(; k; k >>= 1) {
		if(k&1) r = r * n % MOD;
		n = n * n % MOD;
	}
	return r;
}
ll inv(ll n) { return pw(n, MOD-2); }

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<pii> a(n);
	vector<int> res(32, -1), b(n);
	for (int i = 1; i < n; i++) {
		cout << "and" << 1 << " " << (i + 1) << endl;
		int pom1, pom2;
		cin >> pom1;
		cout << "or" << 1 << " " << (i + 1) << endl;
		cin >> pom2;
		a[i] = {pom1, pom2};
		for (int j = 0; j < 32; j++) {
			if (((1 << j) & pom1) != 0) {
				res[j] = 1;
			}
			if (((1 << j) & pom2) == 0) {
				res[j] = 0;
			}
		}
	}
	cout << "and" << 2 << " " << 3 << endl;
	int pom1, pom2;
	cin >> pom1;
	cout << "or" << 2 << " " << 3 << endl;
	cin >> pom2;
	for (int j = 0; j < 32; j++) {
		if (res[j] == -1) {
			if (((1 << j) & pom1) != 0) {
				res[j] = 0;
			} else {
				res[j] = 1;
			}
		}
	}
	int act = 0;
	for (int j = 0; j < 32; j++) {
		if (res[j] == 1) {
			act = act + pw(2, j);
		}
	}
	b[0] = act;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 32; j++) {
			if (res[j] == 0) {
				// check or
				if (((1 << j) & a[i].se) != 0) {
					b[i] = b[i] + pw(2, j);
				}
			} else {
				//check and
				if (((1 << j) & a[i].fi) != 0) {
					b[i] = b[i] + pw(2, j);
				}
			}
		}
	}
	sort(all(b));
	cout << "finish " << b[k - 1] << endl;
}
