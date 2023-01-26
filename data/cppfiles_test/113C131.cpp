#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &x : v) cin >> x;
    long long m;
    cin >> m;
    vector<long long> x(m), y(m);
    for (int i = 0; i < m; ++i) {
      cin >> x[i] >> y[i];
    }
    sort(v.begin(), v.end());
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    for (int i = 0; i < m; ++i) {
      long long ans1(0);
      long long ind = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
      if (ind == n) ind--;
      long long p = v[ind];
      if (p < x[i]) {
        ans1 += x[i] - p;
      }
      long long s = sum - p;
      if (s < y[i]) {
        ans1 += y[i] - s;
      }
      long long ans2(0);
      if (ind > 0) {
        p = v[ind - 1];
      }
      if (p < x[i]) {
        ans2 += x[i] - p;
      }
      s = sum - p;
      if (s < y[i]) {
        ans2 += y[i] - s;
      }
      if (ind == 0) {
        cout << ans1 << "\n";
      } else
        cout << min(ans2, ans1) << "\n";
    }
  }
  return 0;
}
