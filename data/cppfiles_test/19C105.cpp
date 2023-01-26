#include <bits/stdc++.h>
using namespace std;
long long get() {
  char c = getchar();
  long long x = 0LL;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x *= 10LL;
    x += (c - '0');
    c = getchar();
  }
  return x;
}
string i_t_s(int x) {
  string t = "";
  while (x) {
    t += x % 10 + '0';
    x /= 10;
  }
  reverse(t.begin(), t.end());
  return t;
}
int s_t_i(string t) {
  int x = 0;
  for (int i = 0; i < (int)(t.size()); i++) {
    x = x * 10 + (t[i] - '0');
  }
  return x;
}
long long q_p(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y % 2) {
      res = res * x;
      res %= 1000000007;
    }
    y /= 2;
    x = x * x;
    x %= 1000000007;
  }
  return res;
}
bool ok(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}
bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
int n;
int t;
int a[10001];
int dp[2][20001];
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 20001; j++) dp[i][j] = 1e9;
    dp[0][a[0]] = a[0];
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 20001; j++) dp[i % 2][j] = 1e9;
      for (int j = 0; j < 20001; j++) {
        if (dp[(i - 1) % 2][j] == 1e9) continue;
        dp[i % 2][j + a[i]] =
            min(dp[i % 2][j + a[i]],
                dp[(i - 1) % 2][j] + max(0, a[i] - dp[(i - 1) % 2][j] + j));
        dp[i % 2][max(0, j - a[i])] = min(
            dp[i % 2][max(0, j - a[i])], dp[(i - 1) % 2][j] + max(0, a[i] - j));
      }
    }
    int ans = 1e9;
    for (int i = 0; i < 20001; i++) {
      ans = min(ans, dp[(n - 1) % 2][i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
