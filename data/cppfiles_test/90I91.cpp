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
    a[0] = -1e18;
    a[n + 1] = 1e18;
    int now = 0;
    for (int i = 1; i <= n + 1; ++i) {
      vector<long long> L, R;
      L.push_back(a[i - 1]);
      while (now < v.size() && v[now].r < a[i]) {
        L.push_back(v[now].l);
        R.push_back(v[now].r);
        ++now;
      }
      R.push_back(a[i]);
      if (L.size() == 1) {
        f[i][0] = f[i][1] = f[i - 1][0];
        continue;
      }
      for (int j = 0; j < L.size(); ++j) {
        f[i][0] = min(f[i][0], f[i - 1][1] + L[j] - a[i - 1] + a[i] - R[j]);
        f[i][1] =
            min(f[i][1], f[i - 1][1] + L[j] - a[i - 1] + (a[i] - R[j]) * 2);
        if (L[j] == a[i - 1]) {
          f[i][0] = min(f[i][0], f[i - 1][0] + a[i] - R[j]);
          f[i][1] = min(f[i][1], f[i - 1][0] + (a[i] - R[j]) * 2);
        }
      }
    }
    cout << min(f[n + 1][1], f[n + 1][0]) << endl;
  }
  return 0;
}
