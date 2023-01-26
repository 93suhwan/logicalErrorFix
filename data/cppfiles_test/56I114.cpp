#include <bits/stdc++.h>
using namespace std;
void solve();
mt19937 rnd(2007);
signed main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  swap(rng, rnd);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
const long long mod = (long long)1e9 + 7;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return res;
}
long long get_col(string s) {
  if (s[0] == 'w' || s[0] == 'y') return 0;
  if (s[0] == 'g' || s[0] == 'b') return 1;
  return 2;
}
unordered_map<long long, long long> col0;
vector<long long> col;
vector<vector<long long>> g;
vector<vector<long long>> mem;
long long get_col(long long v, long long c) {
  if (col[v] != -1 && col[v] != c) {
    return 0;
  }
  if (mem[v][c] != -1) {
    return mem[v][c];
  }
  long long ans = 1;
  for (auto u : g[v]) {
    long long sum = 0;
    for (long long(c2) = 0; (c2) < (3); ++(c2)) {
      if (c2 != c) {
        sum += get_col(u, c2);
        sum %= mod;
      }
    }
    ans *= sum;
    ans %= mod;
  }
  return mem[v][c] = ans;
}
void solve() {
  long long n;
  cin >> n;
  long long edges_count = (1ll << n) - 2;
  long long k;
  cin >> k;
  vector<pair<long long, long long>> e;
  vector<long long> vertex = {1};
  for (long long(qwe) = 0; (qwe) < (k); ++(qwe)) {
    long long v;
    cin >> v;
    string col_;
    cin >> col_;
    col0[v] = get_col(col_);
    while (v != 1) {
      vertex.push_back(v);
      e.push_back({v, v / 2});
      v /= 2;
    }
  }
  sort((e).begin(), (e).end());
  e.resize(unique((e).begin(), (e).end()) - e.begin());
  edges_count = edges_count - (long long)(e).size();
  long long vertex_count = (1ll << n) - 1 - k;
  sort((vertex).begin(), (vertex).end());
  vertex.resize(unique((vertex).begin(), (vertex).end()) - vertex.begin());
  g.resize((long long)(vertex).size());
  col.assign((long long)(vertex).size(), -1);
  mem.resize((long long)(vertex).size(), vector<long long>(3, -1));
  for (long long(i) = 0; (i) < ((long long)(vertex).size()); ++(i)) {
    col[i] = col0[vertex[i]];
  }
  for (auto i : e) {
    long long v = i.second;
    v = lower_bound((vertex).begin(), (vertex).end(), v) - vertex.begin();
    long long u = i.first;
    u = lower_bound((vertex).begin(), (vertex).end(), u) - vertex.begin();
    g[v].push_back(u);
  }
  long long res = get_col(0, 0) + get_col(0, 1) + get_col(0, 2);
  res %= mod;
  long long ans = res * binpow(2, vertex_count) % mod;
  ans *= binpow(2, edges_count);
  ans %= mod;
  cout << ans << '\n';
}
