#include <bits/stdc++.h>
using namespace std;
long long a[10];
void solve() {
  for (long long i = 1; i <= 7; i++) cin >> a[i];
  sort(a + 1, a + 8);
  cout << a[1] << " " << a[2] << " " << a[7] - a[1] - a[2] << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
