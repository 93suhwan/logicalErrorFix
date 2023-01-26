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
    if (((long long int)abs(x0)) % 2 == 0) {
      long long int shift = x0;
      if (n % 4 == 0) {
        printf("%lld", n + shift);
        ;
        putchar('\n');
      } else if (n % 4 == 1) {
        printf("%lld", -n + shift);
        ;
        putchar('\n');
      } else if (n % 4 == 2) {
        printf("%lld", 1 + shift);
        ;
        putchar('\n');
      } else {
        printf("%lld", n + 1 + shift);
        ;
        putchar('\n');
      }
    } else {
      long long int shift = x0 - 1;
      if (n % 4 == 0) {
        printf("%lld", 1 + shift);
        ;
        putchar('\n');
      } else if (n % 4 == 1) {
        printf("%lld", n + 1 + shift);
        ;
        putchar('\n');
      } else if (n % 4 == 2) {
        printf("%lld", shift);
        ;
        putchar('\n');
      } else {
        printf("%lld", -n + shift);
        ;
        putchar('\n');
      }
    }
  }
}
int main() {
  printf("%lld", -12 % 2);
  ;
  solve();
  return execute_tests(false);
}
int execute_tests(bool run) { return 0; }
