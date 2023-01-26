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
int ans = 1e5, now;
int d[maxn];
struct edge {
  int from, to, v;
  const bool operator<(const edge &x) const { return v < x.v; }
} e[maxn * maxn];
int cnt;
struct dsu {
  int fa[maxn];
  void prework() {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
  void merge(int x, int y) { fa[get(x)] = get(y); }
  bool check(int x, int y) { return get(x) == get(y); }
} S;
int nd[maxn];
bool chose[maxn];
void kruskal() {
  S.prework();
  for (int i = 1; i <= n; i++) nd[i] = 0;
  now = 0;
  for (int i = 1; i <= cnt; i++) chose[i] = 0;
  for (int i = 1; i <= cnt; i++)
    if (!S.check(e[i].from, e[i].to)) {
      S.merge(e[i].from, e[i].to);
      now += e[i].v;
      nd[e[i].from]++;
      nd[e[i].to]++;
      chose[i] = 1;
    }
}
bool calc() {
  S.prework();
  bool flag = 0;
  for (int i = cnt; i >= 1; i--)
    if (chose[i] &&
        (d[e[i].from] < nd[e[i].from] || d[e[i].to] < nd[e[i].to]) &&
        rnd() % 4 != 0) {
      chose[i] = 0;
      nd[e[i].from]--;
      nd[e[i].to]--;
      now -= e[i].v;
      flag = 1;
      break;
    }
  if (!flag) return false;
  flag = 0;
  for (int i = 1; i <= cnt; i++)
    if (chose[i]) S.merge(e[i].from, e[i].to);
  for (int i = 1; i <= cnt; i++)
    if (!S.check(e[i].from, e[i].to) && d[e[i].from] > nd[e[i].from] &&
        d[e[i].to] > nd[e[i].to] && rnd() % 4 != 0) {
      chose[i] = 1;
      nd[e[i].from]++;
      nd[e[i].to]++;
      now += e[i].v;
      flag = 1;
      break;
    }
  if (!flag) return false;
  flag = 1;
  for (int i = 1; i <= k; i++)
    if (nd[i] > d[i]) {
      flag = 0;
      break;
    }
  if (flag) ans = min(ans, now);
  return true;
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= k; i++) d[i] = read();
  for (int i = k + 1; i <= n; i++) d[i] = n + 10;
  for (int i = 1; i <= n - 1; i++)
    for (int j = 1; j <= n - i; j++) {
      cnt++;
      e[cnt].from = i;
      e[cnt].to = i + j;
      e[cnt].v = read();
    }
  sort(e + 1, e + cnt + 1);
  for (int i = 1; i <= 100000; i++) {
    kruskal();
    while (calc())
      ;
  }
  printf("%d", ans);
  return 0;
}
