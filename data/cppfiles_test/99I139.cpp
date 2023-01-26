#include <bits/stdc++.h>
using namespace std;
int execute_tests(bool);
void solve() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int x0;
    scanf("%lld", &x0);
    long long int n;
    scanf("%lld", &n);
    if (x0 % 2 == 0) {
      if (n % 4 == 0) {
        printf("%lld", n + x0);
        ;
        putchar('\n');
      } else if (n % 4 == 1) {
        printf("%lld", -n + x0);
        ;
        putchar('\n');
      } else if (n % 4 == 2) {
        printf("%lld", 1 + x0);
        ;
        putchar('\n');
      } else {
        printf("%lld", n + 1 + x0);
        ;
        putchar('\n');
      }
    } else {
      if (n % 4 == 0) {
        printf("%lld", x0);
        ;
        putchar('\n');
      } else if (n % 4 == 1) {
        printf("%lld", n + x0);
        ;
        putchar('\n');
      } else if (n % 4 == 2) {
        printf("%lld", x0 - 1);
        ;
        putchar('\n');
      } else {
        printf("%lld", -n + x0 - 1);
        ;
        putchar('\n');
      }
    }
  }
}
int main() {
  solve();
  return execute_tests(false);
}
int execute_tests(bool run) { return 0; }
