#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long maxn = 200005;
const long long inf = 0x3f3f3f3f;
bool p(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, now = 3;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      while (!p(now)) {
        now++;
      }
      cout << now << " ";
      now++;
    }
    cout << "\n";
  }
}
