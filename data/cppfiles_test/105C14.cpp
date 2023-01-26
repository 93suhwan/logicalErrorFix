#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], l[200005], r[200005], sum[200005], m[200005],
    ans[200005];
struct qwq {
  int l, r, sum, id;
} c[200005];
inline bool cmp(qwq x, qwq y) {
  return x.sum < y.sum || x.sum == y.sum && x.r < y.r;
}
inline int solve(vector<qwq> v) {
  int rtn = 0, nowr = -1e9;
  for (auto t : v) {
    if (t.l > nowr) nowr = t.r, ++rtn;
    ans[t.id] = nowr;
  }
  return rtn;
}
signed main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> m[i];
    for (int i = 1; i <= n; i++) {
      int x = min(b[i], m[i]);
      r[i] = (a[i] - (m[i] - x)) - (b[i] - x);
      x = min(a[i], m[i]);
      l[i] = (a[i] - x) - (b[i] - (m[i] - x));
      sum[i] = a[i] + b[i] - m[i];
      c[i] = {l[i], r[i], sum[i], i};
    }
    sort(c + 1, c + n + 1, cmp);
    vector<qwq> v;
    c[n + 1].sum = -1e9;
    int qaq = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (c[i].sum != c[i - 1].sum) qaq += solve(v), v.clear();
      v.push_back(c[i]);
    }
    cout << qaq << "\n";
    for (int i = 1; i <= n; i++) {
      int x = min(b[i], m[i]);
      int w = (a[i] - (m[i] - x)) - (b[i] - x);
      int d = w - ans[i];
      x -= d / 2;
      cout << m[i] - x << " " << x << "\n";
    }
  }
  return 0;
}
