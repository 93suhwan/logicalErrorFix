#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5, M = 2000;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
const double pai = acos(-1);
long long T, n;
long long va[N];
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    long long mid = r / 2;
    if (l > mid) {
      cout << r - l << "\n";
      continue;
    }
    if (r % mid == 0)
      cout << mid - 1;
    else
      cout << mid;
    cout << "\n";
  }
  return 0;
}
