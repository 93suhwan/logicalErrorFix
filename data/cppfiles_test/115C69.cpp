#include <bits/stdc++.h>
using namespace std;
long long totalDamage(vector<long long> a, long long k) {
  long long ans = 0;
  for (int i = 0; i < (int)a.size() - 1; ++i) {
    ans += min(a[i + 1] - a[i], k);
  }
  ans += k;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long l = 1, r = h;
    while (l < r) {
      long long m = l + (r - l) / 2;
      long long x = totalDamage(a, m);
      if (x == h) {
        l = m;
        break;
      } else if (x < h) {
        l = m + 1;
      } else
        r = m;
    }
    cout << l << "\n";
  }
  return 0;
}
