#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n;
int a[N];
int cnt[N], maxw, maxans;
int v[N], factor;
void divide(int x) {
  int w = 0;
  while (x) {
    w++;
    cnt[w] += x % 2;
    x >>= 1;
  }
  maxw = max(maxw, w);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void divide2(int x) {
  for (int i = 1; i <= x; i++)
    if (x % i == 0) {
      factor++;
      v[factor] = i;
    }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    maxw = maxans = factor = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(v, 0, sizeof(v));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      divide(a[i]);
    }
    for (int i = 0; i <= maxw; i++) maxans = max(maxans, cnt[i]);
    for (int i = 0; i <= maxw; i++)
      if (cnt[i] != 0) maxans = gcd(maxans, cnt[i]);
    if (maxans == 0) {
      for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i != n) printf(" ");
      }
      puts("");
      continue;
    }
    divide2(maxans);
    for (int i = 1; i <= factor; i++) {
      printf("%d", v[i]);
      if (i != factor) printf(" ");
    }
    puts("");
  }
  return 0;
}
