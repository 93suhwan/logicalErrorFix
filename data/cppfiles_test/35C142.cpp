#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long f(long long n, long long m, long long b) {
  if (n > m) return 0;
  if (m == (1 << (b + 1)) - 1) return m + 1;
  if (m == 0) return 1;
  if ((n & (1 << b)) == 0 && (m & (1 << b)) == 0) return f(n, m, b - 1);
  if ((n & (1 << b))) return f(n ^ (1 << b), m ^ (1 << b), b - 1);
  return (1 << b) + f(n, m ^ (1 << b), b - 1);
}
void solve() {
  cin >> n >> m;
  long long i, j;
  if (n > m) {
    cout << "0\n";
    return;
  }
  long long ans = 0, b = 0;
  for (i = 30; i >= 0; i--) {
    if (n & (1 << i)) {
      b = i;
      break;
    } else {
      if (m & (1 << i)) {
        ans += (1 << i);
        m ^= (1 << i);
      }
    }
  }
  cout << ans + f(n, m, b) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  long long tc = 0;
  cin >> t;
  while (t--) {
    tc++;
    solve();
  }
}
