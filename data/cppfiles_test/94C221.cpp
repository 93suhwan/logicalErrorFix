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
void solve() {
  int n;
  cin >> n;
  string str = to_string(n);
  string n1 = "", n2 = "";
  int len = str.length();
  for (int i = 0; i < len; i += 2) n1 += str[i];
  for (int i = 1; i < len; i += 2) n2 += str[i];
  int a = 0, b = 0;
  if (n1.length() > 0) a = stoi(n1);
  if (n2.length() > 0) b = stoi(n2);
  int dp[2][3];
  dp[0][0] = a == 0 ? 0 : a - 1;
  dp[0][1] = (a == 0) ? 0 : 2;
  dp[0][2] = (a == 0) ? 1 : 0;
  dp[1][0] = b == 0 ? 0 : b - 1;
  dp[1][1] = (b == 0) ? 0 : 2;
  dp[1][2] = (b == 0) ? 1 : 0;
  long long int ans = dp[0][0] * (dp[1][0] + dp[1][1] + dp[1][2]) +
                      dp[0][1] * (dp[1][0] + dp[1][1] / 2) +
                      dp[0][2] * dp[1][0];
  cout << ans << '\n';
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
