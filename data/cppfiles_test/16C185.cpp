#include <bits/stdc++.h>
using namespace std;
const long long mxn = 200005;
const int mod = 1000000007;
void solve_case(int tc) {
  int n;
  cin >> n;
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x != 0) {
      s.insert({x, i});
    }
  }
  vector<pair<int, int>> talks;
  while (s.size() > 1) {
    auto it1 = s.begin(), it2 = s.end();
    it2--;
    pair<int, int> ft = (*it1);
    pair<int, int> sd = (*it2);
    if (ft.first == 0) {
      s.erase(it1);
      continue;
    }
    if (sd.first == 0) {
      s.erase(it2);
      continue;
    }
    talks.push_back({ft.second, sd.second});
    s.erase(it1);
    s.erase(it2);
    s.insert({ft.first - 1, ft.second});
    s.insert({sd.first - 1, sd.second});
  }
  cout << talks.size() << endl;
  for (auto x : talks) {
    cout << x.first << " " << x.second << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test_case = 1;
  cin >> test_case;
  for (int tc = 1; tc <= test_case; tc++) {
    solve_case(tc);
  }
  return 0;
}
