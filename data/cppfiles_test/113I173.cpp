#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 14;
const int maxq = 1e3 + 11;
const int mad = 998244353;
long long a[maxn], b[maxn];
int main() {
  int n;
  cin >> n;
  set<long long> s;
  map<long long, bool> h;
  long long maxi = -1, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]] = 1;
    maxi = max(a[i], maxi);
    sum += a[i];
    s.insert(a[i]);
  }
  int m;
  cin >> m;
  long long ans = 0;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    if (x >= maxi) {
      ans += x - maxi;
      ans += max(0ll, y - (sum - maxi));
    } else {
      if (h[x] == 1) {
        ans += max(0ll, y - (sum - x));
      } else {
        set<long long>::iterator up, lo;
        up = s.upper_bound(x);
        lo = s.lower_bound(x);
        ans += max(0ll, min(y - (sum - *up), y - (sum - *lo) + x - *lo));
      }
    }
    cout << ans << "\n";
    ans = 0;
  }
  return 0;
}
