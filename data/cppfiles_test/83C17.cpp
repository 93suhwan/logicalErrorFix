#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxl = 12 + 5;
char n[maxl];
int l;
const long long mod1 = 998244353, mod2 = 1e9 + 7;
long long pw[maxl], p2[maxl];
vector<long long> vec;
void dfs1(int u, long long res, int v, int l2, bool tp) {
  if (u > v) {
    vec.push_back(res);
    return;
  }
  for (int i = 0; i < 10; i++)
    dfs1(u + 1,
         (res + (p2[l - u - tp] - pw[l2 - u] + mod1) % mod1 * i % mod1) % mod1,
         v, l2, tp);
}
long long s, ans = 0;
void dfs2(int u, long long res, int l2, bool tp) {
  if (u > l2) {
    ans = (ans + res * vec.size() % mod2 + s -
           mod1 *
               (upper_bound(vec.begin(), vec.end(), mod1 - res,
                            greater<long long>()) -
                vec.begin()) %
               mod2 +
           mod2) %
          mod2;
    return;
  }
  for (int i = 0; i < 10; i++)
    dfs2(u + 1,
         (res + (p2[l - u - tp] - pw[l2 - u] + mod1) % mod1 * i % mod1) % mod1,
         l2, tp);
}
int main() {
  scanf("%s", n + 1);
  l = strlen(n + 1);
  if (l == 1) {
    printf("0\n");
    return 0;
  }
  pw[0] = 1;
  for (int i = 1; i <= l; i++) pw[i] = pw[i - 1] * 10 % mod1;
  p2[0] = 1;
  for (int i = 1; i <= l; i++) p2[i] = (p2[i - 1] * 10 % mod1 + 1) % mod1;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= i; j++)
      for (int k = j > 1 ? 0 : 1; k < (i < l ? 10 : n[j] - '0'); k++) {
        if (k == n[j] - '0') continue;
        bool tp = k > n[j] - '0';
        long long res = i + tp;
        if (j > 1) {
          res = (res + p2[l - 1 - tp] * (n[1] - '0' - 1) % mod1 -
                 pw[i - 1] * (n[1] - '0') % mod1 + mod1) %
                mod1;
          for (int x = 2; x < j; x++)
            res = (res + (p2[l - x - tp] - pw[i - x] + mod1) % mod1 *
                             (n[x] - '0') % mod1) %
                  mod1;
          res = (res + (p2[l - j - tp] - pw[i - j] + mod1) % mod1 * k % mod1) %
                mod1;
        } else
          res = (res + p2[l - 1 - tp] * (k - 1) % mod1 - pw[i - 1] * k % mod1 +
                 mod1) %
                mod1;
        if (tp)
          for (int x = 1; x <= l; x++)
            res = (res + (n[x] - '0' - (x == 1)) * pw[l - x] % mod1) % mod1;
        int mid = (i + j + 1) / 2;
        vec = {};
        dfs1(j + 1, 0, mid, i, tp);
        s = 0;
        for (long long i : vec) s = (s + i) % mod2;
        sort(vec.begin(), vec.end(), greater<long long>());
        dfs2(mid + 1, res, i, tp);
      }
    long long res = i;
    res = (res + p2[l - 1] * (n[1] - '0' - 1) % mod1 -
           pw[i - 1] * (n[1] - '0') % mod1 + mod1) %
          mod1;
    for (int j = 2; j <= i; j++)
      res =
          (res + (p2[l - j] - pw[i - j] + mod1) % mod1 * (n[j] - '0') % mod1) %
          mod1;
    ans = (ans + res) % mod2;
  }
  printf("%lld\n", ans);
  return 0;
}
