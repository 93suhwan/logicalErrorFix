#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
void solve() {
  int x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  while (x1 && x1 % 10 == 0) p1++, x1 /= 10;
  while (x2 && x2 % 10 == 0) p2++, x2 /= 10;
  if (p1 == p2) {
    if (x1 > x2) {
      puts(">");
    } else if (x1 < x2) {
      puts("<");
    } else
      puts("=");
  } else if (p1 > p2) {
    puts(">");
  } else
    puts("<");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
