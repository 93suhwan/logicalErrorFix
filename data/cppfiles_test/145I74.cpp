#include <bits/stdc++.h>
using namespace std;
struct ItemType {
  int pid;
  int timer;
  bool operator<(const ItemType& rhs) const {
    return pid < rhs.pid || pid == rhs.pid && timer < rhs.timer;
  }
  bool operator==(const ItemType& rhs) const { return pid == rhs.pid; }
};
vector<ItemType> items;
map<int, map<int, int>> ax, ay;
int find_root(int id) {
  const int first_id = id;
  for (; id != items[id].pid; id = items[id].pid)
    ;
  const int root_id = id;
  for (id = first_id; id != items[id].pid;) {
    id = items[id].pid;
    items[id].pid = root_id;
  }
  return root_id;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for (; test > 0; test--) {
    ax.clear();
    ay.clear();
    items.clear();
    int n, k;
    cin >> n >> k;
    for (int id = 0; id < n; id++) {
      int x, y, timer;
      cin >> x >> y >> timer;
      items.push_back(ItemType{id, timer});
      ax[x][y] = id;
      ay[y][x] = id;
    }
    for (const auto& x1 : ax) {
      int py = INT_MIN;
      int pid = INT_MIN;
      for (const auto y1 : x1.second) {
        if (y1.first <= py + k) {
          items[y1.second].pid = pid;
        } else {
          pid = y1.second;
        }
        py = y1.first;
      }
    }
    for (const auto& y2 : ay) {
      int px = INT_MIN;
      int pid = INT_MIN;
      for (const auto x2 : y2.second) {
        if (x2.first <= px + k) {
          items[find_root(x2.second)].pid = pid;
        } else {
          pid = find_root(x2.second);
        }
        px = x2.first;
      }
    }
    for (int id = 0; id < n; id++) find_root(id);
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
