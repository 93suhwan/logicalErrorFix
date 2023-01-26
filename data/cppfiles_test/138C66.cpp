#include <bits/stdc++.h>
using namespace std;
void err() { cout << "\033[39;0m" << endl; }
template <class T, class... Ts>
void err(const T& arg, const Ts&... args) {
  cout << arg << " ";
  err(args...);
}
const int N = 400010;
int n, m, q;
long long f[N], c[N], d[N], sum[N], r[N], rs[N];
struct item {
  int w, type;
} a[N];
struct Edge {
  int x, y, z;
  bool operator<(const Edge b) const { return z < b.z; }
} e[N];
struct query {
  int id, k;
  bool operator<(const query q) const { return k < q.k; }
} qq[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void solve() {
  scanf("%d%d%d", &n, &m, &q);
  long long res = 0;
  for (int i = int(1); i <= int(n); i++) {
    scanf("%d", &a[i].w);
    a[i].type = 1;
    res += a[i].w;
  }
  for (int i = int(1); i <= int(m); i++) {
    scanf("%d", &a[i + n].w);
    a[i + n].type = 0;
  }
  sort(a + 1, a + 1 + n + m, [&](item a, item b) { return a.w < b.w; });
  for (int i = int(1); i <= int(n + m); i++) {
    f[i] = r[i] = i;
    if (a[i].type) c[i] = 1;
    sum[i] = sum[i - 1] + a[i].w;
    if (i > 1) e[i - 1] = {i - 1, i, a[i].w - a[i - 1].w};
  }
  sort(e + 1, e + n + m);
  for (int i = int(1); i <= int(q); i++) {
    scanf("%d", &qq[i].k);
    qq[i].id = i;
  }
  sort(qq + 1, qq + 1 + q);
  int cur = 1;
  for (int i = int(1); i <= int(q); i++) {
    while (cur < n + m && e[cur].z <= qq[i].k) {
      int x = e[cur].x, y = e[cur].y;
      int fx = find(x), fy = find(y);
      if (fx == fy) continue;
      res -= sum[r[fx]] - sum[r[fx] - c[fx]];
      res -= sum[r[fy]] - sum[r[fy] - c[fy]];
      f[fx] = fy;
      c[fy] += c[fx];
      res += sum[r[fy]] - sum[r[fy] - c[fy]];
      cur++;
    }
    rs[qq[i].id] = res;
  }
  for (int i = int(1); i <= int(q); i++) printf("%lld\n", rs[i]);
}
int main() {
  int T;
  T = 1;
  while (T--) {
    solve();
  }
}
