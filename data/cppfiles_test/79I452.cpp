#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long Mod(long long x);
long long Add(long long a, long long b);
long long Mul(long long a, long long b);
long long FastExp(long long b, long long e);
void init_code() {}
vector<string> v = {"22", "25", "27", "32", "33", "35",
                    "52", "55", "57", "72", "75", "77"};
bool lcs(string a, string b) {
  long long n = a.length(), m = b.length();
  long long dp[n + 1][m + 1];
  memset(dp, 0, sizeof dp);
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      if (a[i - 1] == b[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return dp[n][m] == min(n, m);
}
signed main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    set<long long> st = {1, 4, 6, 8, 9};
    bool flag = true;
    for (char c : s) {
      if (st.count(c - '0')) {
        flag = false;
        cout << 1 << '\n' << c << '\n';
        break;
      }
    }
    if (!flag) continue;
    for (string num : v) {
      if (lcs(s, num)) cout << 2 << '\n' << num << '\n';
    }
  }
  return 0;
}
long long Mod(long long x) { return (x % MOD + MOD) % MOD; }
long long Add(long long a, long long b) { return Mod(Mod(a) + Mod(b)); }
long long Mul(long long a, long long b) { return Mod(Mod(a) * Mod(b)); }
long long FastExp(long long b, long long e) {
  if (e == 0) return 1;
  if (e == 1) return Mod(b);
  if (e % 2 == 0) {
    long long temp = FastExp(b, e / 2);
    return Mul(temp, temp);
  } else {
    long long temp = FastExp(b, e / 2);
    return Mul(Mul(temp, temp), b);
  }
}
