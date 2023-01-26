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
  long long maxi = -1, sum = 0, mini = 1e18 + 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mini = min(a[i], mini);
    h[a[i]] = 1;
    maxi = max(a[i], maxi);
    sum += a[i];
    s.insert(a[i]);
  }
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    long long ans = 0;
    scanf("%ld", &x);
    scanf("%ld", &y);
    if (x >= maxi) {
      ans += x - maxi;
      ans += max(0ll, max(0ll, y - (sum - maxi)));
      cout << ans << "\n";
      continue;
    }
    if (h[x] == 1) {
      ans += max(0ll, max(0ll, y - (sum - x)));
      cout << ans << "\n";
      continue;
    }
    set<long long>::iterator up, lo;
    up = s.upper_bound(x);
    if (mini >= x) {
      ans = max(0ll, y - (sum - mini));
    } else {
      lo = s.lower_bound(x);
      lo--;
      ans += max(0ll, min(max(y - (sum - *up), 0ll),
                          max(y - (sum - *lo), 0ll) + x - *lo));
    }
    cout << ans << "\n";
  }
  return 0;
}
