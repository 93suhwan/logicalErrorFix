#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const ll mod = 1e9 + 7;
ll pw(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y % 2) res = res * x % mod;
    x = x * x % mod;
    y = y / 2;
  }
  return ((res % mod) + mod) % mod;
}
vector<string> colors = {"white", "yellow", "green", "blue", "red", "orange"};
ll k;
map<ll, map<string, ll>> dp;
map<ll, set<ll>> g;
void addEdge(ll u, ll v) {
  g[u].insert(v);
  g[v].insert(u);
}
map<ll, ll> cache;
ll level(ll at) {
  if (cache.count(at)) {
    return cache[at];
  }
  if (at == 1) return 0;
  return cache[at] = 1 + level(at / 2);
}
void mul(ll &x, ll y) {
  x %= mod;
  y %= mod;
  x *= y;
  x %= mod;
}
map<ll, ll> treeCache;
ll solveTree(ll k) {
  if (treeCache.count(k)) {
    return treeCache[k];
  }
  ll res = 1;
  for (ll i = 0; i < k; i++) {
    res *= pw(4, 1ll << i);
    res %= mod;
  }
  return treeCache[k] = res;
}
bool compat(const string &s1, const string &s2) {
  if (s1 == s2) return false;
  if (s1 == "white") {
    return s2 != "yellow";
  } else if (s1 == "yellow") {
    return s2 != "white";
  } else if (s1 == "green") {
    return s2 != "blue";
  } else if (s1 == "blue") {
    return s2 != "green";
  } else if (s1 == "red") {
    return s2 != "orange";
  } else if (s1 == "orange") {
    return s2 != "red";
  }
  assert(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  assert(solveTree(1) == 4);
  assert(solveTree(2) == 4 * 4 * 4);
  cin >> k;
  vector<ll> nodes;
  set<ll> assigned;
  int n;
  cin >> n;
  assert(n >= 1);
  for (int i = 0; i < n; i++) {
    ll at;
    string c;
    cin >> at;
    assigned.insert(at);
    cin >> c;
    for (auto col : colors) {
      dp[at][col] = (col == c ? 1 : 0);
    }
    nodes.push_back(at);
    while (at > 1) {
      ll p = at / 2;
      nodes.push_back(p);
      addEdge(p, at);
      at /= 2;
    }
  }
  sort(nodes.begin(), nodes.end());
  nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  reverse(nodes.begin(), nodes.end());
  int cnt = nodes.size();
  assert(cnt < 2010 * 65);
  for (ll at : nodes) {
    if (level(at) + 1 == k) {
      continue;
    }
    if (!assigned.count(at)) {
      for (auto col : colors) {
        dp[at][col] = 1;
      }
    }
    for (auto &col : colors) {
      for (ll to : {2ll * at, 2ll * at + 1}) {
        if (!g[at].count(to)) {
          mul(dp[at][col], solveTree(k - level(to)));
        } else {
          ll res = 0;
          for (auto &col2 : colors) {
            if (compat(col, col2)) {
              res += dp[to][col2];
            }
          }
          mul(dp[at][col], res);
        }
      }
    }
  }
  ll res = 0;
  for (auto &c : colors) {
    res += dp[1][c];
    res %= mod;
  }
  cout << res << endl;
  return 0;
}
