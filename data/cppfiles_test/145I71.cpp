#include <bits/stdc++.h>
using namespace std;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for (; test > 0; test--) {
    a[0].clear();
    a[1].clear();
    items.clear();
    int n, k;
    cin >> n >> k;
    for (int id = 0; id < n; id++) {
      int x, y, timer;
      cin >> x >> y >> timer;
      items.push_back(ItemType{id, timer});
      a[0][x][y] = id;
      a[1][y][x] = id;
    }
    for (auto& s : a) {
      for (const auto& i : s) {
        int prev_val = INT_MIN;
        int interval_id = INT_MIN;
        for (const auto j : i.second) {
          if (j.first > prev_val + k) {
            interval_id = items[j.second].pid;
          } else {
            items[j.second].pid = interval_id;
          }
          prev_val = j.first;
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
