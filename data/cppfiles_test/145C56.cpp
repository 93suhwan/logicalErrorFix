#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, t;
  vector<int> to;
};
node arr[200000];
int idx[200000];
bool vis[200000];
int dfs(int me) {
  int mn = arr[me].t;
  vis[me] = 1;
  for (const auto& i : arr[me].to)
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
      cin >> arr[i].x >> arr[i].y >> arr[i].t, idx[i] = i, vis[i] = 0,
                                               arr[i].to.clear();
    sort(idx, idx + n, [](const int& lhs, const int& rhs) {
      return arr[lhs].x < arr[rhs].x;
    });
    map<int, unordered_set<int>> mp;
    int mid = 0, l = 0, r = 0;
    for (; mid != n; ++mid) {
      for (; arr[idx[l]].x < arr[idx[mid]].x - k;
           mp[arr[idx[l]].y].erase(idx[l]), ++l)
        ;
      for (; r != n && arr[idx[r]].x <= arr[idx[mid]].x + k;
           mp[arr[idx[r]].y].insert(idx[r]), ++r)
        ;
      for (const auto& i : mp[arr[idx[mid]].y])
        if (i != idx[mid])
          arr[idx[mid]].to.push_back(i), arr[i].to.push_back(idx[mid]);
    }
    sort(idx, idx + n, [](const int& lhs, const int& rhs) {
      return arr[lhs].y < arr[rhs].y;
    });
    mp.clear();
    mid = 0, l = 0, r = 0;
    for (; mid != n; ++mid) {
      for (; arr[idx[l]].y < arr[idx[mid]].y - k;
           mp[arr[idx[l]].x].erase(idx[l]), ++l)
        ;
      for (; r != n && arr[idx[r]].y <= arr[idx[mid]].y + k;
           mp[arr[idx[r]].x].insert(idx[r]), ++r)
        ;
      for (const auto& i : mp[arr[idx[mid]].x])
        if (i != idx[mid])
          arr[idx[mid]].to.push_back(i), arr[i].to.push_back(idx[mid]);
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
