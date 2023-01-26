#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 7;
const long long oo = 2e18 + 7;
const long long mod = 1e9 + 7;
int n;
void solve() {
  cin >> n;
  int base = 3;
  for (int i = 1; i <= n; ++i) {
    cout << base << ' ';
    ++base;
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
