#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, M = 2e5 + 5, mod = 998244353, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = (c * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return c % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
int e[N], ne[N], h[N], idx;
int n;
int d[N];
int st[N], ans;
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs1(int x, int fa) {
  int mx = 0, cnt = 0;
  for (int i = h[x]; ~i; i = ne[i]) {
    int u = e[i];
    if (u == fa) continue;
    dfs1(u, x);
    if (st[u]) continue;
    cnt++;
  }
  if (x != 1) {
    if (!cnt)
      ans++;
    else
      st[x] = 1, ans--;
  } else {
    if (!cnt) ans++;
  }
}
int main() {
  int _ = 1;
  cin >> _;
  memset(h, -1, sizeof h);
  while (_--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      add(a, b);
      add(b, a);
    }
    dfs1(1, -1);
    cout << ans << "\n";
    ans = 0;
    for (int i = 1; i <= n; i++) st[i] = 0, h[i] = -1;
    idx = 0;
  }
}
