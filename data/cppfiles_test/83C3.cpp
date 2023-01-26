#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int TT = 998244353, P = 1e9 + 7, B = 1000000;
LL n;
LL cnt;
vector<int> v[10];
LL sum[10];
LL norm(LL x) {
  x %= TT;
  if (x < 0) return x + TT;
  return x;
}
void dfs1(int k1, int k2) {
  ++cnt;
  v[k1].push_back(norm(cnt - k2));
  (sum[k1] += v[k1].back()) %= P;
  if (k1 >= 6) return;
  for (int i = (0); i <= (9); ++i) {
    dfs1(k1 + 1, k2 * 10 + i);
  }
}
int ans;
void dfs2(int k1, LL k2) {
  if (k2 > n) return;
  if (k1 >= 1) {
    if (k2 * B > n / 10 && k2 * B + B - 1 <= n) {
      LL pw = 1;
      for (int i = (0); i <= (6); ++i) {
        if (i) pw *= 10;
        int now = norm(cnt - k2 * pw);
        int pos =
            lower_bound(v[i].begin(), v[i].end(), TT - now) - v[i].begin();
        ans = (ans + sum[i] + 1LL * now * ((int)(v[i]).size()) -
               1LL * (((int)(v[i]).size()) - pos) * TT) %
              P;
      }
      for (int i = (0); i <= (6); ++i) cnt += ((int)(v[i]).size());
      return;
    }
    ++cnt, (ans += norm(cnt - k2)) %= P;
  }
  for (int i = (!k1); i <= (9); ++i) dfs2(k1 + 1, k2 * 10 + i);
}
int main() {
  scanf("%lld", &n);
  dfs1(0, 0);
  for (int i = (0); i <= (6); ++i) sort(v[i].begin(), v[i].end());
  cnt = 0, dfs2(0, 0);
  printf("%d\n", ans);
  return 0;
}
