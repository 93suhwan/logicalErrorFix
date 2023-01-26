#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
const long long modn = 1e9;
const long long N = 1e5 + 5;
long long a[N];
void solve() {
  long long n;
  cin >> n;
  long long jj = 0, oo = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) jj++;
    if (a[i] % 2 == 0) oo++;
  }
  if (abs(jj - oo) >= 2) {
    cout << -1 << '\n';
  }
  long long sum = 0;
  long long now = 2;
  if (a[0] % 2 == 1) {
    for (long long i = 1; i < n; i++) {
      if (a[i] % 2 == 0) {
        sum = abs(i + 1 - now);
        now += 2;
      }
    }
  } else {
    for (long long i = 1; i < n; i++) {
      if (a[i] % 2 == 1) {
        sum = abs(i + 1 - now);
        now += 2;
      }
    }
  }
  cout << sum << '\n';
}
signed main() {
  long long _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
