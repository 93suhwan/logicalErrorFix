#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int T, n, m;
vector<int> a[500005], prex[500005], sufx[500005], pren[500005], sufn[500005];
char ans[500005];
void solve() {
  for (int(i) = (1); (i) <= (n); (i)++)
    a[i].clear(), prex[i].clear(), sufx[i].clear(), pren[i].clear(),
        sufn[i].clear();
  for (int(i) = (1); (i) <= (n); (i)++) ans[i] = 0;
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (n); (i)++)
    a[i].resize(m + 1), prex[i].resize(m + 1), sufx[i].resize(m + 1),
        pren[i].resize(m + 1), sufn[i].resize(m + 1);
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++) scanf("%d", &a[i][j]);
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++)
      prex[i][j] = max(prex[i][j - 1], a[i][j]);
  for (int(i) = (1); (i) <= (n); (i)++) {
    sufx[i][m] = a[i][m];
    for (int(j) = (m - 1); (j) >= (1); (j)--)
      sufx[i][j] = max(sufx[i][j + 1], a[i][j]);
  }
  for (int(i) = (1); (i) <= (n); (i)++) pren[i][0] = inf;
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (m); (j)++)
      pren[i][j] = min(pren[i][j - 1], a[i][j]);
  for (int(i) = (1); (i) <= (n); (i)++) {
    sufn[i][m] = a[i][m];
    for (int(j) = (m - 1); (j) >= (1); (j)--)
      sufn[i][j] = min(sufn[i][j + 1], a[i][j]);
  }
  for (int(j) = (1); (j) <= (m - 1); (j)++) {
    for (int(i) = (1); (i) <= (n); (i)++) ans[i] = 'B';
    vector<pair<pair<int, int>, int>> seg;
    for (int(i) = (1); (i) <= (n); (i)++) {
      seg.push_back(make_pair(make_pair(sufn[i][j + 1], sufx[i][j + 1]), i));
    }
    sort(seg.begin(), seg.end());
    int u = 0, lel = inf, ler = 0;
    vector<int> suf;
    suf.resize(n + 1);
    suf[n] = prex[seg.back().second][j];
    for (int(i) = (n - 1); (i) >= (1); (i)--)
      suf[i] = max(suf[i + 1], prex[seg[i - 1].second][j]);
    for (int(i) = (0); (i) < (seg.size()); (i)++) {
      if (i > 0) {
        if (seg[i].first.first > u) {
          if (lel > suf[i + 1]) {
            puts("YES");
            printf("%s %d\n", ans + 1, j);
            return;
          }
        }
      }
      u = max(seg[i].first.second, u);
      int id = seg[i].second;
      ans[id] = 'R';
      lel = min(lel, pren[id][j]);
    }
  }
  puts("NO");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
