#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  int ans = n / 10;
  int cur = n % 10;
  if (cur == 9) {
    printf("%d\n", ans + 1);
    return;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  int n;
  while (t--) {
    solve();
  }
}
