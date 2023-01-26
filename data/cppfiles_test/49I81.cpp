#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int n;
vector<long long int> tree[1048576];
long long int ans[1048576], a[1048576], cnt[1048576];
vector<long long int> ql[1048576], qk[1048576], qi[1048576];
set<long long int> shits[1048576];
long long int pre[1048576];
void moveUp(long long int i) { pre[i]--; }
void moveDown(long long int i) { pre[i]++; }
void dfs(long long int i, long long int depth) {
  moveUp(cnt[a[i]]);
  shits[cnt[a[i]]].erase(a[i]);
  cnt[a[i]]++;
  shits[cnt[a[i]]].insert(a[i]);
  for (long long int child : tree[i]) dfs(child, depth + 1);
  for (long long int j = 0; j < ql[i].size(); j++) {
    long long int curL = ql[i][j];
    long long int curK = qk[i][j];
    long long int curI = qi[i][j];
    long long int l = curL - 1, r = depth + 1;
    while (l + 1 < r) {
      long long int mid = (l + r) / 2;
      if (pre[mid] - pre[curL - 1] >= curK)
        r = mid;
      else
        l = mid;
    }
    if (r < n + 1) ans[curI] = 1 + (*shits[r].begin());
  }
  shits[cnt[a[i]]].erase(a[i]);
  cnt[a[i]]--;
  shits[cnt[a[i]]].insert(a[i]);
  moveDown(cnt[a[i]]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t-- > 0) {
    long long int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      cnt[i] = 0;
      shits[0].insert(a[i]);
    }
    for (int i = 1; i < n; i++) {
      long long int x;
      cin >> x;
      tree[x - 1].push_back(i);
    }
    for (int i = 0; i < q; i++) {
      long long int v, l, k;
      cin >> v >> l >> k;
      v--;
      ql[v].push_back(l);
      qk[v].push_back(k);
      qi[v].push_back(i);
      ans[i] = -1;
    }
    for (int i = 0; i <= n + 10; i++) pre[i] = n;
    dfs(0, 0);
    for (int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) {
      tree[i].clear();
      shits[i].clear();
    }
    for (int i = 0; i < q; i++) {
      ql[i].clear();
      qk[i].clear();
      qi[i].clear();
    }
  }
}
