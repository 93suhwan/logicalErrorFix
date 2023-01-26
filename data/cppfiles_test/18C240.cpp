#include <bits/stdc++.h>
using namespace std;
bool intersect(pair<int, int> c, pair<int, int> d) {
  if (c.first > d.first) swap(c, d);
  return c.second > d.first and c.second < d.second;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> aa(2 * n, 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < k; i++) {
      int v, u;
      cin >> v >> u;
      v--;
      u--;
      int x1 = min(v, u);
      int y1 = max(v, u);
      edges.push_back({x1, y1});
      aa[x1] = -1;
      aa[y1] = -1;
    }
    vector<int> bb;
    bb.clear();
    for (int i = 0; i < 2 * n; i++)
      if (aa[i] == 1) bb.push_back(i);
    int u = bb.size() / 2;
    for (int i = 0; i < u; i++) edges.push_back({bb[i], bb[i + u]});
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans += intersect(edges[i], edges[j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
