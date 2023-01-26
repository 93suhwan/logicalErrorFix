#include <bits/stdc++.h>
using namespace std;
long long lcs(string s, string p, long long n, long long m) {
  long long i = 0, j = 0, ans = 0;
  while (i <= n - 1 && j <= m - 1) {
    if (s[i] == p[j]) {
      ans++;
      i++;
      j++;
    } else {
      i++;
    }
  }
  return ans;
}
void solve(long long testcase) {
  string s;
  cin >> s;
  long long x = 1, idx = 1, ans = INT_MAX;
  while (idx < 51) {
    string p = to_string(x);
    long long n = s.size();
    long long m = p.size();
    long long common = lcs(s, p, n, m);
    if (common == m) {
      ans = min(ans, abs(n - m));
    } else {
      long long jubin = (n + m - (2 * common));
      ans = min(ans, jubin);
    }
    x *= 2;
    idx++;
  }
  cout << ans << '\n';
  return;
}
signed main() {
  long long test = 1;
  cin >> test;
  for (long long init = 1; init <= test; init++) {
    solve(init);
  }
  return 0;
}
