#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int vis[N], pr[N], tot, n;
int main() {
  for (int i = 2; i < N; ++i) {
    if (vis[i]) continue;
    pr[++tot] = i;
    for (int j = i * 2; j < N; j += i) vis[j] = 1;
  }
  int T, n;
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      printf("%d", pr[i]);
      if (i != n) putchar(' ');
    }
    puts("");
  }
  return 0;
}
