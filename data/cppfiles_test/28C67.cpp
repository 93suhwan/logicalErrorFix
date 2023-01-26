#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const int N = 100010;
const int M = 1000100;
void solve() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", (a + c) % 2);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
