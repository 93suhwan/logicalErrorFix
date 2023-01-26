#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long dp[5000 + 10], cnt[5000 + 10], c[5000 + 10][5000 + 10];
int main() {
  ios_base::sync_with_stdio(false);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i <= 5000; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 | j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = c[i - 1][j - 1] % mod + c[i - 1][j] % mod;
        c[i][j] %= mod;
      }
    }
  }
  int ind = 0;
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      f++;
      cnt[f] = i;
    }
    if (f == k) {
      break;
    }
    ind++;
    dp[i] = 1;
  }
  dp[ind] = 1;
  for (int i = ind + 1; i < n; i++) {
    dp[i] = dp[i - 1];
    if (s[i] == '1') {
      f++;
      cnt[f] = i;
      int x = cnt[f - k] + 1;
      dp[i] += c[i - x][k];
    } else {
      int x = cnt[f - k] + 1;
      if (s[x] != '0') {
        x--;
      }
      dp[i] += c[i - x][k - 1];
    }
    dp[i] %= mod;
  }
  cout << dp[n - 1] % mod;
}
