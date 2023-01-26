#include <bits/stdc++.h>
using namespace std;
void pri(int x) {
  for (int i = 1; i <= x; i++) putchar('(');
  for (int i = 1; i <= x; i++) putchar(')');
}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    pri(i), pri(n - i);
    puts("");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
