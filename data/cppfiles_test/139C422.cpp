#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  if (n % 2) {
    cout << "NO" << '\n';
    return;
  }
  bool ans = 1;
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[i + (n / 2)]) {
      ans = 0;
      break;
    }
  }
  if (ans)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long num = 1;
  long long _t;
  cin >> _t;
  for (long long i = 1; i <= _t; i++) {
    solve();
  }
}
