#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  long long int i, j, n, k;
  cin >> n >> k;
  long long int hr = 0;
  i = 1;
  while (i <= n) {
    if (i < k) {
      i = i * 2;
      hr++;
    } else {
      hr += (n - i) / k;
      if ((n - i) % k) {
        hr++;
      }
      i = n + 1;
    }
  }
  cout << hr;
  return;
}
int32_t main() {
  long long int t, tc = 1;
  t = 1;
  cin >> t;
  while (tc <= t) {
    solve();
    cout << "\n";
    tc++;
  }
  return 0;
}
