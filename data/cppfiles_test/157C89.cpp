#include <bits/stdc++.h>
using namespace std;
long long int calculate(long long int p, long long int q) {
  long long int modx = 998244353, expo;
  expo = modx - 2;
  while (expo) {
    {
      if (expo & 1) p = (p * q) % modx;
    }
    q = (q * q) % modx;
    expo >>= 1;
  }
  return p % modx;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string s;
    long long int ans = 1;
    cin >> s;
    if (k == 0) {
      cout << 1 << "\n";
      continue;
    }
    long long int i = 0, j = 0;
    long long int dp[n + 5][k + 5];
    memset(dp, 0, sizeof(dp));
    for (int p = 1; p <= k; p++) {
      dp[0][p] = dp[0][p - 1] + 1;
    }
    for (int p = 1; p <= n; p++) {
      for (int q = 1; q <= k; q++)
        dp[p][q] = (dp[p - 1][q] + dp[p][q - 1]) % 998244353;
    }
    long long int zero = 0, lastzero = 0, one = 0, b = 0;
    while (i < n) {
      if (s[i] == '0') {
        zero++;
        if (one == k) lastzero++;
      } else
        one++;
      if (one > k) {
        for (int p = 0; p < zero; p++) {
          ans = (ans + dp[p][k]) % 998244353;
        }
        long long int temp = 0;
        if (b > 0) {
          for (int p = 0; p < zero - lastzero; p++) {
            temp = (temp + dp[p][k - 1]) % 998244353;
          }
        }
        lastzero = 0;
        b = 1;
        ans = (998244353 + ans - temp) % 998244353;
        while (j < i) {
          if (s[j] == '1') {
            one--;
            j++;
            break;
          }
          j++;
          zero--;
        }
      }
      i++;
    }
    if (one == k) {
      for (int p = 0; p < zero; p++) {
        ans = (ans + dp[p][k]) % 998244353;
      }
      long long int temp = 0;
      if (b > 0) {
        for (int p = 0; p < zero - lastzero; p++) {
          temp = (temp + dp[p][k - 1]) % 998244353;
        }
      }
      ans = (998244353 + ans - temp) % 998244353;
    }
    cout << ans << "\n";
  }
  return 0;
}
