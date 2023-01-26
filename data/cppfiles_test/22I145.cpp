#include <bits/stdc++.h>
using namespace std;
const int N = 41;
int n, k, a[N][N], sz[N];
inline void dfs(int x, unsigned long long s1, unsigned long long s2) {
  if (x > k) {
    if (s1 != ((1ull << n) - 1)) {
      puts("REJECTED");
      exit(0);
    }
    for (int i = 0, bg = 0; i < n; ++i)
      if (s2 & (1ull << i))
        bg = 1;
      else if (bg) {
        puts("REJECTED");
        exit(0);
      }
    return;
  }
  int cur0 = 0, cur1 = 0, ct = 0;
  unsigned long long nxt1 = s1;
  for (int i = 1; i <= sz[x]; ++i) {
    int t = a[x][i];
    nxt1 |= 1ull << t;
    if (s1 & (1ull << t)) {
      if (s2 & (1ull << t))
        cur1++;
      else
        cur0++;
    } else
      ct++;
  }
  unsigned long long nxt2 = s2;
  for (int i = 1; i <= sz[x]; ++i) {
    int t = a[x][i];
    if (i <= cur0)
      nxt2 &= ((1ull << n) - 1) ^ (1ull << t);
    else
      nxt2 |= 1ull << t;
  }
  dfs(x + 1, nxt1, nxt2);
  for (int k = 1; k <= ct; ++k)
    dfs(x + 1, nxt1, nxt2 | (1ull << a[x][k + cur0]));
}
int main() {
  scanf("%d%d", &n, &k);
  if (n == 1) {
    puts("ACCEPTED");
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &sz[i]);
    for (int j = 1; j <= sz[i]; ++j) scanf("%d", &a[i][j]), a[i][j]--;
  }
  dfs(1, 0, 0);
  puts("ACCEPTED");
  return 0;
}
