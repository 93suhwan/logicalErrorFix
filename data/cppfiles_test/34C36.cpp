#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
const int N2 = 1 << 13;
int a[N2], b[N2];
vector<int> vc[N + 9];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    vc[a].push_back(i);
  }
  int *pre = a, *cur = b;
  pre[0] = 0;
  for (int i = 1; i < N2; ++i) {
    pre[i] = INT_MAX;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < N2; ++j) {
      cur[j] = pre[j];
    }
    for (int j = 0; j < N2; ++j) {
      auto it = upper_bound(vc[i].begin(), vc[i].end(), pre[j]);
      if (it != vc[i].end()) {
        cur[i ^ j] = min(cur[i ^ j], *it);
      }
    }
    swap(pre, cur);
  }
  vector<int> ans;
  for (int i = 0; i < N2; ++i) {
    if (pre[i] != INT_MAX) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i : ans) printf("%d ", i);
  printf("\n");
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
