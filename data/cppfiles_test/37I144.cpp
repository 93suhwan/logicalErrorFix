#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 2e5 + 3;
long long ksm(long long a, int p) {
  long long res = 1LL;
  while (p) {
    if (p & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    p >>= 1;
  }
  return res;
}
vector<int> v[N];
bool f[N];
int cur, yes;
void dfs(int x, int fa) {
  int k = 0;
  f[x] = 0;
  for (auto i : v[x]) {
    if (i == fa) continue;
    dfs(i, x);
    k += f[i];
  }
  k %= cur;
  if (!k) {
    f[x] = 1;
    return;
  }
  if (k != (cur - 1)) {
    yes = 0;
  }
}
int T, n, res[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      v[i].clear();
    }
    int x, y;
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
    }
    memset(res, 0, 4 * n + 3);
    res[1] = ksm(2, n - 1);
    for (int i = 2; i < n; i++) {
      if ((n - 1) % i) continue;
      cur = i;
      yes = 1;
      dfs(1, 0);
      res[i] = yes;
    }
    for (int i = n; i >= 1; i--) {
      for (int j = i + i; j <= n; j += i) {
        res[i] -= res[j];
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%lld ", res[i] % MOD);
    }
    puts("");
  }
}
