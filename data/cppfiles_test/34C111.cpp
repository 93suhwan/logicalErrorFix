#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char ch, t = 0;
  while (!isdigit(ch = getchar())) t |= ch == '-';
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x = t ? -x : x;
}
inline long long maxll(long long x, long long y) { return x > y ? x : y; }
inline long long minll(long long x, long long y) { return x < y ? x : y; }
inline long long absll(long long x) { return x > 0ll ? x : -x; }
inline long long gcd(long long x, long long y) {
  return (y == 0) ? x : gcd(y, x % y);
}
int n, All = 8191;
int a[1000005];
bitset<8200> ans[8200], vis[8200];
vector<int> pre[1000005];
int main() {
  n = rd();
  for (int i = 0; i <= All; i++) pre[i].push_back(0);
  for (int i = 1; i <= n; i++) {
    a[i] = rd();
    if (!vis[a[i]][a[i]]) pre[a[i]].push_back(a[i]), vis[a[i]][a[i]] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j : pre[a[i]]) {
      ans[a[i]][j] = true;
      for (int k = a[i] + 1; k <= 5000; k++) {
        if (vis[k][k ^ j]) break;
        vis[k][k ^ j] = true, pre[k].push_back(k ^ j);
      }
    }
    pre[a[i]].clear();
  }
  for (int i = 1; i <= 5000; i++) ans[0] |= ans[i];
  printf("%lld\n", ans[0].count());
  for (int i = 0; i <= All; i++)
    if (ans[0][i]) printf("%d ", i);
  printf("\n");
  return 0;
}
