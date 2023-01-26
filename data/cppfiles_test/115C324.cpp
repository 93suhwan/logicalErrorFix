#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> v;
    long long y = h;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long ans = h / n;
    if (h % n != 0) ans++;
    for (long long i = 0; i < n - 1; i++) {
      long long x = a[i + 1] - a[i];
      if (min(ans, x) == x) {
        y = y - x;
      } else {
        v.push_back(x);
      }
    }
    v.push_back(1000000000000000001);
    sort(v.begin(), v.end());
    while ((v.size() > 0) && (y > 0)) {
      auto it = v.begin();
      long long p = (*it) * (v.size());
      if (p == y) {
        y = y - p;
        ans = (*it);
      } else if (p < y) {
        y = y - (*it);
        v.erase(it);
      } else {
        long long z = (v.size());
        ans = y / z;
        if (y % z != 0) ans++;
        break;
      }
    }
    cout << ans << endl;
  }
}
