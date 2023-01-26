#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s) {
  long long x = 0, y = s.length() - 1;
  while (x < y) {
    if (s[x] != s[y]) return false;
    x++;
    y--;
  }
  return true;
}
void rev(string &s) {
  long long x = 0, y = s.length() - 1;
  while (x < y) {
    swap(s[x], s[y]);
    x++;
    y--;
  }
}
bool isPresent(string &s, string &str) {
  long long n = s.length();
  long long m = str.length();
  for (long long i = 0; i <= n - m; i++) {
    string temp = s.substr(i, m);
    if (temp == str) return true;
  }
  return false;
}
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = t.length();
  for (long long i = 0; i < n; i++) {
    if (i <= n - (i + 1)) {
      string temp = t.substr(0, 2 * i + 1);
      if (isPalindrome(temp)) {
        string str = t.substr(i, n - i);
        rev(str);
        if (isPresent(s, str)) {
          cout << "YES" << endl;
          return;
        }
      }
    } else {
      string temp = t.substr(2 * i - n + 1, 2 * n - i - 2);
      if (isPalindrome(temp)) {
        string str = t.substr(0, i + 1);
        if (isPresent(s, str)) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
