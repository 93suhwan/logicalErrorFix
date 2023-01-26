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
  st[x] = 1;
  for (long long i = 1; i <= n; i++) {
    if (b[i] > b[x]) st[i] = 1;
  }
  x = max_element(b + 1, b + n + 1) - b;
  st[x] = 1;
  for (long long i = 1; i <= n; i++) {
    if (a[i] > a[x]) st[i] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    cout << st[i];
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
