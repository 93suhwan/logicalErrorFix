#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1e9 + 7, mod2 = 998244353;
long long seed1 = 200001, seed2 = 233333;
map<pair<long long, long long>, bool> M;
long long a[15], DF[15];
long long ans = 0, AN[15];
long long S1[15], S2[15];
int n;
vector<long long> V[15];
void dfs(int i, long long s1, long long s2, long long now) {
  if (now + a[i] <= ans) return;
  if (i > n) {
    if (M.count(make_pair(s1, s2))) return;
    ans = now;
    for (int i = 1; i <= n; i++) AN[i] = DF[i];
    return;
  }
  for (int j = V[i].size() - 1; j >= 0; j--)
    if (V[i][j] + now + a[i + 1] <= ans)
      break;
    else {
      DF[i] = j + 1;
      dfs(i + 1, (s1 + (j + 1) * S1[i]) % mod1, (s2 + (j + 1) * S2[i]) % mod2,
          now + V[i][j]);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int al;
    scanf("%d", &al);
    while (al--) {
      long long x;
      scanf("%lld", &x);
      V[i].push_back(x);
      a[i] = x;
    }
  }
  for (int i = n; i >= 1; i--) a[i] = a[i + 1] + a[i];
  int m;
  scanf("%d", &m);
  while (m--) {
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
      long long k;
      scanf("%lld", &k);
      s1 = (s1 * seed1 + k) % mod1;
      s2 = (s2 * seed2 + k) % mod2;
    }
    M[make_pair(s1, s2)] = 1;
  }
  S1[n] = 1;
  S2[n] = 1;
  for (int i = n - 1; i > 0; i--) {
    S1[i] = (S1[i + 1] * seed1) % mod1;
    S2[i] = S2[i + 1] * seed2 % mod2;
  }
  dfs(1, 0ll, 0ll, 0ll);
  for (int i = 1; i <= n; i++) printf("%lld ", AN[i]);
}
