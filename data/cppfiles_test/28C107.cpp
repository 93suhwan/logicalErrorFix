#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 998244353;
using namespace std;
bool ok(vector<int> a, int k, int n, int m) {
  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = (i - k + n) % n;
  vector<int> vis(n, 0), b(n);
  for (int i = 0; i < n; ++i) b[p[i]] = a[i];
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (vis[b[i]] == 0) {
      int x = b[i];
      while (vis[x] == 0) {
        vis[x] = 1;
        x = b[x];
      }
      cnt++;
    }
  return n - cnt <= m;
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[i]--;
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; ++i) {
    cnt[(i - a[i] + n) % n]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i)
    if (cnt[i] + 2 * m >= n && ok(a, i, n, m)) ans.push_back(i);
  int sz = ans.size();
  printf("%d", sz);
  for (auto e : ans) printf(" %d", e);
  puts("");
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
