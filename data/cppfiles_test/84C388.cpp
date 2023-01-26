#include <bits/stdc++.h>
long long INTMAX = 1000000007;
using namespace std;
void solve() {
  long long n, s;
  cin >> n >> s;
  long long div = n / 2;
  div++;
  long long ans = s / div;
  cout << ans << "\n";
}
signed main() {
  long long t;
  cin >> t;
  for (long long i1 = 0; i1 < t; i1++) {
    solve();
  }
}
