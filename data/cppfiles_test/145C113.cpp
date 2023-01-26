#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, t;
  vector<int> to;
};
node list[200000];
int idx[200000];
bool vis[200000];
int dfs(int me) {
  int mn = list[me].t;
  vis[me] = 1;
  for (const auto& i : list[me].to)
    if (!vis[i]) mn = min(mn, dfs(i));
  return mn;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i != n; ++i)
      cin >> list[i].x >> list[i].y >> list[i].t, idx[i] = i, vis[i] = 0,
                                                  list[i].to.clear();
    sort(idx, idx + n, [](const int& lhs, const int& rhs) {
      return list[lhs].x < list[rhs].x;
    });
    map<int, set<int>> mp;
    int mid = 0, l = 0, r = 0;
    for (; mid != n; ++mid) {
      for (; list[idx[l]].x < list[idx[mid]].x - k;
           mp[list[idx[l]].y].erase(idx[l]), ++l)
        ;
      for (; r != n && list[idx[r]].x <= list[idx[mid]].x + k;
           mp[list[idx[r]].y].insert(idx[r]), ++r)
        ;
      for (const auto& i : mp[list[idx[mid]].y])
        if (i != idx[mid])
          list[idx[mid]].to.push_back(i), list[i].to.push_back(idx[mid]);
    }
    sort(idx, idx + n, [](const int& lhs, const int& rhs) {
      return list[lhs].y < list[rhs].y;
    });
    mp.clear();
    mid = 0, l = 0, r = 0;
    for (; mid != n; ++mid) {
      for (; list[idx[l]].y < list[idx[mid]].y - k;
           mp[list[idx[l]].x].erase(idx[l]), ++l)
        ;
      for (; r != n && list[idx[r]].y <= list[idx[mid]].y + k;
           mp[list[idx[r]].x].insert(idx[r]), ++r)
        ;
      for (const auto& i : mp[list[idx[mid]].x])
        if (i != idx[mid])
          list[idx[mid]].to.push_back(i), list[i].to.push_back(idx[mid]);
    }
    vector<int> time;
    for (int i = 0; i != n; ++i)
      if (!vis[i]) time.push_back(dfs(i));
    sort(time.begin(), time.end());
    int ans = 0;
    int ll = 0, rr = time.size() - 1;
    for (; rr > ll && time[ll] <= ans; ++ll)
      ;
    for (; rr > ll;) {
      ++ans;
      for (; rr > ll && time[ll] <= ans; ++ll)
        ;
      --rr;
    }
    cout << ans << '\n';
  }
}
