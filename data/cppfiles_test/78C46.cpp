#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1e4;
const int M = 31;
int a[N], n, num[M];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int T;
  scanf("%d", &T);
  for (; T; T--) {
    scanf("%d", &n);
    int ans = 0;
    memset(num, 0, sizeof(num));
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]) flag = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < M; ++j)
        if ((a[i] >> j) & 1) num[j]++;
    }
    for (int i = 0; i < M; ++i) ans = gcd(ans, num[i]);
    for (int i = 1; i <= n; ++i)
      if (ans % i == 0) printf("%d ", i);
    puts("");
  }
}
