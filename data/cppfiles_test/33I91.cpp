#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], ans[N], f[700][700];
int lowbit(int x) { return x & (-x); }
int n, c[710][710];
int query(int u, int v) {
  int ans = 0;
  while (u > 0) {
    ans += c[v][u];
    u -= lowbit(u);
  }
  return ans;
}
void add(int u, int v) {
  while (u <= 625) {
    c[v][u]++;
    u += lowbit(u);
  }
}
int main() {
  add(1, 0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= a[i]; j++) {
      if (query(a[i], j) > 0) add(a[i] + 1, a[i] ^ j);
    }
    add(a[i] + 1, a[i]);
  }
  vector<int> ans;
  for (int i = 0; i <= 625; i++)
    if (query(626, i) > 0) ans.push_back(i);
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d ", x);
  puts("");
  return 0;
}
