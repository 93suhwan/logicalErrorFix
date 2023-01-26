#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 1;
int n, m;
int a[MAXN], b[MAXN], cnt[MAXN], pos[MAXN], c[MAXN];
int solve2() {
  for (int i = 1; i <= n; ++i) {
    a[i] = c[i];
    pos[a[i]] = i;
  }
  int ANS = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      ANS++;
      int x, y;
      x = i;
      y = pos[b[i]];
      swap(pos[a[x]], pos[a[y]]);
      swap(a[x], a[y]);
    }
  }
  return ANS;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[i] = a[i];
  for (int i = 0; i <= n - 1; ++i) cnt[i] = 0;
  for (int i = 1; i <= n; ++i) {
    cnt[(i + n - a[i]) % n]++;
  }
  vector<int> ans;
  for (int i = 0; i <= n - 1; ++i) {
    if (cnt[i] * 3 >= n) {
      for (int j = 1; j <= n; ++j) {
        b[(j + i - 1 + n) % n + 1] = j;
      }
      if (solve2() <= m) {
        ans.push_back(i);
      }
    }
  }
  printf("%d ", int(ans.size()));
  for (auto it : ans) printf("%d ", it);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
