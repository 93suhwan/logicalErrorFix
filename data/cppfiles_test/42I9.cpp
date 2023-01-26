#include <bits/stdc++.h>
using namespace std;
int n, m, a[400005], Nxt[200005];
long long Time[400005], ans[200005], Ans;
const long long mod = 1000000007;
struct node {
  int ID;
  int St, Ed;
  long long dp;
  bool flag;
} f[200005];
bool cmp(node x, node y) { return x.Ed < y.Ed; }
long long Tr[400005];
int lowbit(int x) { return x & (-x); }
void Add(int x, long long val) {
  while (x <= 2 * n) {
    Tr[x] = (Tr[x] + val) % mod;
    x += lowbit(x);
  }
}
long long Query(int x) {
  long long ans = 0;
  while (x) {
    ans = (ans + Tr[x]) % mod;
    x -= lowbit(x);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &f[i].St, &f[i].Ed);
    f[i].ID = i;
    a[f[i].St] = i;
    a[f[i].Ed] = -i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    f[x].flag = true;
  }
  sort(f + 1, f + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    f[i].dp = (1 + Query(f[i].Ed) - Query(f[i].St) + mod) % mod;
    Add(f[i].St, f[i].dp);
  }
  for (int i = 1; i <= 2 * n; i++) Tr[i] = 0;
  int Now = n + 1;
  for (int i = n; i >= 1; i--) {
    if (f[i].flag) {
      Nxt[i] = Now;
      Now = i;
    }
  }
  int End = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i].flag) {
      ans[i] = (1 + Query(f[i].Ed) - Query(f[Nxt[i]].St) + mod) % mod;
      if (f[Nxt[i]].St > f[i].St) End = i;
    }
    Add(f[i].St, f[i].dp);
  }
  for (int i = End + 1; i <= n; i++) {
    if (f[i].flag) Ans = (Ans + ans[i]) % mod;
  }
  printf("%lld\n", Ans);
}
