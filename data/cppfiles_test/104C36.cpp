#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int mx = 1e7 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int> > a(n);
    long long int tot = 0;
    long long int mn = 0, mx = 0;
    vector<pair<long long int, long long int> > sb(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      tot += a[i].first - a[i].second;
      if (a[i].second - m >= 0) {
        sb[i].first = 0;
      } else {
        sb[i].first = m - a[i].second;
      }
      if (a[i].first >= m) {
        sb[i].second = m;
      } else {
        sb[i].second = a[i].first;
      }
      mn += sb[i].first;
      mx += sb[i].second;
    }
    tot += m * n;
    long long int bl;
    if (mn > tot / 2) {
      bl = abs(tot - 2 * mn);
      for (int i = 0; i < n; i++) {
        a[i].first = sb[i].first;
        a[i].second = (m - sb[i].first);
      }
    } else if (mx < tot / 2) {
      bl = abs(tot - 2 * mx);
      for (int i = 0; i < n; i++) {
        a[i].first = sb[i].second;
        a[i].second = (m - sb[i].second);
      }
    } else {
      if (tot & 1)
        bl = 1;
      else
        bl = 0;
      long long int inc = tot / 2 - mn;
      for (int i = 0; i < n; i++) {
        if (sb[i].second - sb[i].first <= inc) {
          inc -= sb[i].second - sb[i].first;
          a[i].first = sb[i].second;
          a[i].second = (m - sb[i].second);
        } else {
          sb[i].first += inc;
          inc = 0;
          a[i].first = sb[i].first;
          a[i].second = (m - sb[i].first);
        }
      }
    }
    cout << bl << "\n";
    for (pair<int, int> pr : a) {
      cout << pr.first << " " << pr.second << "\n";
    }
  }
  return 0;
}
