#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    vector<pair<int, int> > a(n);
    for (auto &z : a) cin >> z.first >> z.second;
    sort((a).begin(), (a).end(), [&](pair<int, int> a, pair<int, int> b) {
      return a.second - a.first > b.second - b.first;
    });
    for (auto &z : a) mp[z] = 1;
    for (auto &z : a) {
      for (int i = z.first; i <= z.second; i++) {
        int l = z.first, r = i - 1;
        int ok = 1;
        ok &= (l > r || mp[{l, r}]);
        l = i + 1, r = z.second;
        ok &= (l > r || mp[{l, r}]);
        if (ok) {
          cout << z.first << ' ' << z.second << ' ' << i << '\n';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
