#include <bits/stdc++.h>
using namespace std;
struct Event {
  int x, y, m, id;
};
map<int, vector<Event> > mp;
int T, N;
int ans[200010];
Event E[200010];
int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    mp.clear();
    for (int i = 1; i <= N; i++) {
      Event e;
      e.id = i;
      cin >> e.x >> e.y >> e.m;
      E[i] = e;
      mp[e.x + e.y - e.m].push_back(e);
    }
    int ret = 0;
    for (auto x : mp) {
      vector<Event> v = x.second;
      vector<vector<int> > segs(0);
      for (auto e : v)
        segs.push_back(
            vector<int>{max(e.x - e.m, 0), e.x - max(0, e.m - e.y), e.id});
      sort(segs.begin(), segs.end(), [&](vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] > b[0];
      });
      for (int l = 0, r; l < (int)segs.size(); l = r + 1) {
        r = l;
        ++ret;
        int curr = segs[l][1];
        while (r < segs.size() - 1 && segs[r + 1][0] <= curr) ++r;
        for (int k = l; k <= r; k++) ans[segs[k][2]] = E[segs[k][2]].x - curr;
      }
    }
    cout << ret << endl;
    for (int i = 1; i <= N; i++)
      cout << ans[i] << " " << E[i].m - ans[i] << endl;
  }
  return 0;
}
