#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 50;
const long long mod = 998244353;
vector<long long> g[N];
long long F[N];
long long H[N];
long long binpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret = (ret * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ret;
}
void reset(long long n) {
  for (long long i = 1; i <= n; i++) {
    g[i].clear();
    F[i] = 0;
  }
}
long long getF(long long node, long long k, long long par = -1) {
  long long val = 0;
  for (auto to : g[node]) {
    if (to == par) continue;
    long long res = getF(to, k, node);
    if (res == -1) {
      return -1;
    }
    if (res == 0) val++;
  }
  if (val % k == 0) {
    return 0;
  } else if (val % k == k - 1) {
    return 1;
  } else {
    return -1;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    F[1] = binpow(2, n - 1);
    for (long long i = 2; i <= n; i++) {
      if ((n - 1) % i == 0) {
        if (getF(1, i) != -1) F[i] = 1;
      }
    }
    for (long long i = n; i >= 1; i--) {
      H[i] = F[i];
      for (long long j = i * 2; j <= n; j += i) {
        H[i] -= H[j];
      }
    }
    for (long long i = 1; i <= n; i++) cout << H[i] << ' ';
    cout << '\n';
    reset(n);
  }
}
