#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res *= x;
      ;
    }
    n >>= 1;
    x *= x;
  }
  return res;
}
long long powerMOD(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % (long long)1e9 + 7;
    }
    n >>= 1;
    x = (x * x) % (long long)1e9 + 7;
  }
  return res;
}
void solve() {
  string a, s;
  cin >> a >> s;
  long long s_len = s.length(), a_len = a.length();
  if (a_len > s_len || (s_len > 2 * a_len)) {
    cout << -1;
    cout << "\n";
    return;
  } else if (a_len == s_len && a > s) {
    cout << -1;
    cout << "\n";
    return;
  }
  reverse(s.begin(), s.end());
  reverse(a.begin(), a.end());
  string ans = "";
  long long j = 0;
  for (long long i = 0; i < s_len; i++) {
    long long t1 = s[i] - '0';
    long long t2 = 0;
    if (j < a_len) {
      t2 = a[j] - '0';
    }
    if (t1 < t2) {
      t1 += (s[i + 1] - '0') * 10;
      i++;
    }
    if (t1 < t2) {
      cout << -1;
      cout << "\n";
      return;
    }
    string temp = to_string(t1 - t2);
    if (temp.length() > 1) {
      cout << -1;
      cout << "\n";
      return;
    }
    ans += temp;
    j++;
  }
  if (j < a_len) {
    cout << -1;
    cout << "\n";
    return;
  }
  reverse(ans.begin(), ans.end());
  long long i = 0;
  while (ans[i] == '0' && i < ans.length()) i++;
  ans = ans.substr(i);
  cout << ans;
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  cout << fixed << setprecision(9);
  while (t--) {
    solve();
  }
}
