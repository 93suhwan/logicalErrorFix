#include <bits/stdc++.h>
using namespace std;
int read() {
  int ret = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9')
    ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return ret;
}
mt19937 rnd(0);
const int maxn = 55;
const int maxk = 6;
bool deb = 1;
int n, k;
int ans = 1e5;
int d[maxk];
int dis[maxn][maxn];
struct edge {
  int x, y, v;
  const bool operator<(const edge &a) const { return v < a.v; }
} e2[maxn * maxn];
int cnt1, cnt2;
struct dsu {
  int fa[maxn];
  void prework() {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
  void merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x > y) swap(x, y);
    fa[x] = y;
  }
  bool check(int x, int y) { return get(x) == get(y); }
} S;
int nd[maxk];
int kruskal() {
  int ret = 0;
  for (int i = 1; i <= cnt2; i++)
    if (!S.check(e2[i].x, e2[i].y)) {
      ret += e2[i].v;
      S.merge(e2[i].x, e2[i].y);
    }
  return ret;
}
bool to[maxn][maxn], nt[maxn][maxn];
void sa() {
  double T = 100000, co = 0.998;
  int now = 1e5;
  memset(to, 0, sizeof to);
  while (T > 1e-15) {
    S.prework();
    int nval = 0;
    for (int i = 1; i <= k; i++)
      for (int j = i + 1; j <= n; j++) nt[i][j] = to[i][j];
    for (int i = 1; i <= k; i++)
      for (int j = i + 1; j <= n; j++)
        if (nt[i][j] &&
            exp(1.0 * (dis[i][j] - 150) / T) * (1ll << 32) >= rnd()) {
          nt[i][j] = 0;
        }
    for (int i = 1; i <= k; i++) {
      nd[i] = 0;
      for (int j = i + 1; j <= n; j++) {
        if (nt[i][j]) {
          nd[i]++;
          if (j <= k) nd[j]++;
          nval += dis[i][j];
          S.merge(i, j);
        }
      }
    }
    for (int i = 1; i <= k; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (!nt[i][j] && nd[i] + 1 <= d[i] && (j > k || nd[j] + 1 <= d[j]) &&
            !S.check(i, j) &&
            exp(-1.0 * dis[i][j] / T) * (1ll << 32) >= rnd()) {
          nd[i]++;
          if (j <= k) nd[j]++;
          nval += dis[i][j];
          S.merge(i, j);
        }
      }
    }
    for (int i = 1; i <= k; i++) {
      if (S.get(i) <= k && nd[i] < d[i]) {
        int x = rnd() % (n - k) + k + 1;
        nd[i]++;
        nval += dis[i][x];
        S.merge(i, x);
      }
    }
    bool flag = 1;
    for (int i = 1; i <= k; i++)
      if (S.get(i) <= k) {
        flag = 0;
        break;
      }
    if (flag) {
      nval += kruskal();
      if (nval < ans) ans = nval;
      if (nval < now) {
        now = nval;
        for (int i = 1; i <= k; i++)
          for (int j = i + 1; j <= n; j++) to[i][j] = nt[i][j];
      } else if (exp(1.0 * (now - nval) / T) * (1ll << 32) >= rnd()) {
        now = nval;
        for (int i = 1; i <= k; i++)
          for (int j = i + 1; j <= n; j++) to[i][j] = nt[i][j];
      }
    }
    T = T * co;
  }
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= k; i++) d[i] = read();
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n - i; j++) dis[i][i + j] = dis[i + j][i] = read();
  for (int i = k + 1; i <= n; i++)
    for (int j = 1; j <= n - i; j++) {
      cnt2++;
      e2[cnt2].x = i;
      e2[cnt2].y = i + j;
      dis[i][i + j] = dis[i + j][i] = e2[cnt2].v = read();
    }
  sort(e2 + 1, e2 + cnt2 + 1);
  sa();
  sa();
  sa();
  sa();
  sa();
  printf("%d", ans);
  return 0;
}
