#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << "[ " << *it << " = " << a << " ]";
  err(++it, args...);
}
const long long mod = 1e9 + 7;
long long mos() { return 0LL; }
template <typename T, typename... Args>
T mos(T a, Args... args) {
  return ((a + mos(args...)) % mod + mod) % mod;
}
long long mop() { return 1LL; }
template <typename T, typename... Args>
T mop(T a, Args... args) {
  return (a * mop(args...)) % mod;
}
const long long N = 2e5 + 13, logN = 23;
vector<pair<long long, long long>> adj[N];
long long sub[N], lvl[N], nn, par[N], dist[N][logN], done[N], A[N];
long long jumps[N][logN], dt[N][logN];
void dfs_size(long long x, long long p) {
  sub[x] = 1;
  nn++;
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p) {
      dfs_size(next.first, x);
      sub[x] += sub[next.first];
    }
  }
}
long long find_centroid(long long x, long long p) {
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p and sub[next.first] > nn / 2)
      return find_centroid(next.first, x);
  }
  return x;
}
void add_edge_in_ct(long long p, long long ch) {
  lvl[ch] = lvl[p] + 1;
  par[ch] = p;
  done[ch] = 1;
}
void dfs(long long x, long long p, long long root_lvl, long long type = -1,
         long long run = -1) {
  for (auto next : adj[x]) {
    if (not done[next.first] and next.first != p) {
      long long nt = type;
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
void decompose(long long root, long long p = 0) {
  nn = 0;
  dfs_size(root, root);
  long long ct = find_centroid(root, root);
  0;
  add_edge_in_ct(p, ct);
  for (auto next : adj[ct]) {
    if (not done[next.first]) {
      dist[next.first][lvl[ct]] = (dist[ct][lvl[ct]] + A[next.first]) % mod;
      dt[next.first][lvl[ct]] = next.second;
      dfs(next.first, ct, lvl[ct], next.second, next.second);
    }
  }
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
  long long n, k;
  cin >> n >> k;
  long long sum1 = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> A[i];
    sum1 = (sum1 + A[i]) % mod;
  }
  for (long long i = 1; i < n; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  decompose(1);
  vector<pair<long long, long long>> child_cntb[N][2], my[N][2];
  for (long long x = 1; x <= n; x++) {
    for (long long y = x; y > 0; y = par[y]) {
      long long type = dt[x][lvl[y]];
      if (x == y) {
        my[y][0].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
        my[y][1].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
      } else {
        my[y][type].push_back({jumps[x][lvl[y]], dist[x][lvl[y]]});
      }
      type = dt[x][lvl[par[y]]];
      child_cntb[y][type].push_back(
          {jumps[x][lvl[par[y]]], dist[x][lvl[par[y]]]});
    }
  }
  auto err_arr = [&](vector<pair<long long, long long>> &arr) {
    for (auto c : arr) {
      cerr << "[" << c.first << " " << c.second << "]";
    }
    cerr << endl;
  };
  for (long long x = 1; x <= n; x++) {
    for (long long j = 0; j <= 1; j++) {
      sort((my[x][j]).begin(), (my[x][j]).end());
      sort((child_cntb[x][j]).begin(), (child_cntb[x][j]).end());
      long long sum = 0;
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
  long long L = 0;
  auto cnt_k = [&](vector<pair<long long, long long>> &v, long long k) {
    L = 0;
    if (k < 0) return 0LL;
    pair<long long, long long> ck = {k + 1, -1};
    long long l = upper_bound((v).begin(), (v).end(), ck) - v.begin() - 1;
    if (l < 0) return 0LL;
    L = l + 1;
    return v[l].second;
  };
  auto k_dists = [&](long long x, long long k) {
    long long ans = cnt_k(my[x][0], k);
    ans = mos(ans, 1LL * L * A[x]);
    ans = mos(ans, cnt_k(my[x][1], k));
    ans = mos(ans, 1LL * (L - 1) * A[x]);
    long long ch = x, q = x;
    x = par[x];
    while (x > 0) {
      long long t = dt[q][lvl[x]];
      ans = mos(ans, cnt_k(my[x][t], k - jumps[q][lvl[x]]));
      ans = mos(ans, 1LL * L * A[x], 1LL * L * dist[q][lvl[x]]);
      ans = mos(ans, -1 * cnt_k(child_cntb[ch][t], k - jumps[q][lvl[x]]));
      ans = mos(ans, -1LL * L * A[x], -1LL * L * dist[q][lvl[x]]);
      ans = mos(ans, cnt_k(my[x][1 - t], k - 1 - jumps[q][lvl[x]]));
      ans = mos(ans, 1LL * L * A[x], 1LL * L * dist[q][lvl[x]]);
      if (L > 0) {
        ans = mos(ans, -A[x], -dist[q][lvl[x]]);
      }
      ans =
          mos(ans, -1 * cnt_k(child_cntb[ch][1 - t], k - 1 - jumps[q][lvl[x]]));
      ans = mos(ans, -1LL * L * A[x], -1LL * L * dist[q][lvl[x]]);
      ch = x;
      x = par[x];
    }
    0;
    return ans;
  };
  long long ans = 0;
  for (long long x = 1; x <= n; x++) {
    ans = (ans + k_dists(x, k)) % mod;
  }
  cout << (1LL * ((ans + sum1) % mod) * modpow<long long>(2, mod - 2)) % mod
       << endl;
  return 0;
}
