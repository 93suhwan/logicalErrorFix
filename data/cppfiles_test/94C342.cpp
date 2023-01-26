#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void readFile() {}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans % mod * a % mod) % mod;
    a *= a;
    a %= mod;
    b = b >> 1;
    b %= mod;
  }
  return ans % mod;
}
long long int inv(long long int a) { return power(a, mod - 2ll); }
int pre[300002];
long long int dp[10][2][2];
long long int help(int pos, int c1, int c2, string str) {
  if (pos == (int)str.length()) {
    return c1 == 0 && c2 == 0;
  }
  if (dp[pos][c1][c2] != -1) return dp[pos][c1][c2];
  long long int ans = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if ((i + j + c1) % 10 == (str[pos] - '0')) {
        long long int temp = help(pos + 1, c2, (i + j + c1) / 10, str);
        ans += temp;
      }
    }
  }
  return dp[pos][c1][c2] = ans;
}
void solve() {
  int n;
  cin >> n;
  string str = to_string(n);
  reverse(str.begin(), str.end());
  memset(dp, -1, sizeof dp);
  long long int ans = help(0, 0, 0, str);
  cout << ans - 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readFile();
  int t;
  cin >> t;
  pre[0] = 0;
  for (int i = 1; i < 300002; i++) {
    pre[i] = pre[i - 1] ^ i;
  }
  while (t--) solve();
}
