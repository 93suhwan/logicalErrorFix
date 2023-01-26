#include <bits/stdc++.h>
using namespace std;
bool solve(long long i, long long j, long long n, long long m,
           vector<vector<long long>>& res) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return false;
  }
  if (res[i][j] == 1) {
    return false;
  }
  if (i == n - 1 && j == m - 1) {
    return true;
  }
  res[i][j] = 1;
  if (solve(i + 1, j, n, m, res)) {
    return true;
  }
  if (solve(i - 1, j, n, m, res)) {
    return true;
  }
  if (solve(i, j - 1, n, m, res)) {
    return true;
  }
  if (solve(i, j + 1, n, m, res)) {
    return true;
  }
  if (solve(i + 1, j + 1, n, m, res)) {
    return true;
  }
  if (solve(i - 1, j + 1, n, m, res)) {
    return true;
  }
  if (solve(i - 1, j - 1, n, m, res)) {
    return true;
  }
  if (solve(i + 1, j - 1, n, m, res)) {
    return true;
  }
  res[i][i] = 0;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long m;
    cin >> m;
    vector<vector<long long>> res(2, vector<long long>(m));
    string str1, str2;
    cin >> str1 >> str2;
    for (long long i = 0; i < m; i++) {
      res[0][i] = str1[i] - '0';
    }
    for (long long i = 0; i < m; i++) {
      res[1][i] = str2[i] - '0';
    }
    bool temp = solve(0, 0, 2, m, res);
    if (temp) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
