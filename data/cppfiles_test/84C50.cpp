#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
long long del(long long a, long long b) { return (a - 1) / b + 1; }
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n % 2 == 0) {
    cout << s / (n / 2 + 1);
  } else {
    cout << s / (n / 2 + 1);
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long _ = 1;
  cin >> _;
  while (_--) solve();
}
