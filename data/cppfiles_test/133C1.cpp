#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x;
  cin >> x;
  long long n = x - 2;
  vector<string> s(n);
  for (long long i{0}; i < n; i++) {
    cin >> s[i];
  }
  bool res = false;
  string ans = "";
  for (long long i{0}; i < n - 1; i++) {
    ans += s[i][0];
    if (s[i][1] != s[i + 1][0]) {
      ans += s[i][1];
      res = true;
    }
  }
  if (!res) {
    ans += s[n - 1][0];
    ans += s[n - 1][1];
    ans += s[n - 1][1];
  } else {
    ans += s[n - 1][0];
    ans += s[n - 1][1];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
