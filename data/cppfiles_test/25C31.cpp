#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int x = 0;
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
const int maxn = 5e4 + 5;
const int mod = 998244353, g = 3, invg = 332748118;
int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b % 2 == 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b /= 2;
  }
  return ans;
}
int rev[maxn * 6];
int w[maxn * 6], w2[maxn * 6], invn;
void init(int n) {
  for (int i = 1; i < n; i++)
    rev[i] = rev[i >> 1] >> 1 | ((i & 1) ? n >> 1 : 0);
  for (int i = 1; i < n; i *= 2) {
    w[i] = 1;
    int wn = ksm(g, (mod - 1) / (i * 2));
    for (int j = 1; j < i; j++) w[i + j] = 1ll * w[i + j - 1] * wn % mod;
  }
  for (int i = 1; i < n; i *= 2) {
    w2[i] = 1;
    int wn = ksm(invg, (mod - 1) / (i * 2));
    for (int j = 1; j < i; j++) w2[i + j] = 1ll * w2[i + j - 1] * wn % mod;
  }
  invn = ksm(n, mod - 2);
}
vector<int> FFT(vector<int> F, bool flag) {
  int n = F.size();
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(F[i], F[rev[i]]);
  for (int i = 1; i < n; i *= 2)
    for (int j = 0; j < n; j += i * 2)
      for (int k = j; k < j + i; k++) {
        int t = 1ll * F[k + i] * (flag ? w[i + k - j] : w2[i + k - j]) % mod;
        F[k + i] = (F[k] - t + mod) % mod;
        F[k] = (F[k] + t) % mod;
      }
  if (!flag)
    for (int i = 0; i < n; i++) F[i] = 1ll * F[i] * invn % mod;
  return F;
}
vector<int> Inv(vector<int> F) {
  int n = F.size();
  if (n == 1) return {ksm(F[0], mod - 2)};
  vector<int> G = Inv(vector<int>(F.begin(), F.begin() + (n + 1) / 2));
  int len = 1;
  while (len < n * 2 - 1) len *= 2;
  F.resize(len);
  G.resize(len);
  init(len);
  F = FFT(F, 1);
  G = FFT(G, 1);
  for (int i = 0; i < len; i++)
    F[i] = (2 - 1ll * F[i] * G[i] % mod + mod) % mod * G[i] % mod;
  F = FFT(F, 0);
  F.resize(n);
  return F;
}
int n, m;
int ans = 0;
vector<int> solve(int m) {
  if (!m) {
    vector<int> F(n + 1);
    F[0] = 1;
    return F;
  }
  vector<int> F = solve(m / 2), G(n + 1);
  for (int i = 0; i <= n; i += 2) {
    G[i] = F[i];
    F[i] = 0;
  }
  F[1] = (m + 1) / 2;
  vector<int> H(n + 1);
  H[0] = 1;
  for (int i = 1; i <= n; i++) H[i] = (mod - F[i]) % mod;
  H = Inv(H);
  ans = n % 2 == 0 ? (1ll * ans * 2 % mod + H[n]) % mod : H[n];
  for (int i = 1; i <= n; i += 2)
    ans = (ans + 1ll * F[i] * H[n - i] % mod * (i - 1) % mod) % mod;
  int len = 1;
  while (len < n * 3 + 1) len *= 2;
  G.resize(len);
  H.resize(len);
  init(len);
  G = FFT(G, 1);
  H = FFT(H, 1);
  for (int i = 0; i < len; i++) G[i] = 1ll * G[i] * G[i] % mod * H[i] % mod;
  G = FFT(G, 0);
  for (int i = 0; i <= n; i++) F[i] = (F[i] + G[i]) % mod;
  return F;
}
int main() {
  n = readint();
  m = readint();
  solve(m);
  printf("%d\n", ans);
  return 0;
}
