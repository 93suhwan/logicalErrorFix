#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8e5;
const int MOD = 998244353;
int add(int x) {
  if (x >= MOD) x -= MOD;
  return x;
}
int sub(int x) {
  if (x < 0) x += MOD;
  return x;
}
void Add(int &x, int y) { x = add(x + y); }
void Sub(int &x, int y) { x = sub(x - y); }
int quick_pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % MOD;
    x = 1ll * x * x % MOD;
    y >>= 1;
  }
  return res;
}
int l = 0;
namespace NTT {
const int NTT_MAX = 8e5;
const int G = 3;
int wn_pos[NTT_MAX + 48], wn_neg[NTT_MAX + 48];
bool init = false;
int wn_pos_pw[21][NTT_MAX + 48], wn_neg_pw[21][NTT_MAX + 48];
void poly_init() {
  init = true;
  int cnt = 0;
  for (int clen = 2; clen <= 524288; clen <<= 1) {
    wn_pos[clen] = quick_pow(G, (MOD - 1) / clen),
    wn_neg[clen] = quick_pow(G, (MOD - 1) - (MOD - 1) / clen);
    cnt++;
    wn_pos_pw[cnt][0] = wn_neg_pw[cnt][0] = 1;
    int wa = wn_pos[clen], wb = wn_neg[clen];
    for (int j = 1; j <= 300000; j++) {
      wn_pos_pw[cnt][j] = 1ll * wn_pos_pw[cnt][j - 1] * wa % MOD;
      wn_neg_pw[cnt][j] = 1ll * wn_neg_pw[cnt][j - 1] * wb % MOD;
    }
  }
}
void poly_ntt(int c[], int len, int fl) {
  int clen, i, j, k, tmp1, tmp2;
  for (i = (len >> 1), j = 1; j < len; j++) {
    if (i < j) swap(c[i], c[j]);
    for (k = (len >> 1); i & k; k >>= 1) i ^= k;
    i ^= k;
  }
  int cnt = 0;
  for (clen = 2; clen <= len; clen <<= 1) {
    ++cnt;
    for (j = 0; j < len; j += clen) {
      int *w = (fl == 1 ? wn_pos_pw[cnt] : wn_neg_pw[cnt]);
      for (k = j; k < j + (clen >> 1); k++) {
        tmp1 = c[k];
        tmp2 = 1ll * (*w) * c[k + (clen >> 1)] % MOD;
        c[k] = add(tmp1 + tmp2);
        c[k + (clen >> 1)] = sub(tmp1 - tmp2);
        w++;
      }
    }
  }
  if (fl == -1) {
    int inv = quick_pow(len, MOD - 2);
    for (int i = 0; i < len; i++) c[i] = 1ll * c[i] * inv % MOD;
  }
}
void poly_mul(int A[], int B[], int N, int M) {
  if (!init) poly_init();
  int len = 1;
  while (len <= N + M) len <<= 1;
  l = max(l, len);
  memset(A + N, 0, (len - N) * sizeof(int));
  memset(B + M, 0, (len - M) * sizeof(int));
  poly_ntt(A, len, 1);
  poly_ntt(B, len, 1);
  for (int i = 0; i < len; i++) A[i] = 1ll * A[i] * B[i] % MOD;
  poly_ntt(A, len, -1);
}
}  // namespace NTT
int n;
char s[MAXN + 48][10];
int tmp[MAXN + 48], A[MAXN + 48], B[MAXN + 48];
void solve(int left, int right) {
  if (left == right) {
    char ch1 = s[left][1], ch2 = s[left][2];
    if (ch1 != 'W' && ch2 != 'W')
      tmp[0] = 1;
    else
      tmp[0] = 0;
    if (ch1 != 'B' && ch2 != 'B')
      tmp[2] = 1;
    else
      tmp[2] = 0;
    if (ch1 == '?' && ch2 == '?')
      tmp[1] = 2;
    else if (ch1 == ch2)
      tmp[1] = 0;
    else
      tmp[1] = 1;
    return;
  }
  int mid = (left + right) >> 1, N = (mid - left + 1) * 2 + 1,
      M = (right - mid) * 2 + 1;
  int len = 1;
  while (len <= N + M) len <<= 1;
  int Tmp[len + 48];
  solve(left, mid);
  memcpy(Tmp, tmp, N * sizeof(int));
  solve(mid + 1, right);
  memcpy(A, Tmp, N * sizeof(int));
  memcpy(B, tmp, M * sizeof(int));
  NTT::poly_mul(A, B, N, M);
  memcpy(tmp, A, len * sizeof(int));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  bool WB = true, BW = true;
  for (int i = 1; i <= n; i++) {
    if (s[i][1] == 'B' || s[i][2] == 'W') WB = false;
    if (s[i][1] == 'W' || s[i][2] == 'B') BW = false;
  }
  int ans = 0;
  if (WB) ans++;
  if (BW) ans++;
  solve(1, n);
  Add(ans, tmp[n]);
  int res = 1;
  for (int i = 1; i <= n; i++) {
    int curans = 0;
    if (s[i][1] != 'B' && s[i][2] != 'W') curans++;
    if (s[i][1] != 'W' && s[i][2] != 'B') curans++;
    res = 1ll * res * curans % MOD;
  }
  Sub(ans, res);
  printf("%d\n", ans);
  return 0;
}
