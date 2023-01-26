#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << "[ " << *it << " = " << a << " ]";
  err(++it, args...);
}
const long long mod = 1e9 + 7;
const int N = 2e5 + 13, logN = 23;
vector<pair<int, int>> adj[N];
long long int sub[N], lvl[N], nn, par[N], dist[N][logN], done[N], A[N];
int jumps[N][logN], dt[N][logN];
void dfs_size(int x, int p) {
  sub[x] = 1;
  nn++;
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p) {
      dfs_size(next.first, x);
      sub[x] += sub[next.first];
    }
  }
}
int find_centroid(int x, int p) {
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p and sub[next.first] > nn / 2)
      return find_centroid(next.first, x);
  }
  return x;
}
void add_edge_in_ct(int p, int ch) {
  lvl[ch] = lvl[p] + 1;
  par[ch] = p;
  done[ch] = 1;
}
void dfs(int x, int p, int root_lvl, int type = -1, int run = -1) {
  bool flag = false;
  if (type == -1) flag = true;
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p) {
      int nt = type;
      if (flag) nt = next.second;
      if (flag) run = next.second;
      if (run != next.second) {
        jumps[next.first][root_lvl] = jumps[x][root_lvl] + 1;
      } else {
        jumps[next.first][root_lvl] = jumps[x][root_lvl];
      }
      run = next.second;
      dist[next.first][root_lvl] = (dist[x][root_lvl] + A[next.first]) % mod;
      dt[next.first][root_lvl] = nt;
      dfs(next.first, x, root_lvl, nt, run);
    }
  }
}
void decompose(int root, int p = 0) {
  nn = 0;
  dfs_size(root, root);
  int ct = find_centroid(root, root);
  0;
  add_edge_in_ct(p, ct);
  dfs(ct, ct, lvl[ct]);
  for (auto next : adj[ct]) {
    if (not done[next.first]) {
      decompose(next.first, ct);
    }
  }
}
template <class T = long long>
T modpow(T x, T y, T M = mod) {
  T ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % M;
    x = (x * x) % M;
    y >>= 1;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  long long int sum1 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    sum1 = (sum1 + A[i]) % mod;
  }
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  decompose(1);
  vector<pair<int, int>> child_cntb[N][2], my[N][2];
  for (int x = 1; x <= n; x++) {
    for (int y = x; y > 0; y = par[y]) {
      int type = dt[x][lvl[y]];
      if (x == y) {
        my[y][0].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
        my[y][1].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
      } else {
        my[y][type].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
      }
      0;
      type = dt[x][lvl[par[y]]];
      child_cntb[y][type].push_back(
          {jumps[x][lvl[par[y]]], dist[x][lvl[par[y]]]});
    }
  }
  auto err_arr = [&](vector<pair<int, int>> &arr) {
    for (auto c : arr) {
      cerr << "[" << c.first << " " << c.second << "]";
    }
    cerr << endl;
  };
  for (int x = 1; x <= n; x++) {
    for (int j = 0; j <= 1; j++) {
      sort((my[x][j]).begin(), (my[x][j]).end());
      sort((child_cntb[x][j]).begin(), (child_cntb[x][j]).end());
      long long int sum = 0;
      for (auto &curr : my[x][j]) {
        sum += curr.second;
        sum %= mod;
        curr.second = sum;
      }
      sum = 0;
      for (auto &curr : child_cntb[x][j]) {
        sum += curr.second;
        sum %= mod;
        curr.second = sum;
      }
    }
  }
  int L = 0;
  auto cnt_k = [&](vector<pair<int, int>> &v, int k) {
    L = 0;
    if (k < 0) return 0;
    pair<int, int> ck = {k + 1, -1};
    int l = upper_bound((v).begin(), (v).end(), ck) - v.begin() - 1;
    if (l < 0) return 0;
    L = l + 1;
    return v[l].second;
  };
  auto k_dists = [&](int x, long long int k) {
    long long int ans = cnt_k(my[x][0], k);
    ans += ((1LL * L * dist[x][lvl[x]]) % mod + (1LL * L * A[x]) % mod) % mod;
    ans %= mod;
    ans = (ans + cnt_k(my[x][1], k)) % mod;
    ans += (((1LL * (L - 1) * dist[x][lvl[x]]) % mod) +
            ((1LL * (L - 1) * A[x]) % mod)) %
           mod;
    ans %= mod;
    int ch = x, q = x;
    x = par[x];
    while (x > 0) {
      int type = dt[q][lvl[x]];
      ans += (cnt_k(my[x][type], k - jumps[q][lvl[x]]));
      ans %= mod;
      ans +=
          (((1LL * L * dist[q][lvl[x]]) % mod) + (1LL * L * A[x]) % mod) % mod;
      ans %= mod;
      ans -= (cnt_k(child_cntb[ch][type], k - jumps[q][lvl[x]]));
      ans -= ((1LL * L * dist[q][lvl[x]]) % mod + (1LL * L * A[x]) % mod) % mod;
      0;
      ans = ((ans + mod) % mod + mod) % mod;
      ans += (cnt_k(my[x][1 - type], k - 1 - jumps[q][lvl[x]]));
      ans %= mod;
      ans += ((1LL * L * dist[q][lvl[x]]) % mod + (1LL * L * A[x]) % mod) % mod;
      ans %= mod;
      0;
      if (k - 1 - jumps[q][lvl[x]] >= 0) {
        ans = (ans - A[x] - dist[q][lvl[x]] + 3 * mod) % mod;
      }
      ans %= mod;
      0;
      ans -= (cnt_k(child_cntb[ch][1 - type], k - 1 - jumps[q][lvl[x]]));
      ans -= ((1LL * L * dist[q][lvl[x]]) % mod + (1LL * L * A[x]) % mod) % mod;
      ans = ((ans + mod) % mod + mod) % mod;
      0;
      ch = x;
      x = par[x];
    }
    0;
    return ans % mod;
  };
  long long int ans = 0;
  for (int x = 1; x <= n; x++) {
    ans = (ans + k_dists(x, k)) % mod;
  }
  cout << (1LL * ((ans + sum1) % mod) * modpow<long long int>(2, mod - 2)) % mod
       << endl;
  return 0;
}
