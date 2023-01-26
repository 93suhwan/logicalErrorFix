#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (m < n) {
      cout << 0 << endl;
      continue;
    }
    long long ans = 0x3f3f3f3f;
    for (int i = 0; i <= 30; i++) {
      long long x = (n >> i), y = (m >> i);
      x <<= i;
      y = (y + 1) << i;
      ans = min(ans, x ^ y);
    }
    cout << ans << endl;
  }
  return 0;
}
