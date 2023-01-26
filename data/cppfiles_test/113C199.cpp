#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int t;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  long long x, y;
  long long ans;
  long long adding;
  int ind;
  int ind2;
  for (long long& el : a) {
    cin >> el;
    sum += el;
  }
  sort(a.begin(), a.end());
  cin >> t;
  while (t--) {
    cin >> x >> y;
    ind = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (ind == n) ind--;
    adding = max(0LL, x - a[ind]);
    ans = max(y - sum + a[ind], 0LL) + adding;
    ind2 = ind;
    if (ind - 1 >= 0) {
      ind--;
      adding = max(0LL, x - a[ind]);
      ans = min(ans, max(y - sum + a[ind], 0LL) + adding);
    }
    ind = upper_bound(a.begin(), a.end(), a[ind2]) - a.begin();
    if (ind < n) {
      adding = max(0LL, x - a[ind]);
      ans = min(ans, max(y - sum + a[ind], 0LL) + adding);
    }
    cout << ans << '\n';
  }
}
