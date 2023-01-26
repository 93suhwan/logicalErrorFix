#include <bits/stdc++.h>
using namespace std;
const long long MXN = 2e5 + 20, Inf = 1e18 + 20;
long long a[MXN], n, h;
bool check(long long k) {
  long long res = 0;
  for (int i = 0; i < n - 1; i++) {
    res += min(k, a[i + 1] - a[i]);
  }
  res += k;
  return (res >= h);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long l = 0, r = Inf;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (check(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << "\n";
  }
}
