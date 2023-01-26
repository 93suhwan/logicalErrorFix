#include <bits/stdc++.h>
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
using namespace std;
long long ksm(long long a, long long b) {
  if (!b) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 1000000007;
  if (b & 1) ns = ns * a % 1000000007;
  return ns;
}
int x[7005], y[7005];
int n;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int cnt[10][10], d[7005][7005];
long long ans;
pair<int, int> g[7005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    cnt[x[i] % 4][y[i] % 4]++;
    g[i] = make_pair(x[i] % 4, y[i] % 4);
  }
  vector<pair<int, int> > p{{0, 0}, {0, 2}, {2, 0}, {2, 2}};
  for (auto x : p)
    for (auto y : p)
      for (auto z : p)
        if (x <= y && y <= z) {
          int d1 = (x == y) ? 0 : 2, d2 = (y == z) ? 0 : 2,
              d3 = (x == z) ? 0 : 2;
          int c1 = cnt[x.first][x.second], c2 = cnt[y.first][y.second],
              c3 = cnt[z.first][z.second];
          if ((d1 + d2 + d3) % 4 == 0) {
            if (x == y && y == z) {
              ans += (long long)c1 * (c1 - 1) * (c1 - 2) / 6;
            } else if (x == y) {
              ans += (long long)c1 * (c1 - 1) / 2 * c3;
            } else if (y == z) {
              ans += (long long)c1 * c3 * (c3 - 1) / 2;
            } else {
              ans += (long long)c1 * c2 * c3;
            }
          }
        }
  printf("%lld\n", ans);
}
