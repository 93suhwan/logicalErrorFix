#include <bits/stdc++.h>
using namespace std;
int P;
int ad(int k1, int k2) { return k1 += k2 - P, k1 += k1 >> 31 & P; }
int su(int k1, int k2) { return k1 -= k2, k1 += k1 >> 31 & P; }
int mu(int k1, int k2) { return 1LL * k1 * k2 % P; }
void uad(int& k1, int k2) { k1 += k2 - P, k1 += k1 >> 31 & P; }
void usu(int& k1, int k2) { k1 -= k2, k1 += k1 >> 31 & P; }
template <class... T>
int ad(int k1, T... k2) {
  return ad(k1, ad(k2...));
}
template <class... T>
int su(int k1, T... k2) {
  return su(k1, ad(k2...));
}
template <class... T>
int mu(int k1, T... k2) {
  return mu(k1, mu(k2...));
}
template <class... T>
void uad(int& k1, T... k2) {
  return uad(k1, ad(k2...));
}
template <class... T>
void usu(int& k1, T... k2) {
  return usu(k1, ad(k2...));
}
int po(int k1, int k2) {
  int k3 = 1;
  for (; k2; k2 >>= 1, k1 = mu(k1, k1))
    if (k2 & 1) k3 = mu(k3, k1);
  return k3;
}
const int N = 205;
int n, fac[N], inv[N], ifac[N];
int main() {
  scanf("%d%d", &n, &P);
  fac[0] = fac[1] = inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
  for (int i = (2); i <= (N - 1); ++i)
    fac[i] = mu(fac[i - 1], i), inv[i] = mu(P - P / i, inv[P % i]),
    ifac[i] = mu(ifac[i - 1], inv[i]);
  int res = 0;
  for (int mn = (n + 1); mn >= (1); --mn) {
    vector<vector<int> > dp(mn + 1, vector<int>(mn + 1, 0));
    for (int tot = (1); tot <= (mn); ++tot) {
      dp[tot][mn * tot - mn * tot] = ifac[tot];
    }
    for (int i = (mn); i <= (n); ++i) {
      vector<vector<int> > ndp(i + 2, vector<int>(mn + 1, 0));
      for (int tot = (1); tot <= (i); ++tot) {
        for (int sum = (mn * tot); sum <= (mn * min(tot + 1, i)); ++sum)
          if (dp[tot][sum - mn * tot]) {
            for (int delta = 0;
                 delta <= i + 1 - tot &&
                 delta <= (mn * (i + 1) - sum) / (i + 1) &&
                 sum + delta * (i + 1) <= mn * min(tot + delta + 1, i + 1);
                 ++delta) {
              uad(ndp[tot + delta][sum + delta * (i + 1) - mn * (tot + delta)],
                  mu(dp[tot][sum - mn * tot], ifac[delta]));
            }
          }
      }
      dp = ndp;
    }
    int old = res;
    for (int i = (0); i <= (((int)(dp[n]).size()) - 1); ++i) {
      uad(res, dp[n][i]);
    }
    ((void)0);
    if (res == old) break;
  }
  printf("%d\n", mu(fac[n], res));
  return 0;
}
