#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3 * 1e5 + 10, maxm = maxn * maxn * 4, mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1), eps = 1e-8;
long long T, n;
long long a[maxn];
bool solve() {
  if (n % 2 == 0) return 1;
  for (long long i = 1; i < n; i++) {
    if (a[i] >= a[i + 1]) return 1;
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (solve())
      cout << "yes"
           << "\n";
    else
      cout << "no"
           << "\n";
  }
  return 0;
}
