#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long n, a[N], b[N];
bool st[N];
void init() { memset(st, 0, sizeof st); }
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  long long x = max_element(a + 1, a + n + 1) - a;
  long long y = max_element(b + 1, b + n + 1) - b;
  long long q = 10;
  while (q--) {
    for (long long i = 1; i <= n; i++) {
      if (a[i] >= a[y] && b[i] < a[y]) {
        y = i;
      }
      if (b[i] >= b[x] && a[i] < a[x]) {
        x = i;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] >= a[x] || b[i] >= b[y])
      cout << 1;
    else
      cout << 0;
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    init();
    solve();
  }
  return 0;
}
