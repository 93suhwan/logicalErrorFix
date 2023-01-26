#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 1e9 + 7;
const long long nmax = 50 + 16;
const long long inf = LLONG_MAX / 2;
long long testCase;
map<long long, long long> a;
void solve() {
  long long n, z = 0, pre = 0;
  a.clear();
  cin >> n;
  a[0] = 0;
  for (long long i = 1; i <= n; i++) {
    char x;
    cin >> x;
    pre += (x == 'a' ? 1 : -1);
    if ((a[pre] || !pre) && !z) {
      z = 1;
      cout << a[pre] + 1 << ' ' << i;
    }
    a[pre] = i;
  }
  if (!z) {
    cout << "-1 -1";
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  testCase = 1;
  cin >> testCase;
  while (testCase--) solve();
  return 0;
}
