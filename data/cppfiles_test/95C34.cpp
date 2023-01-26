#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  for (long long _ = 0; _ < t; _++) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    vector<long long> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
         [&a](long long x, long long y) { return a[x][0] < a[y][0]; });
    vector<vector<long long>> cpmi(n, vector<long long>(m)),
        ccma(n, vector<long long>(m));
    for (long long i = n - 1; i > 0; i--) {
      for (long long j = 0; j < m; j++) {
        cpmi[i][j] = a[ord[i]][j];
        if (i < n - 1) cpmi[i][j] = min(cpmi[i][j], cpmi[i + 1][j]);
        if (j > 0) cpmi[i][j] = min(cpmi[i][j], cpmi[i][j - 1]);
      }
      for (long long j = m - 1; j > 0; j--) {
        ccma[i][j] = a[ord[i]][j];
        if (i < n - 1) ccma[i][j] = max(ccma[i][j], ccma[i + 1][j]);
        if (j < m - 1) ccma[i][j] = max(ccma[i][j], ccma[i][j + 1]);
      }
    }
    vector<long long> pma(m, -1e9), cmi(m, 1e9);
    pair<long long, long long> ans = {-1, -1};
    for (long long i = 0; i < n - 1; i++) {
      for (long long j = 0; j < m; j++) {
        pma[j] = max(pma[j], a[ord[i]][j]);
        if (j > 0) pma[j] = max(pma[j], pma[j - 1]);
      }
      for (long long j = m - 1; j > 0; j--) {
        cmi[j] = min(cmi[j], a[ord[i]][j]);
        if (j < m - 1) cmi[j] = min(cmi[j], cmi[j + 1]);
      }
      for (long long k = 0; k < m - 1; k++) {
        if (pma[k] < cpmi[i + 1][k] && cmi[k + 1] > ccma[i + 1][k + 1]) {
          ans = {i, k + 1};
        }
      }
    }
    if (ans.first == -1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<char> an(n, 'R');
    for (long long j = 0; j <= ans.first; j++) {
      an[ord[j]] = 'B';
    }
    for (char j : an) {
      cout << j;
    }
    cout << " " << ans.second << "\n";
  }
}
