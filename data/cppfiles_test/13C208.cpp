#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long qpow(long long a, long long b, long long mod) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) (ans *= a) %= mod;
    b >>= 1;
    (a *= a) %= mod;
  }
  return ans % mod;
}
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
int nums[20];
long long dp[20][20];
long long dfs(int pos, int pre, bool limit) {
  if (pos == 0) return 1;
  if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
  int maxnum = limit ? nums[pos] : 9;
  long long sum = 0;
  for (int i = 0; i <= maxnum; i++) {
    if (pre == 4 && i == 9) continue;
    sum += dfs(pos - 1, i, limit && i == maxnum);
  }
  if (!limit) dp[pos][pre] = sum;
  return sum;
}
long long solve(long long n) {
  int pos = 0;
  while (n) {
    nums[++pos] = n % 10;
    n /= 10;
  }
  memset(dp, -1, sizeof(dp));
  return dfs(pos, 0, true);
}
string s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a = 0, b = 0, c = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B')
        b++;
      else
        a++;
    }
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
