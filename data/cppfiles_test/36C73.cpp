#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 1e3;
const long long MOD = 1e9 + 7;
const long long inf = 1e10;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long Q;
  cin >> Q;
  while (Q--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    if (n % 2 == 0) {
      n /= 2;
      for (long long i = 0; i < n; ++i) cout << "a";
      cout << "b";
      for (long long i = 1; i < n; ++i) cout << "a";
    } else {
      n /= 2;
      for (long long i = 0; i < n; ++i) cout << "a";
      cout << "bc";
      for (long long i = 1; i < n; ++i) cout << "a";
    }
    cout << '\n';
  }
  return 0;
}
