#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f;
using namespace std;
void sol() {
  long long n, m;
  while (cin >> n >> m) {
    string s;
    cin.ignore();
    cin >> s;
    long long x[6][n];
    string a[6] = {"abc", "acb", "bca", "bac", "cab", "cba"};
    memset(x, 0, sizeof(x));
    ;
    for (long long i = 0; i < s.size(); i++) {
      if (i) {
        for (long long j = 0; j < 6; j++) {
          x[j][i] = x[j][i - 1];
          if (s[i] != a[j][i % 3]) x[j][i]++;
        }
      } else {
        for (long long j = 0; j < 6; j++) {
          x[j][i] = 0;
          if (s[i] != a[j][i % 3]) x[j][i]++;
        }
      }
    }
    while (m--) {
      long long a, b;
      cin >> a >> b;
      long long ans = INF;
      if (a > 1) {
        for (long long i = 0; i < 6; i++) {
          ans = (x[i][b - 1] - x[i][a - 2] < ans ? x[i][b - 1] - x[i][a - 2]
                                                 : ans);
        }
      } else {
        for (long long i = 0; i < 6; i++) {
          ans = (x[i][b - 1] < ans ? x[i][b - 1] : ans);
        }
      }
      cout << ans << "\n";
    }
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    sol();
    cout.flush();
  }
  return 0;
}
