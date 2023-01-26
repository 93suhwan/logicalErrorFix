#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> b, c;
    for (long long i = 0; i < n; i++) {
      if (a[i] > 0) {
        b.push_back(a[i]);
      } else {
        c.push_back(-1 * a[i]);
      }
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long ans = 0;
    for (long long i = b.size() - 1; i >= 0; i -= k) {
      ans += 2 * b[i];
    }
    for (long long i = c.size() - 1; i >= 0; i -= k) {
      ans += 2 * c[i];
    }
    long long mx = 0;
    if (b.size() > 0) {
      mx = b[b.size() - 1];
    }
    if (c.size() > 0) {
      mx = max(mx, c[c.size() - 1]);
    }
    ans -= mx;
    cout << ans << "\n";
  }
  return 0;
}
