#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int n;
vector<int> tree[1048576];
int ans[1048576], a[1048576], cnt[1048576];
vector<int> ql[1048576], qk[1048576], qi[1048576];
unordered_set<int> shits[1048576];
int pre[1048576];
void dfs(int i, int depth) {
  pre[cnt[a[i]]]--;
  shits[cnt[a[i]]].erase(a[i]);
  cnt[a[i]]++;
  shits[cnt[a[i]]].insert(a[i]);
  for (int child : tree[i]) dfs(child, depth + 1);
  for (int j = 0; j < ql[i].size(); j++) {
    int curL = ql[i][j];
    int curK = qk[i][j];
    int curI = qi[i][j];
    int l = curL - 1, r = depth + 1;
    int ask = curK + pre[curL - 1];
    if (ask >= n + 1) continue;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (pre[mid] >= ask)
        r = mid;
      else
        l = mid;
    }
    if (r < depth + 1) ans[curI] = 1 + (*shits[r].begin());
  }
  shits[cnt[a[i]]].erase(a[i]);
  cnt[a[i]]--;
  shits[cnt[a[i]]].insert(a[i]);
  pre[cnt[a[i]]]++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      cnt[i] = 0;
      shits[0].insert(a[i]);
    }
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      tree[x - 1].push_back(i);
    }
    for (int i = 0; i < q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      v--;
      ql[v].push_back(l);
      qk[v].push_back(k);
      qi[v].push_back(i);
      ans[i] = -1;
    }
    for (int i = 0; i <= n + 5; i++) pre[i] = n;
    dfs(0, 1);
    for (int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << '\n';
    shits[0].clear();
    for (int i = 0; i < n; i++) {
      tree[i].clear();
      ql[i].clear();
      qk[i].clear();
      qi[i].clear();
    }
  }
}
