#include <bits/stdc++.h>
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
template <class T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long qpow(long long a, int b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) (ans *= a) %= 998244353;
    (a *= a) %= 998244353;
  }
  return ans;
}
struct Z {
  int x;
  inline int val() const { return x; }
  inline int inv() const { return qpow(x, 998244353 - 2); }
  Z(int x = 0) : x(x) {}
  Z operator-() const {
    return Z((998244353 - x >= 998244353 ? 998244353 - x - 998244353
                                         : 998244353 - x));
  }
  Z &operator+=(const Z &z) {
    x = (x + z.x >= 998244353 ? x + z.x - 998244353 : x + z.x);
    return *this;
  }
  Z &operator-=(const Z &z) {
    x = (x - z.x < 0 ? x - z.x + 998244353 : x - z.x);
    return *this;
  }
  Z &operator*=(const Z &z) {
    x = 1ll * x * z.x % 998244353;
    return *this;
  }
  Z &operator/=(const Z &z) {
    x = 1ll * x * z.inv() % 998244353;
    return *this;
  }
  Z operator+(const Z &z) const {
    return Z((x + z.x >= 998244353 ? x + z.x - 998244353 : x + z.x));
  }
  Z operator-(const Z &z) const {
    return Z((x - z.x < 0 ? x - z.x + 998244353 : x - z.x));
  }
  Z operator*(const Z &z) const { return Z(1ll * x * z.x % 998244353); }
  Z operator/(const Z &z) const { return Z(1ll * x * z.inv() % 998244353); }
};
template <int T>
struct Hash {
  struct E {
    int v, w, nxt;
    E() {}
    E(int v, int w, int nxt) : v(v), w(w), nxt(nxt) {}
  } e[T + 100];
  int s_e, head[T + 100];
  std::vector<int> d;
  inline void a_e(int u, int v, int w) {
    e[++s_e] = E(v, w, head[u]);
    head[u] = s_e;
  }
  inline int H(int x) { return (1ll * x * x + (x & T) + (x ^ T)) % T + 1; }
  int &operator[](const int x) {
    int u = H(x);
    for (int i = head[u]; i; i = e[i].nxt)
      if (e[i].v == x) return e[i].w;
    a_e(u, x, 0);
    d.push_back(x);
    return e[head[u]].w;
  }
  inline void clear() {
    s_e = 0;
    for (auto u : d) head[H(u)] = 0;
    d.clear();
  }
};
long long sum[101101], f[22][101101];
inline void init(int N) {
  for (int i = 1; i <= N; i++) sum[i] = i;
  for (int i = 2; i <= N; i++) {
    if (sum[i] ^ i) continue;
    for (int j = i; j <= N; j += i) sum[j] -= sum[j] / i;
  }
  for (int i = 2; i <= N; i++) sum[i] += sum[i - 1];
}
inline long long C(int L, int R) {
  long long ans = 0;
  for (int l = L, r; l <= R; l = r + 1)
    r = R / (R / l), ans += sum[R / l] * (r - l + 1);
  return ans;
}
int k;
void solve(int l, int r, int L, int R) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  int Mid = min(mid - 1, R);
  long long c = C(Mid + 1, mid);
  long long val = 1e18;
  for (int i = Mid; i >= L; i--) {
    long long cost = f[k - 1][i] + c;
    if (cost < val) val = cost, Mid = i;
    c += sum[mid / i];
  }
  f[k][mid] = val;
  solve(l, mid - 1, L, Mid);
  solve(mid + 1, r, Mid, R);
}
const int N = 1e5;
int main() {
  init(N);
  for (int i = 1; i <= N; i++) f[1][i] = 1ll * i * (i + 1) / 2;
  for (k = 2; k <= 16; k++) solve(k, N, k - 1, N - 1);
  int t = read<int>();
  while (t--) {
    int n = read<int>();
    int k = read<int>();
    if (k > 16)
      printf("%d\n", n);
    else
      printf("%lld\n", f[k][n]);
  }
  return 0;
}
