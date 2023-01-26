#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long a[N];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long start = 1;
  if (n % 2 == 1) {
    if (a[1] + a[2] != 0)
      cout << -a[3] << " " << -a[3] << " " << a[1] + a[2] << " ";
    else if (a[1] + a[3] != 0)
      cout << -a[2] << " " << a[1] + a[3] << " " << -a[2] << " ";
    else
      cout << a[2] + a[3] << " " << -a[1] << " " << -a[1] << " ";
    start += 3;
  }
  while (start < n) {
    cout << -a[start + 1] << " " << a[start] << " ";
    start += 2;
  }
  puts("");
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
