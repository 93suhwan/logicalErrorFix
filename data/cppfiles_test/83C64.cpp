#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 5e3 + 5;
const int inf = 0x3f3f3f3f;
long long dp[MAXN];
int f[MAXN][MAXN];
char s[MAXN];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; j <= n + 1; j++) {
        f[i][j] = 0;
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = n; j >= 1; j--) {
        if (s[i] == s[j])
          f[i][j] = f[i + 1][j + 1] + 1;
        else
          f[i][j] = 0;
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = n - i + 1;
      for (int j = 1; j < i; j++) {
        int c = f[i][j];
        if (s[i + c] > s[j + c]) {
          dp[i] = max(dp[i], dp[j] + n - i + 1 - c);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
}
