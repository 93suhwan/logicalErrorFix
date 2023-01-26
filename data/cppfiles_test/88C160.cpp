#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long long inf = 1e18 + 1;
const long long INF = 1e9;
void mistakes_imp() {}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  bool yes = false;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) yes = true;
  }
  if (n % 2 == 0 or yes) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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
}
