#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<int> a;
  for (int i = 0; i < 10052; i++) {
    a.push_back(i);
  }
  int n;
  cin >> n;
  vector<long long int> v(n);
  long long int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s = s + v[i];
  }
  sort(v.begin(), v.end());
  int q;
  cin >> q;
  while (q--) {
    long long int x, y;
    cin >> x >> y;
    auto it = lower_bound(v.begin(), v.end(), x);
    auto itr = upper_bound(v.begin(), v.end(), x);
    long long int ans1 = 0, ans2 = 0;
    if (v[0] >= x) {
      long long int d = s - v[0];
      if (y > d) {
        ans1 = y - d;
        cout << ans1 << "\n";
        ;
      } else
        cout << 0 << "\n";
      ;
    } else if (v[n - 1] <= x) {
      long long int d = s - v[n - 1];
      if (y > d) {
        ans1 = (x - v[n - 1]) + (y - d);
        cout << ans1 << "\n";
        ;
      } else {
        ans1 = (x - v[n - 1]);
        cout << ans1 << "\n";
        ;
      }
    } else {
      if (*it > x) it--;
      ans1 += (x - *it);
      long long int d = s - *it;
      if (y > d) {
        ans1 += (y - d);
      }
      if (*itr < x) itr++;
      d = s - *itr;
      if (y > d) ans2 += (y - d);
      ans1 = min(ans1, ans2);
      cout << ans1 << "\n";
      ;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
