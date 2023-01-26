#include <bits/stdc++.h>
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T& t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n, m;
int pri[1010100], npri[1010100], mu[1010100], dc[1010100], cc;
void init() {
  mu[1] = 1, dc[1] = 1;
  for (int i = (2); i <= (1010100 - 1); i++) {
    if (!npri[i]) pri[++cc] = i, dc[i] = i, mu[i] = 1;
    for (int j = (1); j <= (cc); j++) {
      int x = i * pri[j];
      if (x >= 1010100) break;
      npri[x] = 1, dc[x] = dc[i] * (i % pri[j] ? pri[j] : 1);
      if (i % pri[j] == 0) break;
      mu[x] = mu[i];
    }
  }
}
int in[1010100];
int N;
int use[1010100];
struct Bit {
  int b[23], u[23], vi[23], cc;
  int add(int x) {
    int v = 1 << cc, xx = x;
    for (int i = (20); i >= (0); i--)
      if (x >> i & 1) {
        if (!b[i]) return b[i] = x, u[cc] = xx, vi[i] = v, ++cc, 1 << (cc - 1);
        x ^= b[i], v ^= vi[i];
      }
    return 1 << cc ^ v;
  }
  void work(int w) {
    int U = 0;
    for (int i = (20); i >= (0); i--)
      if (w >> i & 1) assert(b[i]), w ^= b[i], U ^= vi[i];
    for (int i = (0); i <= (cc - 1); i++)
      if (U >> i & 1) in[u[i]] = 1, ++N;
  }
} B[(int)(1010100 * 0.65)];
void work(vector<int>& V, int id, int w) {
  for (auto x : V) use[x] = B[id].add(x);
  B[id].work(w);
}
int w[1010100];
vector<int> V[1010100];
int main() {
  file();
  init();
  {
    n = 1e6, m = 0;
    for (int i = (1); i <= (n); i++)
      if (rnd(0, 1)) ++m, w[dc[i]] ^= i;
  }
  vector<int> q;
  for (int i = (1); i <= (n); i++)
    if (mu[i]) q.push_back(i);
  int Q = q.size();
  static int id[1010100];
  for (int i = (0); i <= (Q - 1); i++) id[q[i]] = i;
  for (int i = (1); i <= (n); i++) V[id[dc[i]]].push_back(i);
  for (int i = (0); i <= (Q - 1); i++) work(V[i], i, w[q[i]]);
  static int p[1010100], K;
  for (int i = (0); i <= (Q - 1); i++)
    if ((int)V[i].size() != B[i].cc) p[++K] = i;
  while (N != m) {
    int t = p[rnd(1, K)];
    int x = V[t][rnd(0, (int)V[t].size() - 1)];
    if ((use[x] & -use[x]) == use[x]) continue;
    int _N = N;
    if (in[x])
      --_N;
    else
      ++_N;
    for (int i = (0); i <= (B[t].cc - 1); i++)
      if (use[x] >> i & 1)
        assert(x != B[t].u[i]), _N += (in[B[t].u[i]] ? -1 : 1);
    if (abs(_N - m) < abs(N - m) || (abs(_N - m) == abs(N - m) && rnd(0, 1))) {
      in[x] ^= 1;
      for (int i = (0); i <= (B[t].cc - 1); i++)
        if (use[x] >> i & 1) in[B[t].u[i]] ^= 1;
      N = _N;
    }
  }
  int cc = 0;
  for (int i = (1); i <= (n); i++)
    if (in[i]) ++cc;
  assert(cc == m);
  for (int i = (1); i <= (n); i++)
    if (in[i]) printf("%d ", i);
  fflush(stdout);
  return 0;
}
