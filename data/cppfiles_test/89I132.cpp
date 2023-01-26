#include <bits/stdc++.h>
using namespace std;
int a[101000], prime[101000], vis[101000], cnt;
void Euler_prime(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) {
      prime[cnt++] = i;
      vis[i] = true;
    }
    for (int j = 0; j < cnt; ++j) {
      if (i * prime[j] > n) break;
      vis[i * prime[j]] = true;
      if (!i % prime[j]) break;
    }
  }
}
int main() {
  int t, n;
  Euler_prime(101000 - 10);
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int mark = 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      mark = 0;
      int num = lower_bound(prime, prime + cnt, i + 1) - prime + 1;
      for (int j = 0; j < num && prime[j] <= i + 1; j++) {
        if (prime[j] > i + 1) break;
        if (a[i] % prime[j]) {
          mark = 1;
          break;
        }
      }
      if (!mark) {
        printf("NO\n");
        break;
      }
    }
    if (mark) printf("YES\n");
  }
}
