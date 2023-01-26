#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 2e6;
int T, n, a[N], b[N], m[N], l[N], r[N], ans[N];
vector<int> vec[M + 1];
bool cmp(int x, int y) {
  if (l[x] != l[y]) return l[x] < l[y];
  return r[x] > r[y];
}
void slv() {
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> m[i];
    vec[a[i] + b[i] - m[i]].emplace_back(i);
    if (a[i] >= m[i])
      l[i] = a[i] - m[i];
    else
      l[i] = 0;
    if (b[i] >= m[i])
      r[i] = a[i];
    else
      r[i] = a[i] + b[i] - m[i];
  }
  for (int t = 1; t <= n; ++t) {
    int i = a[t] + b[t] - m[t];
    if (vec[i].size() == 0) continue;
    sort(vec[i].begin(), vec[i].end(), cmp);
    int sz = vec[i].size(), x = -1, y = M, pre = 0;
    for (int k = 0; k <= sz - 1; ++k) {
      if (l[vec[i][k]] > y) {
        for (int j = pre; j <= k - 1; ++j) {
          ans[vec[i][j]] = a[vec[i][j]] - y;
        }
        pre = k;
        x = -1;
        y = M;
        res++;
      }
      x = l[vec[i][k]];
      y = min(r[vec[i][k]], y);
    }
    for (int k = pre; k <= sz - 1; ++k) {
      ans[vec[i][k]] = a[vec[i][k]] - y;
    }
    res++;
    vec[i].clear();
  }
  cout << res << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " " << m[i] - ans[i] << '\n';
  }
}
int main() {
  {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
  }
  cin >> T;
  while (T--) slv();
}
