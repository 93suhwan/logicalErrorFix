#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  long long k;
  cin >> k;
  long long t = 1;
  long long num = 1;
  while (t <= k) {
    long long l = num % 10;
    if (num % 3 == 0) {
      num++;
      continue;
    } else if (l == 3) {
      num++;
      continue;
    } else {
      t++;
      num++;
    }
  }
  cout << num - 1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
