#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int calc(string s, int n, char c) {
  int l = 0, r = n - 1;
  int cnt = 0;
  while (l <= r) {
    if (s[l] == s[r]) {
      if (l == r)
        cnt++;
      else
        cnt += 2;
      l++;
      r--;
    } else if (s[l] == c)
      l++;
    else if (s[r] == c)
      r--;
    else
      return INT_MAX;
  }
  return n - cnt;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INT_MAX;
  for (int i = 0; i < 26; i++) ans = min(ans, calc(s, n, 'a' + i));
  if (ans == INT_MAX)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
