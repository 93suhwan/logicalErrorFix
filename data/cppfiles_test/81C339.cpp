#include <bits/stdc++.h>
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(long long &x) { scanf("%lld", &x); }
void sc(long long &x, long long &y) { scanf("%lld%lld", &x, &y); }
void sc(long long &x, long long &y, long long &z) {
  scanf("%lld%lld%lld", &x, &y, &z);
}
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(long long x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(long long x, long long y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(long long x, long long y, long long z) {
  printf("%lld %lld %lld\n", x, y, z);
}
void ast(long long x, long long l, long long r) { assert(x >= l && x <= r); }
using namespace std;
const int N = 3e5 + 5, mod = 1e9 + 7;
int n, q, a[N];
char s[N];
void sol(int cas) {
  sc(n, q);
  sc(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] == '+' ? 1 : -1;
  for (int i = 2; i <= n; i += 2) a[i] = -a[i];
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  while (q--) {
    int l, r;
    sc(l, r);
    if (a[r] == a[l - 1])
      out(0);
    else if ((r - l) & 1)
      out(2);
    else
      out(1);
  }
}
int main() {
  srand(time(0));
  int t = 1, cas = 0;
  scanf("%d", &t);
  while (t--) {
    sol(++cas);
  }
}
