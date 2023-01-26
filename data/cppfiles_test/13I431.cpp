#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
int mp[200][200];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  bool flag = 0;
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      mp[i][j] = -1;
    }
  }
  if (n % 2 == 1) {
    k -= m / 2;
    if (k < 0) {
      cout << "NO\n";
      return;
    }
    flag = 1;
    n--;
  }
  if (n % 2 == 0) {
    if (m % 2 && k > m / 2 * n) {
      cout << "NO\n";
      return;
    }
    if (k % 2 == 0) {
      cout << "YES\n";
      for (int j = 1; j + 1 <= m; j += 2) {
        for (int i = 1; i <= n; i++) {
          for (int d = 0; d < 26; d++) {
            if (mp[i][j] == -1 && mp[i][j + 1] == -1 && k &&
                mp[i - 1][j] != d && mp[i][j - 1] != d) {
              mp[i][j] = mp[i][j + 1] = d;
              k--;
              break;
            }
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (mp[i][j] == -1 && mp[i + 1][j] == -1) {
            for (int d = 0; d < 26; d++) {
              if (mp[i - 1][j] != d && mp[i][j - 1] != d && mp[i][j + 1] != d &&
                  mp[i + 1][j - 1] != d && mp[i + 1][j] != d &&
                  mp[i + 1][j + 1] != d) {
                mp[i][j] = mp[i + 1][j] = d;
                break;
              }
            }
          }
        }
      }
      if (flag) {
        for (int i = 1; i + 1 <= m; i += 2) {
          for (int d = 0; d < 26; d++) {
            if (mp[n][i] != d && mp[n][i + 1] != d) {
              mp[n + 1][i] = mp[n + 1][i + 1] = d;
              break;
            }
          }
        }
      }
      if (flag) n++;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << char(mp[i][j] + 'a');
        }
        cout << '\n';
      }
    } else {
      cout << "NO\n";
    }
  }
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
