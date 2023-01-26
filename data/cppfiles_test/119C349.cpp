#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long SIZE = 1e6 + 5;
void solve() {
  long long n;
  cin >> n;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sum += x;
  }
  if (sum % n == 0)
    cout << 0 << '\n';
  else
    cout << 1 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
