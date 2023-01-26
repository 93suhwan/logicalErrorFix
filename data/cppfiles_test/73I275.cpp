#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1005];
void solve() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int maxn = 0;
    for (int i = 1; i <= n; ++i) {
      maxn = max(maxn, abs(a[i] - i));
    }
    if (maxn == 0)
      printf("0\n");
    else
      printf("%d\n", maxn + 1);
  }
}
int main() { solve(); }
