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
    printf("%lld", (!((opa != opb) != ((a - b) % 2 + 2) % 2)) * (n - 1));
  }
  return 0;
}
