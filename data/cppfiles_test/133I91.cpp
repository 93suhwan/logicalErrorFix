#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9, I = 1e18;
const int mxn = 1e5;
int t, n;
string s, ans;
void solve() {
  ans = "a";
  cin >> n;
  for (int i = 0; i < n - 2; i++) {
    cin >> s;
    if (i == 0)
      ans += s;
    else
      ans += s[1];
  }
  cout << ans << endl;
}
int main() {
  cin >> t;
  while (t--) solve();
}
