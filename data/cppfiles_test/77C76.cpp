#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e17;
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<long long> adj[1000005];
vector<bool> visited(1000005, false);
long long sz;
vector<long long> ans;
vector<long long> pp;
void dfs(long long v) {
  pp.push_back(v);
  visited[v] = true;
  for (long long u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[n][m], b[n][m], k = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        b[i][j] = k;
        k++;
      }
    }
    long long bit[n * m][4];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        long long x = a[i][j];
        if (x >= 4 and x <= 7) {
          bit[b[i][j]][3] = 0;
        }
        if (x <= 4) {
          bit[b[i][j]][3] = 0;
          bit[b[i][j]][2] = 0;
        }
        long long q = 0;
        while (x) {
          bit[b[i][j]][q] = x % 2;
          x /= 2;
          q++;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (bit[b[i][j]][0] == 0 and j > 0 and bit[b[i][j - 1]][2] == 0) {
          adj[b[i][j]].push_back(b[i][j - 1]);
          adj[b[i][j - 1]].push_back(b[i][j]);
        }
        if (bit[b[i][j]][1] == 0 and i < n - 1 and bit[b[i + 1][j]][3] == 0) {
          adj[b[i][j]].push_back(b[i + 1][j]);
          adj[b[i + 1][j]].push_back(b[i][j]);
        }
        if (bit[b[i][j]][2] == 0 and j < m - 1 and bit[b[i][j + 1]][0] == 0) {
          adj[b[i][j]].push_back(b[i][j + 1]);
          adj[b[i][j + 1]].push_back(b[i][j]);
        }
        if (bit[b[i][j]][3] == 0 and i > 0 and bit[b[i - 1][j]][1] == 0) {
          adj[b[i][j]].push_back(b[i - 1][j]);
          adj[b[i - 1][j]].push_back(b[i][j]);
        }
      }
    }
    for (long long i = 0; i < n * m; i++) {
      if (visited[i] == false) {
        dfs(i);
        ans.push_back(pp.size());
        pp.clear();
      }
    }
    long long h = ans.size();
    sort(ans.rbegin(), ans.rend());
    for (long long i = 0; i < h; i++) {
      cout << ans[i] << " ";
    }
  }
  return 0;
}
