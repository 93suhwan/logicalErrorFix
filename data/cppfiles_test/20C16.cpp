#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const int MAXN = 403;
const int CAP = 30;
long long CS[MAXN][MAXN] = {0};
long long grid[MAXN][MAXN] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e;
  cin >> T;
  for (int c4 = 0; c4 < (T); ++c4) {
    cin >> n >> m;
    for (int c1 = 0; c1 < (n); ++c1) {
      string s;
      cin >> s;
      CS[c1][0] = 0;
      for (int c2 = 0; c2 < (m); ++c2) {
        grid[c1][c2] = (s[c2] == '1');
        CS[c1][c2 + 1] = CS[c1][c2] + grid[c1][c2];
      }
    }
    int ans = CAP;
    for (int i1 = 0; i1 < (n); ++i1) {
      for (int j1 = 0; j1 < (m); ++j1) {
        int temp = 0;
        for (int j2 = j1 + 1; j2 < (m); ++j2) {
          if (temp >= ans) break;
          if (j2 - j1 + 1 >= 4) {
            int temp2 = temp;
            for (int i2 = i1 + 1; i2 < (n); ++i2) {
              if (temp2 >= ans) break;
              if (i2 - i1 + 1 >= 5) {
                int temp3 =
                    temp2 + ((j2 - j1 - 1) - (CS[i2][j2] - CS[i2][j1 + 1]));
                ans = min(ans, temp3);
              }
              temp2 += 2 - (grid[i2][j1] + grid[i2][j2]) + CS[i2][j2] -
                       CS[i2][j1 + 1];
            }
          }
          temp += 1 - grid[i1][j2];
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
