#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int mxn = 2e5 + 5;
long long t, n = 0, m, q;
long long arr[416][416];
vector<long long> g;
vector<pair<long long, long long> > f;
string s[416];
void input() {
  f.clear(), g.clear();
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      arr[i][j] = 0;
    }
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "0" + s[i] + "0";
    for (int j = 1; j <= m; j++) {
      arr[i][j] = arr[i][j - 1] + (s[i][j] == '1');
    }
  }
}
void solve() {
  long long ans = mxn;
  for (int j1 = 1; j1 <= m; j1++) {
    for (int j2 = j1 + 3; j2 <= m; j2++) {
      long long cnt = 0, d = j2 - j1 - 1, lvl = 1, x = 0;
      cnt = d - (arr[1][j2 - 1] - arr[1][j1]);
      for (int i = 2; i < 5; i++) {
        cnt += (s[i][j2] == '0') + (s[i][j1] == '0');
        cnt += (arr[i][j2 - 1] - arr[i][j1]);
      }
      cnt += (d - (arr[5][j2 - 1] - arr[5][j1]));
      ans = min(ans, cnt);
      cnt = d - (arr[1][j2 - 1] - arr[1][j1]);
      for (int i = 2; i <= n; i++) {
        if (lvl + 4 <= i) {
          ans = min(ans, cnt + (d - (arr[i][j2 - 1] - arr[i][j1])));
        }
        if (i <= n - 4) {
          if (cnt > 16 || cnt + (s[i][j2] == '0') + (s[i][j1] == '0') +
                                  (arr[i][j2 - 1] - arr[i][j1]) >
                              d - (arr[i][j2 - 1] - arr[i][j1])) {
            cnt += arr[i][j2 - 1] - arr[i][j1] + (s[i][j2] == '0') +
                   (s[i][j1] == '0');
            for (int j = i + 1; j <= i + 4; j++) {
              if (cnt > 16) break;
              if (lvl + 4 <= j) {
                ans = min(ans, cnt + (d - (arr[j][j2 - 1] - arr[j][j1])));
              }
              cnt += ((arr[j][j2 - 1] - arr[j][j1]) + (s[j][j2] == '0') +
                      (s[j][j1] == '0'));
            }
            cnt = d - (arr[i][j2 - 1] - arr[i][j1]);
            lvl = i;
            continue;
          }
        }
        cnt += ((arr[i][j2 - 1] - arr[i][j1]) + (s[i][j2] == '0') +
                (s[i][j1] == '0'));
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    input(), solve();
  }
  return 0;
}
