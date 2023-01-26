#include <bits/stdc++.h>
using namespace std;
const int N = (1e6 + 12);
const int mod = (1e9 + 7);
const int inf = (1e9 + 7);
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int q;
  cin >> q;
  vector<pair<int, int>> vec;
  while (q--) {
    int t, x;
    cin >> t;
    if (t == 1) {
      cin >> x;
      vec.push_back({0, x});
    } else {
      int y;
      cin >> y >> x;
      vec.push_back({y, x});
    }
  }
  vector<int> ans;
  reverse(vec.begin(), vec.end());
  for (auto to : vec) {
    if (to.first == 0) {
      if (a[to.second]) {
        ans.push_back(a[to.second]);
      } else {
        ans.push_back(to.second);
      }
    } else {
      a[to.first] = to.second;
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto to : ans) {
    cout << to << " ";
  }
}
