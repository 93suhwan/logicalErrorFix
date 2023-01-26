#include <bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 7;
void solve() {
  int n;
  scanf("%d", &n);
  int x = n / 3, y = x;
  if (n % 3 == 1) x++;
  if (n % 3 == 2) y++;
  printf("%d %d\n", x, y);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
