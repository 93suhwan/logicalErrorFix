#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long j = 2;
  for (long long i = 0; i < n; i++) {
    cout << j << " ";
    j = 2 * j + 1;
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cout << fixed << setprecision(20);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
