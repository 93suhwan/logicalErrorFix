#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9, I = 1e18;
const int mxn = 1e5;
int t, n;
string s, pr, ans;
bool fl;
void solve() {
  fl = 0;
  ans = "";
  cin >> n;
  cin >> pr;
  ans = pr;
  for (int i = 1; i < n - 2; i++) {
    cin >> s;
    if (pr[1] != s[0]) {
      fl = 1;
      ans += s[0];
    }
    ans += s[1];
    pr = s;
  }
  if (!fl) ans = "a" + ans;
  cout << ans << endl;
}
int main() {
  cin >> t;
  while (t--) solve();
}
