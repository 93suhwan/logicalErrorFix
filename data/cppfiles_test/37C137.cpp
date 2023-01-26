#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
void solve() {
  long long n, m;
  cin >> n >> m;
  set<long long> s;
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    s.insert(b);
  }
  long long val = -1;
  for (long long i = 1; i <= n; i++) {
    if (s.count(i) == 0) {
      val = i;
      break;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (i == val)
      continue;
    else
      cout << val << " " << i << endl;
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
