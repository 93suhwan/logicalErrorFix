#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 1000010, mod = 998244353;
struct edge {
  int next, to;
} e[maxn];
int head[maxn], len;
void add(int x, int y) {
  e[++len] = {head[x], y};
  head[x] = len;
}
int w[maxn];
void dfs(int now, int fa) {
  for (int i = head[now]; i; i = e[i].next) {
    int u = e[i].to;
    if (u == fa) continue;
    dfs(u, now);
    w[now]++;
  }
}
long long ksm(long long num, int T) {
  long long sum = 1ll;
  while (T) {
    if (T % 2) sum = sum * num % mod;
    num = num * num % mod;
    T >>= 1;
  }
  return sum;
}
namespace NTT {
int R[maxn];
long long tmp[maxn];
void FFT(int len, long long *a, bool op, int L) {
  for (int i = 0; i < len; i++)
    R[i] = (R[i / 2] / 2) + ((i % 2) * (1 << L - 1));
  for (int i = 0; i < len; i++) tmp[R[i]] = a[i];
  for (int i = 0; i < len; i++) a[i] = tmp[i];
  long long Wn, w;
  for (int i = 1; i < len; i *= 2) {
    Wn = ksm((op ? 3 : 332748118), (mod - 1) / (i * 2));
    for (int j = 0; j < len; j += i * 2) {
      w = 1;
      for (int k = 0; k < i; k++, w = w * Wn % mod) {
        int K = k + j;
        long long S1 = a[K], S2 = w * a[K + i] % mod;
        a[K] = (S1 + S2) % mod;
        a[K + i] = (S1 - S2 + mod) % mod;
      }
    }
  }
}
}  // namespace NTT
using namespace NTT;
int i, j, k, n, m, T, chs[maxn];
long long A[maxn], B[maxn], jc[maxn];
vector<int> V[maxn];
void build(int root, int L, int R) {
  if (L == R) {
    chs[root] = L;
    V[L].push_back(w[L]);
    V[L].push_back(1);
  } else {
    build(root * 2, L, ((L + R) / 2));
    build(root * 2 + 1, ((L + R) / 2) + 1, R);
    int len = 1, Ls = 0;
    while (len <= (R - L + 2)) len <<= 1, ++Ls;
    for (int i = 0; i <= (((L + R) / 2) - L + 1); i++)
      A[i] = V[chs[root * 2]][i];
    for (int i = 0; i <= (R - ((L + R) / 2)); i++)
      B[i] = V[chs[root * 2 + 1]][i];
    FFT(len, A, true, Ls);
    FFT(len, B, true, Ls);
    for (int i = 0; i < len; i++) A[i] = A[i] * B[i] % mod;
    FFT(len, A, false, Ls);
    chs[root] = chs[root * 2];
    V[chs[root]].clear();
    long long W = ksm(len, mod - 2);
    for (int i = 0; i <= len; i++) V[chs[root]].push_back(A[i] * W % mod);
    for (int i = 0; i <= len; i++) A[i] = B[i] = 0;
  }
}
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  build(1, 1, n);
  long long ans = 0;
  jc[0] = 1;
  for (i = 1; i <= n; i++)
    jc[i] = jc[i - 1] * i % mod,
    ans += jc[i] * ((n - i) % 2 ? -1 : 1) * V[chs[1]][i] % mod, ans %= mod;
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}
