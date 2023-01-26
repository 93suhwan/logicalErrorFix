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
const int N = 3e5 + 5, mod = 998244353;
int n, a[N];
int sum(int x) { return a[x] + a[x + 1] + a[x + 2]; }
void sol(int cas) {
  sc(n);
  for (int i = 1; i <= n; i++) sc(a[i]);
  vector<int> ans;
  int sm = 0, s = 0;
  for (int i = 1; i <= n; i++) sm += a[i];
  if (sm & 1) {
    printf("NO\n");
    return;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == 1) {
      int j = i;
      while (j + 2 <= n) {
        if (sum(j) == 1) {
          ans.push_back(j);
          a[j + 1] = a[j + 2] = 1;
          j += 2;
        } else if (sum(j) == 2) {
          for (int k = j; k >= i; k--)
            if (sum(k) == 2) {
              ans.push_back(k);
              a[k] = a[k + 1] = a[k + 2] = 0;
            }
          break;
        } else
          j += 2;
      }
    } else if (sum(i) == 2) {
      ans.push_back(i);
      a[i] = a[i + 1] = a[i + 2] = 0;
    }
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      printf("NO\n");
      return;
    }
  printf("YES\n");
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf(i == ans.size() - 1 ? "%d\n" : "%d ", ans[i]);
}
int main() {
  srand(time(0));
  int t = 1, cas = 0;
  scanf("%d", &t);
  while (t--) {
    sol(++cas);
  }
  return 0;
}
