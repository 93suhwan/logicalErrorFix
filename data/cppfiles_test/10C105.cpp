#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 100;
int T;
int n, k, a[N];
vector<int> v[N];
int ans[N];
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) v[i].clear(), ans[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      v[a[i]].push_back(i);
    }
    int col = 1, cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt = 0;
      for (auto x : v[i]) {
        if (cnt >= k) break;
        ans[x] = col;
        col++;
        col %= (k + 1);
        if (col == 0) col++;
        cnt++;
      }
    }
    if (col > 1) {
      for (int i = n; i >= 1 && col > 1; i--) {
        for (int j = v[i].size() - 1; j >= 0 && col > 1; j--) {
          if (ans[v[i][j]] == col - 1) {
            ans[v[i][j]] = 0;
            col--;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
