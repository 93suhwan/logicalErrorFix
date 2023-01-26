#include <bits/stdc++.h>
using namespace std;
const long long M = 10;
string s, t;
long long a[M], dp[M][26], n;
long long f(long long i, long long j) {
  if (i >= n) {
    return j == 0;
  }
  long long& ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  for (long long k = 0; k < 10; ++k) {
    long long x = t[i] - '0';
    if (!i and !k) continue;
    if (x == k or t[i] == '_') {
      long long nj = (j + k * a[n - 1 - i]) % 25;
      ans += f(i + 1, nj);
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  a[0] = 1;
  for (long long i = 1; i < M; ++i) {
    a[i] = (10 * a[i - 1]) % 25;
  }
  bool ok = 0;
  for (char& c : s) ok |= (c == 'X');
  long long ans = 0;
  if (!ok) {
    if (s == "0") {
      cout << 1;
    } else {
      if (s[0] == '0') {
        cout << 0;
      } else {
        t = s;
        memset(dp, -1, sizeof(dp));
        cout << f(0, 0);
      }
    }
    return 0;
  }
  for (long long x = 0; x < 10; ++x) {
    t = s;
    for (char& c : t) {
      if (c == 'X') c = (x + '0');
    }
    if (t[0] == '0') continue;
    memset(dp, -1, sizeof(dp));
    ans += f(0, 0);
  }
  cout << ans;
  return 0;
}
