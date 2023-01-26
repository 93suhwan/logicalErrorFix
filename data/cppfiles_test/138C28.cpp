#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, m, q;
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
struct re {
  int a, b;
};
re a[N], c[N];
long long ans[N], v[N], v2[N], v3[N], sum[N];
bool cmp(re x, re y) { return x.a < y.a; }
set<pair<int, int> > S;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> n >> m >> q;
  long long now = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a;
    a[i].b = 1;
    now += a[i].a;
  }
  for (int i = n + 1; i <= n + m; i++) {
    cin >> a[i].a;
    a[i].b = 0;
  }
  for (int i = 1; i <= n + m; i++) fa[i] = i;
  sort(a + 1, a + n + m + 1, cmp);
  for (int i = 1; i <= n + m; i++) {
    sum[i] = sum[i - 1] + a[i].a;
    v[i] = a[i].a * a[i].b, v2[i] = a[i].b;
    v3[i] = i;
  }
  for (int i = 2; i <= n + m; i++) S.insert(make_pair(a[i].a - a[i - 1].a, i));
  for (int i = 1; i <= q; i++) {
    cin >> c[i].a;
    c[i].b = i;
  }
  sort(c + 1, c + q + 1, cmp);
  for (int i = 1; i <= q; i++) {
    while (!S.empty() && (*S.begin()).first <= c[i].a) {
      int h = (*S.begin()).second;
      int f1 = find(h), f2 = find(h - 1);
      now -= v[f1];
      now -= v[f2];
      fa[f1] = f2;
      v2[f2] += v2[f1];
      v3[f2] = max(v3[f2], v3[f1]);
      v[f2] = sum[v3[f2]] - sum[v3[f2] - v2[f2]];
      now += v[f2];
      S.erase(S.begin());
    }
    ans[c[i].b] = now;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
  return 0;
}
