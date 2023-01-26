#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, maxn = 200030;
int aabs(int x) {
  if (x < 0) return -x;
  return x;
}
long long pow(long long x, long long a) {
  long long now = 1;
  while (a) {
    if (a % 2) now = now * x % mod;
    x = x * x % mod;
    a >>= 1;
  }
  return now;
}
int t;
char s[200];
int main() {
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0;
    if (s[0] != '0') ans += (s[0] - '0');
    for (int i = 1; i < n; i++)
      if (s[i] != '0') ans += (s[i] - '0' + 1);
    printf("%d\n", ans);
  }
  return 0;
}
