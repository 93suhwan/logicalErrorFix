#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), k = t.length() - 1;
  for (int i = n - 1; i >= 0 && k >= 0;) {
    if (s[i] == t[k]) {
      k--;
      i--;
    } else {
      i -= 2;
    }
  }
  cout << ((k < 0) ? "YES" : "NO") << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
