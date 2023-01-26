#include <bits/stdc++.h>
using namespace std;
const int P = 998244353, mod = 1e9 + 7, B = 1e6;
int m(long long d) { return (d % P + P) % P; }
long long n, cnt, s[7];
int ans;
vector<int> p[7];
void dfs0(int d, long long v) {
  cnt++, p[d].push_back(m(cnt - v));
  if (d < 6)
    for (int i = 0; i <= 9; i++) dfs0(d + 1, v * 10 + i);
}
int calc(int id, int f) {
  int ps = lower_bound(p[id].begin(), p[id].end(), P - f) - p[id].begin();
  return ((long long)f * p[id].size() + s[id] -
          (long long)P * (p[id].size() - ps)) %
         mod;
}
void dfs1(int d, long long v) {
  if (v > n) return;
  if (d >= 1) {
    if (v * B > n / 10 && v * B + B - 1 <= n) {
      int t = 1;
      for (int i = 0; i <= 6; i++)
        (ans += calc(i, m(cnt - v * t))) %= mod, t *= 10;
      for (int i = 0; i <= 6; i++) cnt += p[i].size();
      return;
    }
    (ans += m(++cnt - v)) %= mod;
  }
  for (int i = !d; i <= 9; i++) dfs1(d + 1, v * 10 + i);
}
int main() {
  scanf("%lld", &n), dfs0(0, 0);
  for (int i = 0; i <= 6; i++) {
    sort(p[i].begin(), p[i].end());
    for (int j = 0; j <= p[i].size() - 1; j++) s[i] += p[i][j];
  }
  cnt = 0, dfs1(0, 0), printf("%d\n", ans);
  return 0;
}
