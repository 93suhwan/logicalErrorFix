#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long M = 1e9 + 7;
void solve() {
  string s, ss;
  cin >> s >> ss;
  long long l = ss.length() - 1;
  for (long long i = s.length() - 1; i >= 0; i--) {
    ~l&& s[i] == ss[l] ? l-- : i--;
  }
  if (~l) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
