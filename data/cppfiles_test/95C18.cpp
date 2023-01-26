#include <bits/stdc++.h>
using namespace std;
void chmax(long long int& a, long long int b) { a = max(a, b); }
void chmin(long long int& a, long long int b) { a = min(a, b); }
signed main() {
  long long int t = 1;
  cin >> t;
  for (long long int q = 0; q < t; q++) {
    long long int n, m;
    cin >> n >> m;
    vector<vector<long long int>> A(n, vector<long long int>(m));
    for (long long int i = 0; i < n; i++)
      for (long long int j = 0; j < m; j++) cin >> A[i][j];
    vector<pair<vector<long long int>, long long int>> B(n);
    for (long long int i = 0; i < n; i++) B[i] = make_pair(A[i], i);
    sort(B.begin(), B.end());
    vector<vector<long long int>> LU(n, vector<long long int>(m)),
        RU(n, vector<long long int>(m, 1e18)),
        LD(n, vector<long long int>(m, 1e18)), RD(n, vector<long long int>(m));
    for (long long int i = 0; i < n; i++)
      for (long long int j = 0; j < m; j++) {
        LU[i][j] = B[i].first[j];
        if (i) chmax(LU[i][j], LU[i - 1][j]);
        if (j) chmax(LU[i][j], LU[i][j - 1]);
      }
    for (long long int i = 0; i < n; i++)
      for (long long int j = m - 1; j >= 0; j--) {
        RU[i][j] = B[i].first[j];
        if (i) chmin(RU[i][j], RU[i - 1][j]);
        if (j < m - 1) chmin(RU[i][j], RU[i][j + 1]);
      }
    for (long long int i = n - 1; i >= 0; i--)
      for (long long int j = 0; j < m; j++) {
        LD[i][j] = B[i].first[j];
        if (i < n - 1) chmin(LD[i][j], LD[i + 1][j]);
        if (j) chmin(LD[i][j], LD[i][j - 1]);
      }
    for (long long int i = n - 1; i >= 0; i--)
      for (long long int j = m - 1; j >= 0; j--) {
        RD[i][j] = B[i].first[j];
        if (i < n - 1) chmax(RD[i][j], RD[i + 1][j]);
        if (j < m - 1) chmax(RD[i][j], RD[i][j + 1]);
      }
    bool x = 1;
    for (long long int i = 0; i < n - 1; i++) {
      for (long long int j = 0; j < m - 1; j++) {
        if (LU[i][j] < LD[i + 1][j] && RU[i][j + 1] > RD[i + 1][j + 1]) {
          x = 0;
          string ans;
          for (long long int k = 0; k < n; k++) ans += 'R';
          for (long long int k = 0; k < i + 1; k++) ans[B[k].second] = 'B';
          cout << "YES" << endl << ans << " " << j + 1 << endl;
          break;
        }
      }
      if (!x) break;
    }
    if (x) cout << "NO" << endl;
  }
  return 0;
}
