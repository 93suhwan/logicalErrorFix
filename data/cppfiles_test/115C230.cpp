#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  long long int n, h;
  cin >> n >> h;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) return h;
  long long int lo = 1;
  long long int hi = h;
  long long int ans = hi;
  while (lo <= hi) {
    long long int mid = lo + (hi - lo) / 2;
    long long int temph = 0;
    for (int i = 0; i < n; i++) {
      if (i == n - 1)
        temph += mid;
      else
        temph += min(a[i + 1] - a[i], mid);
    }
    if (temph >= h) {
      ans = min(ans, mid);
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}
