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
    string temp = "";
    for (long long i = 0; i < n; i++) {
      if (s[i] == c) {
        if (s[n - i - 1] == c) {
          temp += s[i];
        } else
          count++;
      } else
        temp += s[i];
    }
    if (ispalindrome(temp)) {
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
