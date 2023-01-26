#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void solve() {
  long long k;
  cin >> k;
  long long cnt = 0, c = 0;
  for (long long i = 1; i <= 10000; i++) {
    if (i % 3 == 0 || i % 10 == 3)
      continue;
    else
      cnt++;
    if (cnt == k) {
      c = i;
      break;
    }
  }
  cout << c << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
