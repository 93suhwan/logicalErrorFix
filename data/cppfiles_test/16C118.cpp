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
    priority_queue<pair<int, int>> qe;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 0) qe.push({x, i + 1});
    }
    while (qe.size() > 1) {
      int i = qe.top().second, cur = qe.top().first;
      qe.pop();
      int j = qe.top().second, curj = qe.top().first;
      qe.pop();
      ans.push_back({i, j});
      if (cur > 1) {
        qe.push({cur - 1, i});
      }
      if (curj > 1) {
        qe.push({curj - 1, j});
      }
    }
    cout << ans.size() << '\n';
    for (auto j : ans) cout << j.first << " " << j.second << '\n';
  }
  return 0;
}
