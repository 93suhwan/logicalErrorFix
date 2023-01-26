#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long k;
  for (long long i = 0; i < n; i++) cin >> k;
  for (long long i = 1; i <= n + 1; i++) cout << i << " ";
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
