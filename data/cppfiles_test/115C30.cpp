#include <bits/stdc++.h>
using namespace std;
bool get(vector<long long> &a, int n, long long h, long long k) {
  long long sm = 0, end = a[sm] + k - 1;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (end < a[i]) {
      ans += (end - a[sm] + 1);
      sm = i;
    }
    end = a[i] + k - 1;
  }
  ans += (end - a[sm] + 1);
  return (ans >= h);
}
long long fun(vector<long long> &a, int n, long long h) {
  long long mn = 1, mx = h;
  while (mn <= mx) {
    long long mid = (mn + mx) / 2ll;
    if (get(a, n, h, mid))
      mx = mid - 1;
    else
      mn = mid + 1;
  }
  return mn;
}
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> a(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    a[n] = LONG_MAX;
    if (n >= h)
      cout << 1 << endl;
    else
      cout << fun(a, n, h) << endl;
  }
  return 0;
}
