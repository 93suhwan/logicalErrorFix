//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
#define int int64_t
#define span(a) begin(a), end(a)
constexpr int mod = 1e9 + 7;
constexpr int lim = 101;

int fact[lim + 1], invfact[lim + 1];

auto power(int base, int exp) {
  int result = 1;
  while(exp) {
    if(exp & 1) (result *= base) %= mod;
    (base *= base) %= mod;
    exp >>= 1;
  }
  return result;
}

inline int bin(int n, int r) {
  if(r > n) return 0; 
  return ((fact[n] * invfact[r]) % mod * invfact[n - r]) % mod;
}

auto preprocess(int n) {
  int inv[n + 1];
  inv[0] = inv[1] = 1;
  for(int i = 2; i <= n; ++i) {
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  }
  invfact[0] = invfact[1] = 1;
  for(int i = 2; i <= n; ++i) {
    invfact[i] = (invfact[i - 1] * inv[i]) % mod;
  }
  fact[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}

int d[lim];
vector<int> adj[lim];

void dfs(int u, int p, int l) {
  d[l]++;
  for(auto& v: adj[u]) {
    if(v != p) {
      dfs(v, u, l + 1);
    }
  }
}

void hike() {
  int n, k; cin >> n >> k;
  for(int i = 0; i + 1 < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int count = 0;
  for(int i = 1; i <= n; ++i) {
    dfs(i, 0, 0);
    for(int j = 0; j < n; ++j) {
      (count += bin(d[j], k)) %= mod;
    }
    memset(d, 0, sizeof d);
  }
  cout << count << "\n";
  for(int i = 1; i <= n; ++i) {
    adj[i].clear();
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  preprocess(lim);
  int t = 1; cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..