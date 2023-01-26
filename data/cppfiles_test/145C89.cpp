#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
struct disjointSet {
  std::vector<int> boss;
  std::vector<int> depth;
  std::vector<int> time;
  int size;
  disjointSet(int _size) {
    size = _size;
    boss.resize(size, 0);
    depth.resize(size, 0);
    time.resize(size, 0);
    for (int i = 0; i < size; i++) {
      boss[i] = i;
    }
  }
  int query(int vertax) {
    if (boss[vertax] == vertax) {
      return vertax;
    } else {
      boss[vertax] = query(boss[vertax]);
      return boss[vertax];
    }
  }
  bool merge(int vertax1, int vertax2) {
    int bossOfVertax1 = query(vertax1);
    int bossOfVertax2 = query(vertax2);
    if (bossOfVertax1 == bossOfVertax2) {
      return false;
    }
    int b1 = bossOfVertax1;
    int b2 = bossOfVertax2;
    if (depth[bossOfVertax1] < depth[bossOfVertax2]) {
      boss[bossOfVertax1] = bossOfVertax2;
      time[b2] = min(time[b1], time[b2]);
    } else if (depth[bossOfVertax1] > depth[bossOfVertax2]) {
      boss[bossOfVertax2] = bossOfVertax1;
      time[b1] = min(time[b1], time[b2]);
    } else {
      boss[bossOfVertax1] = bossOfVertax2;
      time[b2] = min(time[b1], time[b2]);
      depth[bossOfVertax2] += 1;
    }
    return true;
  }
};
bitset<200000> vis;
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) vis[i] = false;
    vector<array<int, 3> > vec(n);
    disjointSet DSU(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) cin >> vec[i][j];
      cin >> DSU.time[i];
      vec[i][2] = i;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i + 1 < n; i++) {
      auto [x1, y1, id1] = vec[i];
      auto [x2, y2, id2] = vec[i + 1];
      if (x1 == x2 and y2 - y1 <= k) DSU.merge(id1, id2);
    }
    for (int i = 0; i < n; i++) swap(vec[i][0], vec[i][1]);
    sort(vec.begin(), vec.end());
    for (int i = 0; i + 1 < n; i++) {
      auto [y1, x1, id1] = vec[i];
      auto [y2, x2, id2] = vec[i + 1];
      if (y1 == y2 and x2 - x1 <= k) DSU.merge(id1, id2);
    }
    vector<int> t;
    for (int i = 0; i < n; i++) {
      int tmp = DSU.query(i);
      if (!vis[tmp]) t.emplace_back(DSU.time[tmp]);
      vis[tmp] = true;
    }
    sort(t.rbegin(), t.rend());
    int ans = t.size() - 1;
    for (int i = 0; i + 1 < t.size(); i++) {
      if (t[i + 1] <= i) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
