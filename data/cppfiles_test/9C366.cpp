#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int gcd(int n, int m) { return n == 0 ? m : gcd(m % n, n); }
int lcm(int n, int m) { return n * m / gcd(n, m); }
int a[30];
int main() {
  int t;
  char c;
  scanf("%d", &t);
  scanf("%c", &c);
  while (t--) {
    memset(a, 0, sizeof(a));
    int ans = 0;
    while (scanf("%c", &c)) {
      if (c == '\n') break;
      if (++a[c - 'a'] < 3) ans++;
    }
    printf("%d\n", ans / 2);
  }
  return 0;
}
