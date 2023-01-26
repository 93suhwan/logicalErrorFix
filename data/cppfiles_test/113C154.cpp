#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    int p = lower_bound(a.begin(), a.end(), x) - a.begin();
    long long res = x + y;
    if (p < n) res = min(res, max(long long(0), y - (sum - a[p])));
    if (p - 1 >= 0)
      res = min(res, x - a[p - 1] + max(long long(0), y - (sum - a[p - 1])));
    cout << res << "\n";
  }
  return 0;
}
