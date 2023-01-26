#include <bits/stdc++.h>
using namespace std;
int T, n;
void solve() {
  scanf("%d", &n);
  int sum = 0, in;
  for (int i = 0; i < n; i++) scanf("%d", &in);
  sum += in;
  (sum / n) * n == sum ? cout << 1 : cout << 0;
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
