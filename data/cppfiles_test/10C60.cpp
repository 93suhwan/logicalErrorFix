#include <bits/stdc++.h>
using namespace std;
long long int poww(long long int base, long long int poow) {
  long long int ans = 1;
  long long int tem = base;
  while (poow > 0) {
    if (poow % 2) ans = (ans * tem) % 1000000007;
    tem = (tem * tem) % 1000000007;
    poow /= 2;
  }
  return ans;
}
int main() {
  long long int a, b, c, t, n, m, k, r, ax, bx, ay, by;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  scanf("%lld", &r);
  scanf("%lld", &c);
  scanf("%lld", &ax);
  scanf("%lld", &ay);
  scanf("%lld", &bx);
  scanf("%lld", &by);
  if (ax == bx && ay == by) {
    a = m * n;
  } else {
    a = m * n - (r * c);
  }
  long long int mm = poww(k, a);
  printf("%lld\n", mm);
  return 0;
}
