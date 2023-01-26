#include <bits/stdc++.h>
using namespace std;
long long n, m, Nxt[1000005];
long long ans[1000005], Ans;
const long long mod = 1000000007;
struct node {
  long long ID;
  long long St, Ed;
  long long dp;
  bool flag;
} f[1000005];
bool cmp(node x, node y) { return x.Ed < y.Ed; }
long long Tr[1000005];
long long lowbit(long long x) { return x & (-x); }
void Add(long long x, long long val) {
  while (x <= 2 * n) {
    Tr[x] = (Tr[x] + val) % mod;
    x += lowbit(x);
  }
}
long long Query(long long x) {
  long long ans = 0;
  while (x) {
    ans = (ans + Tr[x]) % mod;
    x -= lowbit(x);
  }
  return ans;
}
signed main() {
  scanf("%d", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%d%d", &f[i].St, &f[i].Ed);
    f[i].ID = i;
  }
  scanf("%d", &m);
  for (long long i = 1; i <= m; i++) {
    long long x;
    scanf("%d", &x);
    f[x].flag = true;
  }
  sort(f + 1, f + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    f[i].dp = (1 + Query(f[i].Ed) - Query(f[i].St) + mod) % mod;
    Add(f[i].St, f[i].dp);
  }
  for (long long i = 1; i <= 2 * n; i++) Tr[i] = 0;
  long long Now = n + 1;
  for (long long i = n; i >= 1; i--) {
    if (f[i].flag) {
      Nxt[i] = Now;
      Now = i;
    }
  }
  long long End = 0;
  for (long long i = 1; i <= n; i++) {
    if (f[i].flag) {
      ans[i] = (1 + Query(f[i].Ed) - Query(f[Nxt[i]].St) + mod) % mod;
      if (f[Nxt[i]].St > f[i].St) End = i;
    }
    Add(f[i].St, f[i].dp);
  }
  for (long long i = End + 1; i <= n; i++) {
    if (f[i].flag) Ans = (Ans + ans[i]) % mod;
  }
  printf("%lld\n", Ans);
}
