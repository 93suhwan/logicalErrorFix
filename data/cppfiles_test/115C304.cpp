#include <bits/stdc++.h>
using namespace std;
int a[100];
static inline long long min(long long a, long long b) { return a < b ? a : b; }
int main() {
  int t, n, i;
  long long h, d, st, dr, k;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (i = 0; i < n; i++) cin >> a[i];
    st = 0;
    dr = h;
    while (dr - st > 1) {
      k = (st + dr) / 2;
      d = k;
      for (i = 0; i < n - 1; i++) d += min(k, a[i + 1] - a[i]);
      if (d < h)
        st = k;
      else
        dr = k;
    }
    cout << dr << "\n";
  }
  return 0;
}
