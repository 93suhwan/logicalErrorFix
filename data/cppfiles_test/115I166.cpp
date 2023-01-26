#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  long long int n, h;
  cin >> n >> h;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) return h;
  long long int mindist = 1e18 + 7;
  long long int maxdist = 0;
  for (int i = 1; i < n; i++) {
    mindist = min(mindist, a[i] - a[i - 1]);
    maxdist = max(maxdist, a[i] - a[i - 1]);
  }
  long long int mink = ceil(h / (float)n);
  if (mink <= mindist) return mink;
  long long int secondsCovered = a[n - 1] - a[0] + 1;
  if (h > secondsCovered + maxdist - 1) return h - secondsCovered - maxdist + 1;
  long long int lo = mindist + 1;
  long long int hi = maxdist;
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
