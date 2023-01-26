#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  pair<int, int> arr[n];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[i] = {a, i};
  }
  sort(arr, arr + n);
  set<int> st[k + 1];
  vector<int> ans(n, 0);
  int last = 1;
  for (int i = 0; i < n; i++) {
    if (st[last].find(arr[i].first) == st[last].end()) {
      st[last].insert(arr[i].first);
      ans[arr[i].second] = last;
      last = (last + 1) % k;
      if (last == 0) {
        last = k;
      }
    }
  }
  vector<bool> vis(k + 1, 0);
  for (int i = 0; i < n; i++) {
    if (st[ans[i]].size() > st[k].size() && !vis[ans[i]]) {
      vis[ans[i]] = 1;
      ans[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
