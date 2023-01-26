#include <bits/stdc++.h>
using namespace std;
long long n, a, b, T, dis;
bool opa, opb;
char x[20], y[20];
int main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld%lld%s%s", &n, &a, &b, x + 1, y + 1);
    opa = (x[1] == 'r');
    opb = (y[1] == 'l');
    if (!a) opa = 0;
    if (a == n - 1) opa = 1;
    if (!b) opb = 0;
    if (b == n - 1) opb = 1;
    if (a == b && opa == opb)
      printf("%lld", (!opa) * (n - 1));
    else
      printf("%lld", (!(((a - b) % 2 + 2) % 2)) * (n - 1));
  }
  return 0;
}
