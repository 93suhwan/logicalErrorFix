#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long f[N][2], a[N], L[N], R[N];
struct segment {
  int l, r;
};
vector<segment> v;
inline bool cmp(segment x, segment y) {
  return (x.r != y.r) ? (x.r < y.r) : (x.l > y.l);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    v.clear();
    sort(a + 1, a + n + 2);
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      int id = lower_bound(a + 1, a + n + 1, l) - a;
      if (id == n + 1 || a[id] > r) {
        v.push_back((segment){l, r});
      }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i < v.size(); ++i) {
      if (v[i - 1].l >= v[i].l || v[i - 1].r == v[i].r) {
        v.erase(v.begin() + i);
        i--;
      }
    }
    for (int i = 1; i <= n + 1; ++i) f[i][0] = f[i][1] = 1e15;
    f[0][0] = f[0][1] = 0;
    a[0] = -1e10;
    a[n + 1] = 1e10;
    int now = 0;
    for (int i = 1; i <= n + 1; ++i) {
      int cnl = 0, cnr = 0;
      L[++cnl] = a[i - 1];
      while (now < v.size() && v[now].r < a[i]) {
        L[++cnl] = v[now].l;
        R[++cnr] = v[now].r;
        ++now;
      }
      R[++cnr] = a[i];
      for (int j = 1; j <= cnl; ++j) {
        f[i][0] = min(f[i][0], f[i - 1][1] + L[j] - a[i - 1] + a[i] - R[j]);
        f[i][1] =
            min(f[i][1], f[i - 1][1] + L[j] - a[i - 1] + (a[i] - R[j]) * 2);
        f[i][0] =
            min(f[i][0], f[i - 1][0] + (L[j] - a[i - 1]) * 2 + a[i] - R[j]);
        f[i][1] = min(f[i][1],
                      f[i - 1][0] + (L[j] - a[i - 1]) * 2 + (a[i] - R[j]) * 2);
      }
    }
    printf("%lld\n", min(f[n + 1][1], f[n + 1][0]));
  }
  return 0;
}
