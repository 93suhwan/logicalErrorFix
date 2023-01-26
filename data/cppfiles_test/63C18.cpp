#include <bits/stdc++.h>
using namespace std;
int f[1 << 20][2], sum[1 << 20], val[20], a[20], b[20];
string s[20];
vector<int> vec[20], pre[20];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int m = s[i].size(), cnt = 0;
    pre[i].resize(m, 0);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '(')
        ++cnt;
      else {
        ++b[i];
        if (cnt == 0)
          vec[i].push_back(j);
        else
          --cnt;
      }
      if (cnt == 0) pre[i][j]++;
      if (j) pre[i][j] += pre[i][j - 1];
    }
    for (int j = 0; j < m; ++j)
      if (s[i][j] == '(')
        ++a[i];
      else
        --a[i];
  }
  int all = (1 << n) - 1;
  for (int i = 1; i <= all; ++i)
    for (int j = 0; j < n; ++j)
      if (i >> j & 1) sum[i] += a[j];
  f[0][1] = -1e9;
  for (int S = 1; S <= all; ++S) {
    f[S][0] = f[S][1] = -1e9;
    for (int i = 0; i < n; ++i)
      if (S >> i & 1) {
        int T = S ^ (1 << i);
        if (sum[T] >= vec[i].size()) {
          f[S][0] = max(f[S][0], f[T][0]);
          if (sum[T] == vec[i].size()) {
            if (vec[i].size() == 0)
              f[S][0] = max(f[S][0], f[T][0] + pre[i].back());
            else {
              int l = vec[i].back(), r = s[i].size() - 1;
              f[S][0] = max(f[S][0], f[T][0] + 1 + pre[i][r] - pre[i][l]);
            }
          }
        }
        f[S][1] = max(f[S][1], f[T][1]);
        if (sum[T] >= 0 && sum[T] < vec[i].size()) {
          f[S][1] = max(f[S][1], f[T][0]);
          int r = vec[i][sum[T]] - 1;
          if (r < 0) continue;
          if (sum[T] == 0) {
            f[S][1] = max(f[S][1], f[T][0] + pre[i][r]);
          } else {
            int l = vec[i][sum[T] - 1];
            f[S][1] = max(f[S][1], f[T][0] + pre[i][r] - pre[i][l] + 1);
          }
        }
      }
  }
  cout << max(f[all][0], f[all][1]);
}
