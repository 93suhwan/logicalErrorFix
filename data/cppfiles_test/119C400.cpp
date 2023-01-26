#include <bits/stdc++.h>
using namespace std;
void inputl() {}
template <typename... Arg>
void inputl(long long int& a, Arg&&... args) {
  scanf("%lld", &a);
  inputl(forward<Arg>(args)...);
}
void outputl(long long int a) { printf("%lld ", a); }
template <typename... Arg>
void outputl(long long int a, Arg... args) {
  printf("%lld ", a);
  outputl(args...);
}
void input() {}
template <typename... Arg>
void input(int& a, Arg&&... args) {
  scanf("%d", &a);
  input(forward<Arg>(args)...);
}
void output(int a) { printf("%d ", a); }
template <typename... Arg>
void output(int a, Arg... args) {
  printf("%d ", a);
  output(args...);
}
void solve() {
  int t;
  input(t);
  ;
  while (t--) {
    int n;
    input(n);
    ;
    int a[n];
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    ;
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    output(sum % n == 0 ? 0 : 1);
    ;
    putchar('\n');
  }
}
int main() {
  solve();
  return 0;
}
