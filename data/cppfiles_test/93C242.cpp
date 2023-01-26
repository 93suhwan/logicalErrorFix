#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int oo = 1e9 + 10;
const int mod = 1000000007;
const int N = 1e5 + 5;
int CntXor(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  int xo = CntXor(a - 1);
  int need = b ^ xo;
  if (xo == b)
    printf("%d\n", a);
  else if (need != a)
    printf("%d\n", a + 1);
  else
    printf("%d\n", a + 2);
}
int t = 1;
int main() {
  scanf("%d", &t);
  while (t--) solve();
}
