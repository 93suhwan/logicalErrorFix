#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 9;
int a[N], nxt[N], pos[N], vis[N], minv[N];
vector<int> vc[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n; i >= 1; --i) {
    nxt[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  minv[0] = 0;
  for (int i = 1; i < (1 << 13); ++i) {
    minv[i] = 5000;
  }
  vis[0] = true;
  for (int i = 1; i <= 5000; ++i) {
    if (pos[i]) vc[pos[i]].push_back(0);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j : vc[i]) {
      int k = j ^ a[i];
      vis[k] = true;
      if (a[i] < minv[k]) {
        for (int x = a[i] + 1; x <= minv[k]; ++x) {
          if (pos[x]) vc[pos[x]].push_back(k);
        }
        minv[k] = a[i];
      }
    }
    pos[a[i]] = nxt[i];
  }
  vector<int> ans;
  for (int i = 0; i < (1 << 13); ++i) {
    if (vis[i]) ans.push_back(i);
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
