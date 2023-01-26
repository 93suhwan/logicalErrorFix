#include <bits/stdc++.h>
using namespace std;
int T, n, a = 0, b = 1;
void solve() {
  scanf("%d", &n);
  int div, sum, in;
  for (int i = 0; i < n; i++) scanf("%d", &in);
  sum += in;
  div = sum / n;
  div* n == sum ? cout << 0 : cout << 1;
  cout << "\n";
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
