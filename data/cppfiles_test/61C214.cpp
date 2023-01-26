#include <bits/stdc++.h>
using namespace std;
const int mxn = 200000, m = 3;
long long n, k;
long long a[mxn][2], b[mxn], d[mxn], h[mxn], dp[2][m + 1];
vector<int> v[mxn][2];
map<int, vector<int>> first[mxn];
void answer() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    first[i].clear();
    for (int j = 0; j < 2; j++) v[i][j].clear();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
      v[--a[i][j]][j].push_back(i);
    }
    first[a[i][0]][a[i][1]].push_back(i);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = dp[1][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      for (int l = m; l; l--) {
        dp[j][l] += v[i][j].size() * dp[j][l - 1];
      }
  k = 0;
  for (int i = 0; i < n; i++) {
    b[i] = n + first[a[i][0]][a[i][1]].size(), d[i] = 1;
    for (int j = 0; j < 2; j++) b[i] -= v[a[i][j]][j].size();
    k += b[i];
  }
  k /= 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++) {
      for (int l : v[i][j]) h[a[l][!j]]++;
      for (int l : v[i][j]) d[l] *= v[i][j].size() - h[a[l][!j]];
      for (int l : v[i][j]) h[a[l][!j]]--;
    }
  for (int i = 0; i < n; i++)
    for (auto j : first[i]) {
      long long x = 0;
      for (int l : j.second) x += b[l];
      for (int l : j.second) d[l] += k + x;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++) {
      long long x = 0;
      for (int l : v[i][j]) x += b[l];
      for (int l : v[i][j]) d[l] -= x;
    }
  long long ret = dp[0][m] + dp[1][m], x = 0;
  for (int i = 0; i < n; i++) x += d[i];
  ret -= x / 3;
  cout << ret << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) answer();
  return 0;
}
