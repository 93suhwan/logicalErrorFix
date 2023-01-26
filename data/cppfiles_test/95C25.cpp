#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int n, m, col;
vector<int> idx, res;
vector<vector<int> > a, pre_min, pre_max, suf_min, suf_max;
vector<int> pre_left, pre_right, suf_left, suf_right;
void init() {
  a.assign(n + 2, vector<int>(m + 2, 0));
  pre_min.assign(n + 2, vector<int>(m + 2, INF));
  pre_max.assign(n + 2, vector<int>(m + 2, 0));
  suf_min.assign(n + 2, vector<int>(m + 2, INF));
  suf_max.assign(n + 2, vector<int>(m + 2, 0));
  pre_left.assign(n + 2, 0);
  pre_right.assign(n + 2, INF);
  suf_left.assign(n + 2, INF);
  suf_right.assign(n + 2, 0);
  res.assign(n + 2, 0);
  idx.assign(n + 2, 0);
}
bool cmp(const int &i, const int &j) {
  return pre_max[i][col] < pre_max[j][col];
}
bool valid(int i) {
  return pre_left[i] < suf_left[i + 1] && suf_right[i + 1] < pre_right[i];
}
void solve() {
  for (int j = 1, _n = m - 1; j <= _n; ++j) {
    for (int i = 1, _n = n; i <= _n; ++i) idx[i] = i;
    col = j;
    sort(idx.begin() + 1, idx.begin() + 1 + n, cmp);
    for (int i = 1, _n = n; i <= _n; ++i) {
      int k = idx[i];
      pre_left[i] = pre_max[k][j];
      pre_right[i] = min(pre_right[i - 1], suf_min[k][j + 1]);
    }
    for (int i = n, _n = 1; i >= _n; --i) {
      int k = idx[i];
      suf_left[i] = min(suf_left[i + 1], pre_min[k][j]);
      suf_right[i] = max(suf_right[i + 1], suf_max[k][j + 1]);
    }
    for (int i = 1, _n = n - 1; i <= _n; ++i)
      if (valid(i)) {
        for (int k = 1, _n = i; k <= _n; ++k) res[idx[k]] = 1;
        puts("YES");
        for (int k = 1, _n = n; k <= _n; ++k) cout << (res[k] ? 'B' : 'R');
        cout << ' ' << j << '\n';
        return;
      }
  }
  puts("NO");
}
int main() {
  ios::sync_with_stdio();
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    init();
    for (int i = 1, _n = n; i <= _n; ++i)
      for (int j = 1, _n = m; j <= _n; ++j) cin >> a[i][j];
    for (int i = 1, _n = n; i <= _n; ++i) {
      for (int j = 1, _n = m; j <= _n; ++j) {
        pre_max[i][j] = max(pre_max[i][j - 1], a[i][j]);
        pre_min[i][j] = min(pre_min[i][j - 1], a[i][j]);
      }
      for (int j = m, _n = 1; j >= _n; --j) {
        suf_max[i][j] = max(suf_max[i][j + 1], a[i][j]);
        suf_min[i][j] = min(suf_min[i][j + 1], a[i][j]);
      }
    }
    solve();
  }
}
