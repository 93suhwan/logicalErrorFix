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
  long long i = s_len - 1, j = a_len - 1;
  bool good = 1;
  string ans = "";
  while (i >= 0 && j >= 0) {
    long long digit1 = s[i] - '0', digit2 = a[j] - '0';
    if (digit1 >= digit2) {
      ans = to_string(digit1 - digit2) + ans;
      i--;
      j--;
    } else {
      if (i == 0) {
        good = 0;
        break;
      }
      digit1 += (s[i - 1] - '0') * 10;
      long long diff = digit1 - digit2;
      if (diff > 9 || diff < 0) {
        good = 0;
        break;
      }
      ans = to_string(digit1 - digit2) + ans;
      i -= 2;
      j--;
    }
  }
  if (!good || j >= 0) {
    cout << -1;
    cout << "\n";
    return;
  }
  while (i >= 0) {
    ans = s[i] + ans;
    i--;
  }
  long long idx = 0;
  while (ans[idx] == '0' && idx < ans.length()) idx++;
  ans = ans.substr(idx);
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
