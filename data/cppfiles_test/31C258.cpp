#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long n;
long long f[N];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> f[i];
  if (n % 2) {
    if (f[1] + f[2])
      cout << f[3] << ' ' << f[3] << ' ' << -f[1] - f[2] << ' ';
    else if (f[2] + f[3])
      cout << -f[2] - f[3] << ' ' << f[1] << ' ' << f[1] << ' ';
    else
      cout << f[2] << ' ' << -f[3] - f[1] << ' ' << f[2] << ' ';
    for (long long i = 4; i <= n; i += 2)
      cout << f[i + 1] << ' ' << -f[i] << ' ';
  } else {
    for (long long i = 1; i <= n; i += 2)
      cout << f[i + 1] << ' ' << -f[i] << ' ';
  }
  puts("");
}
signed main() {
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
