#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 9;
const int N2 = 10000;
int a[N], minv[N];
bool vis[N], ok[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n; i >= 1; --i) {
    if (!vis[a[i]]) ok[i] = true;
    vis[a[i]] = true;
  }
  minv[0] = 0;
  for (int i = 1; i < N2; ++i) {
    minv[i] = INT_MAX;
  }
  for (int i = 0; i <= n; ++i) {
    if (!ok[i]) continue;
    vector<int> vc;
    for (int j = 0; j < N2; ++j) {
      if (minv[j] < a[i]) vc.push_back(j ^ a[i]);
    }
    for (int j : vc) {
      minv[j] = min(minv[j], a[i]);
    }
  }
  vector<int> ans;
  for (int i = 0; i < N2; ++i) {
    if (minv[i] != INT_MAX) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i : ans) {
    printf("%d ", i);
  }
  printf("\n");
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
