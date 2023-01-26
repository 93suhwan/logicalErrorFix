#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 5e5 + 100;
vector<int> pos[maxn];
int ans[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
        int x;
        cin >> x;
        pos[x].push_back(++k);
      } else {
        int x, y;
        cin >> x >> y;
        if (x == y) {
          continue;
        }
        if (pos[x].size() > pos[y].size()) {
          swap(pos[x], pos[y]);
        }
        for (auto item : pos[x]) {
          pos[y].push_back(item);
        }
        pos[x].clear();
      }
    }
    for (int i = 1; i < maxn; ++i) {
      for (auto item : pos[i]) {
        ans[item] = i;
      }
    }
    for (int i = 1; i <= k; ++i) {
      cout << ans[i] << (i == k ? "\n" : " ");
    }
  }
}
