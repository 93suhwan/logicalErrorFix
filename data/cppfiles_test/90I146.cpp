#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long f[N][2], a[N];
struct segment {
  long long l, r;
};
vector<segment> v;
inline bool cmp(segment x, segment y) {
  return x.l != y.l ? x.l < y.l : x.r < y.r;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    v.clear();
    for (int i = 1; i <= m; ++i) {
      int l, r;
      cin >> l >> r;
      int id = lower_bound(a + 1, a + n + 1, l) - a;
      if (id == n + 1 || a[id] > r) {
        v.push_back((segment){l, r});
      }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); ++i) {
      if (i != 0 && v[i].r <= v[i - 1].r) {
        v.erase(v.begin() + i - 1);
        i -= 1;
      }
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = f[0][1] = 0;
    a[n + 1] = 1e18;
    int now = 0;
    for (int i = 1; i <= n + 1; ++i) {
      int j = now;
      while (j < v.size() && v[j].r < a[i]) ++j;
      if (j == now)
        f[i][0] = f[i][1] = f[i - 1][0];
      else {
        if (i == 1) {
          f[i][0] = a[i] - v[0].r;
          f[i][1] = f[i][0] * 2;
        } else {
          int o = j - 1;
          for (int k = now; k < o; ++k) {
            f[i][0] = min(f[i][0],
                          f[i - 1][1] + v[k].l - a[i - 1] + a[i] - v[k + 1].r);
            f[i][1] = min(f[i][1], f[i - 1][1] + v[k].l - a[i - 1] +
                                       (a[i] - v[k + 1].r) * 2);
          }
          f[i][0] = min(f[i][0], f[i - 1][1] + v[o].l - a[i - 1]);
          f[i][1] = min(f[i][1], f[i - 1][1] + v[o].l - a[i - 1]);
          f[i][0] =
              min(f[i][0], min(f[i - 1][0], f[i - 1][1]) + a[i] - v[now].r);
          f[i][1] = min(f[i][1],
                        min(f[i - 1][1], f[i - 1][0]) + (a[i] - v[now].r) * 2);
        }
      }
      now = j;
    }
    cout << min(f[n + 1][1], f[n + 1][0]) << endl;
  }
  return 0;
}
