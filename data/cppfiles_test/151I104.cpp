#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 5e6 + 7;
vector<vector<int>> q;
int ans[N];
int changeTo[N];
int main() {
  freopen("ans.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Q;
  cin >> Q;
  q.resize(Q);
  memset(changeTo, -1, sizeof changeTo);
  int n = 0;
  for (int i = 0; i < Q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      n++;
      int x;
      cin >> x;
      q[i].push_back(1);
      q[i].push_back(x);
    } else {
      int x, y;
      cin >> x >> y;
      q[i].emplace_back(2);
      q[i].emplace_back(x);
      q[i].emplace_back(y);
    }
  }
  int idx = n - 1;
  for (int i = Q - 1; i >= 0; --i) {
    int t = q[i].front();
    if (t == 1) {
      int x = q[i].back();
      if (~changeTo[x]) {
        x = changeTo[x];
      }
      ans[idx--] = x;
    } else {
      int x = q[i][1];
      int y = q[i].back();
      int c = changeTo[y];
      if (~c)
        changeTo[x] = c;
      else
        changeTo[x] = y;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
