#include <bits/stdc++.h>
using namespace std;
long long a, b, mod1 = 998244353, mod2 = 1000000007, rk, an, sum[101];
vector<long long> qu[101];
void dfs1(long long qq, long long ww) {
  if (qq > 6) return;
  rk++;
  qu[qq].push_back(((rk - ww) % mod1 + mod1) % mod1);
  sum[qq] += ((rk - ww) % mod1 + mod1) % mod1;
  for (int i = 0; i <= 9; i++) {
    dfs1(qq + 1, ww * 10 + i);
  }
}
long long work(long long qq, long long ww) {
  long long tt =
      lower_bound(qu[qq].begin(), qu[qq].end(), mod1 - ww) - qu[qq].begin();
  return (ww * qu[qq].size() % mod2 + sum[qq] -
          mod1 * (qu[qq].size() - tt) % mod2) %
         mod2;
}
void dfs2(long long qq, long long ww) {
  if (ww > a) return;
  if (qq >= 1) {
    if (ww * 10000000 > a && ww * 1000000 + 999999 <= a) {
      long long tt = 1;
      for (int i = 0; i <= 6; i++) {
        an += work(i, ((rk - ww * tt) % mod1 + mod1) % mod1);
        an %= mod2;
        tt *= 10;
      }
      for (int i = 0; i <= 6; i++) {
        rk += qu[i].size();
      }
      return;
    }
    rk++;
    an += ((rk - ww) % mod1 + mod1) % mod1;
    an %= mod2;
  }
  if (qq == 0)
    for (int i = 1; i <= 9; i++) dfs2(qq + 1, ww * 10 + i);
  else
    for (int i = 0; i <= 9; i++) dfs2(qq + 1, ww * 10 + i);
}
int main() {
  scanf("%lld", &a);
  dfs1(0, 0);
  rk = 0;
  for (int i = 0; i <= 6; i++) sort(qu[i].begin(), qu[i].end());
  dfs2(0, 0);
  an %= mod2;
  an += mod2;
  an %= mod2;
  printf("%lld", an);
  return 0;
}
