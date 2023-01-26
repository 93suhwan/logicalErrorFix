#include <bits/stdc++.h>
using namespace std;
const long long oo = 4e18;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v, ans;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    int indx = n - 2;
    for (int i = n - 1; i > 0; i--) {
      if (indx < 0) break;
      if (v[i].first == 0) continue;
      while (v[indx].first <= 0 && indx > -1) {
        indx--;
      }
      if (indx < 0) break;
      if (indx == i) indx--;
      while (v[i].first > 0) {
        while (v[indx].first <= 0 && indx > -1) {
          indx--;
        }
        if (indx == i) indx--;
        if (indx < 0) break;
        if (v[indx].first >= 0 && v[i].first >= 0) {
          v[indx] = {v[indx].first - 1, v[indx].second};
          v[i] = {v[i].first - 1, v[i].second};
          ans.push_back({v[i].second, v[indx].second});
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto j : ans) cout << j.first << " " << j.second << '\n';
  }
  return 0;
}
