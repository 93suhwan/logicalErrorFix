#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
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
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    int n, K, x;
    scanf("%d%d%d", &n, &K, &x);
    if (x == 0) {
      int ans = 1;
      int pw = 1, cur = po(2, K);
      for (int i = (0); i <= (n - 1); ++i) {
        ans = mu(ans, su(cur, pw));
        pw = mu(pw, 2);
        if (ans == 0) break;
      }
      printf("%d\n", ans);
    } else {
      const int inv2 = (P + 1) >> 1;
      vector<int> q_dw(K + 1), q_ifac(K + 1);
      {
        int cur = po(2, n);
        q_dw[0] = 1;
        for (int i = (1); i <= (K); ++i) {
          q_dw[i] = mu(q_dw[i - 1], su(1, cur));
          cur = mu(cur, inv2);
        }
      }
      {
        q_ifac[0] = 1;
        int pw = 1;
        for (int i = (1); i <= (K); ++i) {
          pw = ad(pw, pw);
          q_ifac[i] = mu(q_ifac[i - 1], su(1, pw));
        }
        q_ifac[K] = po(q_ifac[K], P - 2);
        for (int i = (K); i >= (1); --i) {
          q_ifac[i - 1] = mu(q_ifac[i], su(1, pw));
          pw = mu(pw, inv2);
        }
      }
      int ans = 0, pw = 1;
      auto q_binom = [&](int m, int r) { return mu(q_dw[r], q_ifac[r]); };
      const int powK = po(2, K);
      int w1 = 1;
      for (int i = 0; i <= K && i <= n; ++i) {
        int res = 0;
        if (i == 0)
          res = 1;
        else {
          w1 = mu(w1, su(powK, pw));
          uad(res, mu(w1, q_binom(n, i)));
          pw = ad(pw, pw);
        }
        uad(ans, mu(res, pw - 1));
      }
      ans = mu(ans, po(powK - 1, P - 2));
      ans = su(po(2, 1LL * n * K % (P - 1)), ans);
      printf("%d\n", ans);
    }
  }
  return 0;
}
