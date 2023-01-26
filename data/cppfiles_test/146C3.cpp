#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using ld = long double;
const long long N = 2e5 + 10, mod = 1e9 + 7;
const LL INF = 1e16;
long long dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
long long ne[N], pre[N], p[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> p[i];
    pre[p[i]] = i;
  }
  long long len = sqrt(n);
  for (long long i = 1; i <= n; i++) {
    long long x = i;
    for (long long j = 1; j <= len; j++) {
      x = p[x];
    }
    ne[i] = x;
  }
  while (q--) {
    long long op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      swap(p[x], p[y]);
      pre[p[x]] = x;
      pre[p[y]] = y;
      long long a = x;
      for (long long j = 1; j <= len; j++) a = p[a];
      ne[x] = a;
      for (long long j = 1; j <= len; j++) {
        x = pre[x];
        a = pre[a];
        ne[x] = a;
      }
      a = y;
      for (long long j = 1; j <= len; j++) a = p[a];
      ne[y] = a;
      for (long long j = 1; j <= len; j++) {
        y = pre[y];
        a = pre[a];
        ne[y] = a;
      }
    } else {
      while (y >= len) {
        x = ne[x];
        y -= len;
      }
      for (long long i = 1; i <= y; i++) {
        x = p[x];
      }
      cout << x << '\n';
    }
  }
}
