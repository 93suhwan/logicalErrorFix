#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxlog = 31;
int cnt[maxlog];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    memset(cnt, 0, sizeof(cnt));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int u;
      scanf("%d", &u);
      for (int j = 0; j < maxlog; ++j) {
        if ((u >> j) & 1) cnt[j]++;
      }
    }
    vector<int> ans;
    for (int j = 1; j <= n; ++j) {
      bool ok = true;
      for (int i = 0; i < maxlog; ++i) {
        if (cnt[i]) {
          if (cnt[i] % j != 0) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        ans.push_back(j);
      }
    }
    for (auto u : ans) printf("%d ", u);
    puts("");
  }
}
