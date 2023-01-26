#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5000 + 7;
int T, n;
char s[MAX_N];
int z[MAX_N][MAX_N];
int dp[MAX_N];
void getZ(int n, char s[], int z[]) {
  z[0] = 0;
  for (int i = 1, k = 0; i < n; ++i) {
    int x = i - k;
    z[i] = 0;
    if (z[x] < z[k] - x) {
      z[i] = z[x];
    } else {
      z[i] = max(0, z[k] - x);
      while (s[z[i]] == s[i + z[i]]) z[i] += 1;
      if (k + z[k] < i + z[i]) k = i;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> (s + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i] = 0;
      getZ(n - i + 1, s + i, z[i] + i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (s[i + z[j][i]] > s[j + z[j][i]]) {
          dp[i] = max(dp[i], dp[j] + n - i + 1 - z[j][i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
