#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const long long mod = 1e9 + 7LL;
long long inv(long long x) {
  long long at = mod - 2, rs = 1;
  while (at) {
    if (at & 1) rs = (rs * x) % mod;
    x = (x * x) % mod;
    at >>= 1LL;
  }
  return rs;
}
long long fat[N], ifat[N];
long long comb(int n, int m) {
  if (n < m) return 0;
  return ((fat[n] * ifat[m]) % mod * ifat[n - m]) % mod;
}
vector<int> lista[N];
int vis[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  fat[0] = 1;
  ifat[0] = 1;
  for (int i = 1; i < N; ++i) {
    fat[i] = (fat[i - 1] * (long long)i) % mod;
    ifat[i] = inv(fat[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> n >> c;
    for (int i = 0; i <= n; ++i) {
      lista[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      lista[a].push_back(b);
      lista[b].push_back(a);
    }
    long long ans = 0;
    if (c == 2) {
      cout << comb(n, 2) << "\n";
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      queue<int> f, f1;
      f.push(i);
      vis[i] = i;
      for (int j = 1; j <= n; ++j) {
        while (!f.empty()) {
          int u = f.front();
          f.pop();
          for (int v : lista[u])
            if (vis[v] != i) {
              vis[v] = i;
              f1.push(v);
            }
        }
        ans = (ans + comb(f1.size(), c)) % mod;
        swap(f1, f);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
