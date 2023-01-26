#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u32 = unsigned int;
using db = double;
using ld = long double;
using pii = std::array<int, 2>;
using pll = std::array<ll, 2>;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3f;
namespace Fast_in {
template <typename T>
void in(T &x) {
  x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (f) x = -x;
}
template <typename T>
T in() {
  T x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
template <typename T, typename... Tp>
void in(T &x, Tp &...a) {
  in(x);
  in(a...);
}
template <typename T>
void in(T *l, T *r) {
  for (; l != r; ++l) in(*l);
}
}  // namespace Fast_in
using namespace Fast_in;
namespace Fast_out {
template <typename T>
void out_sub(T x, char ch = '\n') {
  static int tp, sk[30];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  do {
    sk[++tp] = x % 10;
    x /= 10;
  } while (x);
  while (tp) {
    putchar(sk[tp--] + '0');
  }
  putchar(ch);
}
void out(int x, char ch = '\n') { out_sub(x, ch); }
void out(ll x, char ch = '\n') { out_sub(x, ch); }
void out(u32 x, char ch = '\n') { out_sub(x, ch); }
void out(ull x, char ch = '\n') { out_sub(x, ch); }
void out(db x, char ch = '\n') { printf("%.12f%c", x, ch); }
void out(ld x, char ch = '\n') { printf("%.12Lf%c", x, ch); }
void out(char x, char ch = '\n') { printf("%d%c", x, ch); }
void out(char *x, char ch = '\n') { printf("%s%c", x, ch); }
void out(string x, char ch = '\n') { printf("%s%c", x.c_str(), ch); }
void out(pii x) { out_sub(x[0], ' '), out_sub(x[1]); }
void out(pll x) { out_sub(x[0], ' '), out_sub(x[1]); }
template <typename T>
void out(vector<T> x, char ch = ' ') {
  if (x.empty()) {
    puts("");
    return;
  }
  T val = x.back();
  x.pop_back();
  for (auto i : x) out(i, ch);
  out(val);
}
template <typename T>
void out(set<T> x, char ch = ' ') {
  if (x.empty()) {
    puts("");
    return;
  }
  T val = *x.rbegin();
  x.erase(--x.end());
  for (auto i : x) out(i, ch);
  out(val);
}
template <typename T>
void out(T *l, T *r, char ch = ' ') {
  if (l == r) {
    puts("");
    return;
  }
  --r;
  for (; l != r; ++l) out(*l, ch);
  if (l == r) out(*l);
}
template <typename T, typename... Tp>
void out(T x, Tp... a) {
  out(x, ' ');
  out(a...);
}
}  // namespace Fast_out
using namespace Fast_out;
namespace Bin {
template <int len = 0, typename T>
void out_bin(T x, char ch = '\n') {
  if (len) {
    cout << bitset<len>(x).to_string() << ch;
    return;
  }
  long long val = 1ll << 32;
  bool flg = false;
  if (x > val) {
    for (int i = 63; ~i; --i)
      if (flg)
        printf("%d", (x >> i) & 1);
      else if ((x >> i) & 1) {
        flg = true;
        printf("1");
      }
  } else {
    for (int i = 31; ~i; --i)
      if (flg)
        printf("%d", (x >> i) & 1);
      else if ((x >> i) & 1) {
        flg = true;
        printf("1");
      }
  }
  putchar(ch);
}
template <typename T>
void in_bin(T &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x <<= 1;
    x |= ch & 1;
    ch = getchar();
  }
}
}  // namespace Bin
using namespace Bin;
struct Timer {
  int val, pre;
  Timer() {
    pre = clock();
    val = clock();
  }
  void operator()(int flg = 2) {
    if (flg == 2) val = pre;
    int now = clock();
    if (flg != 0) std::cerr << now - val << "ms\n";
    if (flg != 1) val = now;
    pre = now;
  }
};
Timer Time;
struct Random {
  mt19937 my_rand;
  Random() {
    srand((long long)new char);
    my_rand.seed(rand());
  }
};
Random __Rd;
template <typename T>
T rnd(T _l, T _r) {
  T len = _r - _l + 1;
  return __Rd.my_rand() % len + _l;
}
template <typename T>
void Max(T &x, T y) {
  x < y && (x = y);
}
template <typename T>
void Min(T &x, T y) {
  x > y && (x = y);
}
template <typename T, class Func>
void Max(T &x, T y, Func F) {
  if (x < y) {
    x = y;
    F();
  }
}
template <typename T, class Func>
void Min(T &x, T y, Func F) {
  if (x > y) {
    x = y;
    F();
  }
}
template <typename T>
T abss(T x) {
  return x < 0 ? -x : x;
}
void File(string In, string Out) {
  if (!In.empty()) freopen(In.c_str(), "r", stdin);
  if (!Out.empty()) freopen(Out.c_str(), "w", stdout);
}
namespace Mod {
const int md = 998244353;
inline int add(const int &a, const int &b) {
  int p = a + b;
  if (p >= md) p -= md;
  return p;
}
inline int sub(const int &a, const int &b) {
  int p = a - b;
  if (p < 0) p += md;
  return p;
}
inline void add_(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub_(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int __mul(const int &a, const int &b) { return 1ll * a * b % md; }
inline int mul(const int &a, const int &b) {
  int p = __mul(a, b);
  if (p < 0) p += md;
  return p;
}
template <typename T>
int qpow(int a, T b) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
inline int inv(int x) { return qpow(x, md - 2); }
inline void inv(int *F, int len, int *G = NULL, bool flg = false) {
  if (G == NULL) G = F;
  if (flg) {
    F[0] = G[0] = 1;
    for (int i = 1; i <= len; ++i) F[i] = __mul(F[i - 1], i);
  }
  std::vector<int> S(len + 1), iS(len + 1);
  S[0] = 1;
  for (int i = 1; i <= len; ++i) S[i] = mul(S[i - 1], F[i]);
  iS[len] = inv(S[len]);
  for (int i = len; i >= 1; --i) {
    iS[i - 1] = mul(iS[i], F[i]);
    G[i] = mul(S[i - 1], iS[i]);
  }
}
}  // namespace Mod
using namespace Mod;
namespace gvihvo {
const int N = 5010;
int n, k;
char s[N];
int C[N][N];
int sum[N];
int top;
pii stk[N];
void main() {
  in(n, k);
  if (k == 0) {
    out(1);
    return;
  }
  scanf("%s", s + 1);
  int ans = 0;
  for (int i = (0); i <= (n); ++i) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); ++j)
      C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  }
  for (int i = (1); i <= (n); ++i) sum[i] = sum[i - 1] + (s[i] == '1');
  for (int i = 1, j = 1; i <= n; ++i) {
    if (s[i - 1] == '0') continue;
    while (j + 1 <= n && sum[j + 1] - sum[i - 1] <= k) ++j;
    if (sum[j] - sum[i - 1] != k) break;
    stk[++top] = {i, j};
  }
  if (!top) {
    out(1);
    return;
  }
  for (int i = (1); i <= (top - 1); ++i) {
    ans = add(ans, C[stk[i][1] - stk[i][0] + 1][k]);
    if (stk[i][1] >= stk[i + 1][0]) {
      ans = sub(ans, C[stk[i][1] - stk[i + 1][0] + 1]
                      [sum[stk[i][1]] - sum[stk[i + 1][0] - 1]]);
    } else
      ans = sub(ans, 1);
  }
  ans = add(ans, C[stk[top][1] - stk[top][0] + 1][k]);
  out(ans);
}
void init() { ; }
}  // namespace gvihvo
int main() {
  gvihvo::init();
  gvihvo::main();
  return 0;
}
