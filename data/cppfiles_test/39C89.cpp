#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 2e6 + 6;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e3 + 3;
long long qpow(long long x, long long y) {
  long long ans = 1;
  x %= mod;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int n, k;
int a[maxn];
int ask(vector<int>& c) {
  printf("?");
  for (int i : c) printf(" %d", i);
  puts("");
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    vector<int> c;
    for (int j = 1; j < n; j++) c.push_back(1);
    c.push_back(i);
    k = ask(c);
    if (k == 0) {
      a[n] = n + 2 - i;
      break;
    }
  }
  if (a[n] == 0) a[n] = 1;
  for (int i = 1; i <= n; i++)
    if (i != a[n]) {
      int x, y;
      if (a[n] + n - i >= 1 && a[n] + n - i <= n) {
        x = n;
        y = a[n] + n - i;
      } else {
        x = 1;
        y = a[n] + 1 - i;
      }
      vector<int> c;
      for (int j = 1; j < n; j++) c.push_back(y);
      c.push_back(x);
      int k = ask(c);
      a[k] = i;
    }
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", a[i]);
  puts("");
}
