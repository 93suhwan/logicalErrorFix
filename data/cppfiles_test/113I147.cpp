#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> b(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  sort(b.begin(), b.end());
  long long m;
  cin >> m;
  vector<pair<long long, long long>> a(m);
  for (long long i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < m; i++) {
    long long ans1 = 1e18, ans2 = 1e18;
    auto x = upper_bound(b.begin(), b.end(), a[i].first);
    if (x != b.end()) {
      ans1 = 0;
      if (*x < a[i].first) ans1 += (a[i].first - *x);
      long long y = sum - *x;
      if (y < a[i].second) ans1 += (a[i].second - y);
    }
    if (x != b.begin()) {
      --x;
      ans2 = 0;
      if (*x < a[i].first) ans2 += (a[i].first - *x);
      long long y = sum - *x;
      if (y < a[i].second) ans2 += (a[i].second - y);
    }
    cout << min(ans1, ans2) << endl;
  }
  return 0;
}
