#include <bits/stdc++.h>
using namespace std;
int pow_mod(int a, long long k, int mod) {
  if (k == 0) {
    return 1;
  }
  int sub = pow_mod(a, k / 2, mod);
  if (k % 2 == 0) {
    return ((long long)sub * sub) % mod;
  } else {
    return (((long long)sub * sub) % mod * a) % mod;
  }
}
int main() {
  int h, i, j, l;
  int t, n, m, k, q;
  int r, c;
  scanf("%d %d %d %d %d", &n, &m, &k, &r, &c);
  int ax, ay, bx, by;
  scanf("%d %d %d %d", &ax, &ay, &bx, &by);
  long long count;
  long long mod = 1e9 + 7;
  if (ax == bx && ay == by) {
    count = n * m;
  } else {
    count = n * m - r * c;
  }
  printf("%d\n", pow_mod(k, count, mod));
}
