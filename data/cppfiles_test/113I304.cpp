#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int sum = 0;
  vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    sum += vec[i];
  }
  sort(vec.begin(), vec.end());
  long long int d;
  cin >> d;
  for (int i = 1; i <= d; i++) {
    long long int x, y;
    cin >> x >> y;
    long long int d = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    cout << d << endl;
    if (d == 0) {
      long long int ans1 = 0, ans2 = 0;
      long long int rs = 0;
      if (x > vec[d]) {
        ans1 = ans1 + (x - vec[d]);
      }
      rs = rs + (sum - vec[d]);
      if (y > rs) {
        ans2 = ans2 + (y - rs);
      }
      cout << ans1 + ans2 << endl;
    } else if (d == vec.size()) {
      long long int ans1 = 0, ans2 = 0;
      long long int rs = 0;
      if (x > vec[d - 1]) {
        ans1 = ans1 + (x - vec[d - 1]);
      }
      rs = rs + (sum - vec[d - 1]);
      if (y > rs) {
        ans2 = ans2 + (y - rs);
      }
      cout << ans1 + ans2 << endl;
    } else {
      long long int ans1 = 0, ans2 = 0;
      long long int mans1 = 0, mans2 = 0;
      long long int rs = 0;
      long long int nrs = 0;
      if (x > vec[d - 1]) {
        ans1 = ans1 + (x - vec[d - 1]);
      }
      if (x > vec[d]) {
        mans1 = mans1 + (x - vec[d]);
      }
      rs = rs + (sum - vec[d - 1]);
      nrs = nrs + (sum - vec[d]);
      if (y > rs) {
        ans2 = ans2 + (y - rs);
      }
      if (y > nrs) {
        mans2 = mans2 + (y - nrs);
      }
      cout << min(ans1 + ans2, mans1 + mans2) << endl;
    }
  }
}
int main() {
  solve();
  return 0;
}
