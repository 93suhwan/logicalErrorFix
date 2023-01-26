#include <bits/stdc++.h>
using namespace std;
long long a[105];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long tt = a[1];
    for (int i = 1; i <= n; i += 2) {
      tt = gcd(tt, a[i]);
    }
    int flag1 = 1;
    for (int i = 2; i <= n; i += 2) {
      if (a[i] % tt == 0) {
        flag1 = 0;
        break;
      }
    }
    long long ttt = a[2];
    for (int i = 2; i <= n; i += 2) {
      ttt = gcd(ttt, a[i]);
    }
    int flag2 = 1;
    for (int i = 1; i <= n; i += 2) {
      if (a[i] % ttt == 0) {
        flag2 = 0;
        break;
      }
    }
    if (flag1)
      printf("%lld\n", tt);
    else if (flag2)
      printf("%lld\n", ttt);
    else
      puts("0");
  }
  return 0;
}
