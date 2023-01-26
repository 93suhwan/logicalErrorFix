#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 1;
vector<long long> x(N);
void solve() {
  long long a, b;
  cin >> a >> b;
  long long p = x[a - 1];
  if (p == b) {
    cout << a << "\n";
  } else {
    if (a == p) {
      cout << 2 * a - 1 << "\n";
    } else {
      long long y = p ^ b;
      if (y == a) {
        cout << a + 2 << "\n";
      } else
        cout << a + 1 << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (long long j = 0; j < N; j++) {
    if (j == 0) {
      x[j] = 0;
    } else {
      x[j] = (x[j - 1] ^ j);
    }
  }
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
