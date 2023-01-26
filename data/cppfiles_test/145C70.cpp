#include <bits/stdc++.h>
using namespace std;
const int change_id = 1e6;
int k, base_id;
map<int, map<int, int>> a[2];
struct ItemType {
  int pid;
  int timer;
  bool operator<(const ItemType& rhs) const {
    return pid < rhs.pid || pid == rhs.pid && timer < rhs.timer;
  }
  bool operator==(const ItemType& rhs) const { return pid == rhs.pid; }
};
vector<ItemType> items;
bool check(map<int, int>::const_iterator& it, int val) {
  if (items[it->second].pid < change_id && abs(it->first - val) <= k) {
    items[it->second].pid = base_id;
    return true;
  }
  return false;
}
void dfs(int x, int y) {
  {
    const auto& ax = a[0][x];
    auto ity = ax.find(y);
    if (ity != ax.begin()) {
      --ity;
      if (check(ity, y)) {
        dfs(x, ity->first);
      }
      ++ity;
    }
    if (++ity != ax.end()) {
      if (check(ity, y)) {
        dfs(x, ity->first);
      }
    }
  }
  {
    const auto& ay = a[1][y];
    auto itx = ay.find(x);
    if (itx != ay.begin()) {
      --itx;
      if (check(itx, x)) {
        dfs(itx->first, y);
      }
      ++itx;
    }
    if (++itx != ay.end()) {
      if (check(itx, x)) {
        dfs(itx->first, y);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for (; test > 0; test--) {
    a[0].clear();
    a[1].clear();
    items.clear();
    int n;
    cin >> n >> k;
    for (int id = 0; id < n; id++) {
      int x, y, timer;
      cin >> x >> y >> timer;
      items.push_back(ItemType{id, timer});
      a[0][x][y] = id;
      a[1][y][x] = id;
    }
    for (const auto& x1 : a[0]) {
      for (const auto y1 : x1.second) {
        if (items[y1.second].pid < change_id) {
          base_id = items[y1.second].pid += change_id;
          dfs(x1.first, y1.first);
        }
      }
    }
    sort(items.begin(), items.end());
    auto last = unique(items.begin(), items.end());
    sort(items.begin(), last, [](const ItemType& lhs, const ItemType& rhs) {
      return lhs.timer > rhs.timer;
    });
    int result = -1;
    for (auto it = items.begin(); it != last; ++it) {
      if (it->timer <= result) break;
      result++;
    }
    cout << result << "\r\n";
  }
  return 0;
}
