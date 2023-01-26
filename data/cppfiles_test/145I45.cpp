#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mx;
map<int, vector<int>> my;
map<pair<int, int>, int> time_of;
map<pair<int, int>, bool> used;
vector<int> value;
int k = 0;
int dfs(int x, int y) {
  if (used[{x, y}] == true) return time_of[{x, y}];
  used[{x, y}] = true;
  int time = time_of[{x, y}];
  auto b = lower_bound(mx[x].begin(), mx[x].end(), x - k);
  while (b != mx[x].end() && *b <= x + k) {
    time = min(time, dfs(*b, y));
    b++;
  }
  auto b1 = lower_bound(my[y].begin(), my[y].end(), y - k);
  while (b1 != my[y].end() && *b1 <= y + k) {
    time = min(time, dfs(x, *b1));
    b1++;
  }
  return time;
}
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    cin >> n >> k;
    vector<int> ans;
    vector<pair<int, int>> x(n);
    value.clear();
    used.clear();
    mx.clear();
    my.clear();
    time_of.clear();
    ans.clear();
    for (int i = 0; i < n; i++) {
      int x, y, time;
      cin >> x >> y >> time;
      mx[x].push_back(y);
      my[y].push_back(x);
      time_of[{x, y}] = time;
      used[{x, y}] = false;
    }
    for (auto &i : mx) {
      sort(i.second.begin(), i.second.end());
    }
    for (auto &i : mx) {
      for (auto j : i.second) {
        if (used[{i.first, j}] == false) {
          ans.push_back(dfs(i.first, j));
        }
      }
    }
    sort(ans.begin(), ans.end());
    int cnt = 0;
    int size = ans.size() - 1;
    for (int i = 0; i < ans.size(); i++) {
      if (size - i - 1 < 0) {
        cout << i << endl;
        break;
      }
      if (ans[size - i - 1] <= i) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
