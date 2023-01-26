#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long MAXN = 500005;
const long long INF = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7;
struct Node {
  long long u, id, dep;
} a[MAXN];
long long n, k, f[MAXN][10], sum[MAXN], cnt, g[MAXN][10], num[MAXN];
vector<long long> Can[10];
map<string, long long> MMap;
map<long long, long long> Map, Color;
string S;
bool cmp(Node &a, Node &b) { return a.id > b.id; }
void Init(long long n) {
  for (long long i = 1; i <= 6; i++) f[1][i] = 1;
  sum[1] = 6;
  for (long long i = 2; i <= n; i++) {
    long long cur1 = (sum[i - 1] - f[i - 1][1] - f[i - 1][2] + 2 * MOD) % MOD;
    long long cur2 = (sum[i - 1] - f[i - 1][3] - f[i - 1][4] + 2 * MOD) % MOD;
    long long cur3 = (sum[i - 1] - f[i - 1][5] - f[i - 1][6] + 2 * MOD) % MOD;
    f[i][1] = f[i][2] = cur1 * cur1 % MOD;
    f[i][3] = f[i][4] = cur2 * cur2 % MOD;
    f[i][5] = f[i][6] = cur3 * cur3 % MOD;
    for (long long j = 1; j <= 6; j++) sum[i] = (sum[i] + f[i][j]) % MOD;
  }
}
long long Dep(long long x) {
  if (x == 0) return 0;
  long long cur = 0;
  while (x > 0) {
    cur++;
    x >>= 1;
  }
  return cur;
}
bool Judge(long long x, long long y) {
  if (x == 0 || y == 0) return true;
  if ((x == 1 || x == 2) && (y == 1 || y == 2)) return false;
  if ((x == 3 || x == 4) && (y == 3 || y == 4)) return false;
  if ((x == 5 || x == 6) && (y == 5 || y == 6)) return false;
  return true;
}
void Solve(long long u, long long dep) {
  long long ls = 0, rs = 0;
  if (!Map[u]) {
    Map[u] = ++cnt;
    num[cnt] = u;
    for (long long i = 1; i <= 6; i++) g[cnt][i] = f[k - dep + 1][i];
    return;
  }
  if (dep == k) {
    if (Color[u])
      g[Map[u]][Color[u]] = 1;
    else
      for (long long i = 1; i <= 6; i++) g[Map[u]][i] = 1;
    return;
  }
  Solve(u << 1, dep + 1);
  Solve(u << 1 | 1, dep + 1);
  if (!Color[u]) {
    for (long long i = 1; i <= 6; i++) {
      for (auto j : Can[i]) {
        for (auto k : Can[i]) {
          g[Map[u]][i] =
              (g[Map[u]][i] + g[Map[u << 1]][j] * g[Map[u << 1 | 1]][k] % MOD) %
              MOD;
        }
      }
    }
  } else {
    for (long long i = Color[u]; i <= Color[u]; i++) {
      for (auto j : Can[i]) {
        for (auto k : Can[i]) {
          g[Map[u]][i] =
              (g[Map[u]][i] + g[Map[u << 1]][j] * g[Map[u << 1 | 1]][k] % MOD) %
              MOD;
        }
      }
    }
  }
  return;
}
signed main() {
  scanf("%lld%lld", &k, &n);
  Init(k);
  MMap["white"] = 1;
  MMap["yellow"] = 2;
  MMap["green"] = 3;
  MMap["blue"] = 4;
  MMap["red"] = 5;
  MMap["orange"] = 6;
  Can[1] = Can[2] = {3, 4, 5, 6};
  Can[3] = Can[4] = {1, 2, 5, 6};
  Can[5] = Can[6] = {1, 2, 3, 4};
  for (long long i = 1; i <= n; i++) {
    long long u, id;
    scanf("%lld", &a[i].u);
    cin >> S;
    a[i].id = MMap[S];
    Color[a[i].u] = a[i].id;
    long long cur = a[i].u;
    while (cur) {
      Map[cur] = 1;
      cur >>= 1;
    }
  }
  cnt = 0;
  for (auto i : Map) Map[i.first] = ++cnt, num[cnt] = i.first;
  Solve(1, 1);
  long long ans = 0;
  for (long long i = 1; i <= 6; i++) ans = (ans + g[1][i]) % MOD;
  printf("%lld", ans);
  return 0;
}
