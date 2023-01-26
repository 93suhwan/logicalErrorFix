#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10;
long long min(long long a, long long b) { return a > b ? b : a; }
long long a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum <= k) {
      cout << 0 << endl;
      continue;
    }
    sort(a, a + n);
    long long ans = 1e18 + 10, res = sum;
    long long times = 0;
    while (1) {
      long long times1 = times;
      long long res1 = res;
      for (int i = n - 1; i > 0; i--) {
        res1 -= (a[i] - a[0]);
        times1++;
        if (res1 <= k) break;
      }
      times++;
      a[0]--;
      res--;
      if (res1 > k) continue;
      if (ans >= times1)
        ans = times1;
      else
        break;
    }
    cout << ans << endl;
  }
}
