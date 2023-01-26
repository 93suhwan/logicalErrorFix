#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
bool ispalindrome(string &s) {
  long long l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = INT_MAX;
  if (ispalindrome(s)) {
    cout << 0 << "\n";
    return;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    long long count = 0;
    long long l = 0, r = n - 1;
    bool flag = 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (s[l] == c) {
          l++;
          count++;
        } else if (s[r] == c) {
          r--;
          count++;
        } else {
          flag = 0;
          break;
        }
      }
    }
    if (flag) {
      ans = min(ans, count);
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
