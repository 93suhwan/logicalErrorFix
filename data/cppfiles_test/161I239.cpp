#include <bits/stdc++.h>
using namespace std;
bool compareInterval(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first) return true;
  if (p1.first == p2.first) return p1.second > p2.second;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      vec.push_back({l, r});
      mp[{l, r}] = 1;
    }
    sort(vec.begin(), vec.end(), compareInterval);
    for (int i = 0; i < n; i++) {
      l = vec[i].first;
      r = vec[i].second;
      if (l == r) {
        cout << l << " " << r << " " << l << "\n";
      } else {
        for (int j = l; j <= r; j++) {
          if (mp[{l, j - 1}] == 1 || mp[{j + 1, r}] == 1) {
            cout << l << " " << r << " " << j << "\n";
            break;
          }
        }
      }
    }
    cout << "\n";
  }
}
