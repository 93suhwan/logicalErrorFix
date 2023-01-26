#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
bool isPalin(string s) {
  int r = s.size() - 1, l = 0;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}
int rec(string s, int l, int r, int c) {
  if (l == r) {
    return c;
  }
  if (r - l == 1) {
    if (s[l] == s[r])
      return c;
    else
      return INT_MAX;
  }
  if (s[l] != s[r]) {
    return min(rec(s, l + 1, r, c + 1), rec(s, l, r - 1, c + 1));
  }
  return rec(s, l + 1, r - 1, c);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long int ans = rec(s, 0, n - 1, 0);
    if (ans == INT_MAX)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
