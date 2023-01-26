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
int n, k;
int ans;
int d[maxk];
struct edge {
  int x, y, v;
  const bool operator<(const edge &a) const { return v < a.v; }
} e1[maxn * 5], e2[maxn * maxn];
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
  for (int i = 1; i <= cnt2; i++) {
    if (!S.check(e2[i].x, e2[i].y)) ret += e2[i].v;
    S.merge(e2[i].x, e2[i].y);
  }
  return ret;
}
void sa() {
  double T = 100000, co = 0.998;
  unordered_map<int, bool> chose, np;
  chose.clear();
  int now = ans = 1e5;
  while (T > 1e-15) {
    S.prework();
    np = chose;
    int nval = 0;
    int cnt = rnd() % 10;
    while (cnt--)
      for (auto i = np.begin(); i != np.end(); i++)
        if (rnd() % np.size() == 0) {
          np.erase(i);
          break;
        }
    for (int i = 1; i <= k; i++) nd[i] = 0;
    for (auto i : np) {
      if (e1[i.first].x <= k) nd[e1[i.first].x]++;
      if (e1[i.first].y <= k) nd[e1[i.first].y]++;
      S.merge(e1[i.first].x, e1[i.first].y), nval += e1[i.first].v;
    }
    cnt = rnd() % 10;
    while (cnt--) {
      for (int i = 1; i <= cnt1; i++)
        if (np.find(i) == np.end() && !S.check(e1[i].x, e1[i].y) &&
            (e1[i].x > k || nd[e1[i].x] + 1 <= d[e1[i].x]) &&
            (e1[i].y > k || nd[e1[i].y] + 1 <= d[e1[i].y]) &&
            rnd() % (cnt1 - np.size()) == 0) {
          np[i] = 1;
          S.merge(e1[i].x, e1[i].y);
          nval += e1[i].v;
          if (e1[i].x <= k) nd[e1[i].x]++;
          if (e1[i].y <= k) nd[e1[i].y]++;
          break;
        }
    }
    for (int i = 1; i <= k; i++) {
      if (S.get(i) <= k) {
        if (nd[i] < d[i]) {
          while (true) {
            int d = rnd() % cnt1 + 1;
            if (e1[d].x == i && e1[d].y > k) {
              np[d] = 1;
              nd[i]++;
              nval += e1[d].v;
              S.merge(e1[d].x, e1[d].y);
              break;
            }
          }
        }
      }
    }
    nval += kruskal();
    ans = min(ans, nval);
    if (nval < now)
      swap(chose, np), now = nval;
    else if (exp(1.0 * (now - nval) / T) * (1ll << 32) >= rnd())
      swap(chose, np), now = nval;
    T = T * co;
  }
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= k; i++) d[i] = read();
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n - i; j++) {
      cnt1++;
      e1[cnt1].x = i;
      e1[cnt1].y = i + j;
      e1[cnt1].v = read();
    }
  for (int i = k + 1; i <= n; i++)
    for (int j = 1; j <= n - i; j++) {
      cnt2++;
      e2[cnt2].x = i;
      e2[cnt2].y = i + j;
      e2[cnt2].v = read();
    }
  sort(e2 + 1, e2 + cnt2 + 1);
  sa();
  printf("%d", ans);
  return 0;
}
