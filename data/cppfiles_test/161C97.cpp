#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n;
    vector<pair<int, int>> set;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      set.push_back({l, r});
      mp[{l, r}] = 1;
    }
    for (int i = 0; i < n; i++) {
      l = set[i].first;
      r = set[i].second;
      if (r == l)
        cout << l << " " << r << " " << l << "\n";
      else {
        for (int j = l; j <= r; j++) {
          if (l > j - 1) {
            if (mp[{j + 1, r}] == 1) {
              cout << l << " " << r << " " << j << "\n";
              break;
            }
          } else if (r < j + 1) {
            if (mp[{l, j - 1}] == 1) {
              cout << l << " " << r << " " << j << "\n";
              break;
            }
          } else {
            if (mp[{l, j - 1}] == 1 && mp[{j + 1, r}] == 1) {
              cout << l << " " << r << " " << j << "\n";
              break;
            }
          }
        }
      }
    }
    cout << "\n";
  }
}
