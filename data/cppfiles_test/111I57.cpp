#include <bits/stdc++.h>
using namespace std;

// loops
#define FOR_3(i, a, b) for (int i = (a), bb##i = (b); i < bb##i; ++i)
#define FORR_3(i, a, b) for (int i = (b)-1, aa##i = (a); i >= aa##i; --i)

#define FOR_2(i, n) FOR_3(i, 0, n)
#define FORR_2(i, n) FORR_3(i, 0, n)

#define FOR_1(n) FOR_2(_i##__LINE__, n)
#define FOR_0() for (;;)

#define OVERLOAD(_0, _1, _2, _3, NAME, ...) NAME
#define FOR(...)                                                               \
  OVERLOAD(_0, ##__VA_ARGS__, FOR_3, FOR_2, FOR_1, FOR_0)(__VA_ARGS__)
#define FORR(...)                                                              \
  OVERLOAD(_0, ##__VA_ARGS__, FORR_3, FORR_2, FORR_1, FOR_0)(__VA_ARGS__)

// min / max

template <class T> auto min(T &&t) { return move(t); };
template <class T, class... TS> auto min(T &&t, TS &&...ts) {
  auto rest = min(forward<TS>(ts)...);
  return t < rest ? t : rest;
}

template <class T> auto max(T &&t) { return move(t); };
template <class T, class... TS> auto max(T &&t, TS &&...ts) {
  auto rest = max(forward<TS>(ts)...);
  return t > rest ? t : rest;
}

#define REMIN(a, b) ((a) = min(a, b))
#define REMAX(a, b) ((a) = max(a, b))

// containers / arrays
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) int((x).size())
#define ZERO(x) memset(x, 0, sizeof(x));

// other
#define UNUSED(...) (void)(__VA_ARGS__);

// types
#define umap unordered_map
#define deq deque

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

using di = deque<int>;
using dll = deque<ll>;
using dpii = deque<pii>;

// abbrevs
#define push push_back
#define pop pop_back

// array operations
#define SORT(v) sort(ALL(v));
#define UNIQUE(c)                                                              \
  {                                                                            \
    SORT(c);                                                                   \
    c.erase(unique(ALL(c)), c.end());                                          \
  }

auto PERM(int n) {
  di v(n);
  FOR(i, n) v[i] = i;
  return v;
}

template <class V> auto esort(const V &v) {
  auto perm = PERM(SZ(v));
  sort(ALL(perm), [&](int a, int b) { return v[a] < v[b]; });
  return perm;
}

template <class V> auto eremap(V &&vv) {
  auto v = move(vv);
  SORT(v);
  umap<typename V::value_type, int> r;
  int nxt = 0;
  for (auto &e : v)
    if (r.emplace(e, nxt).second)
      ++nxt;
  return r;
}

#ifdef LOCAL
#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>

void print_trace() {
  char pid_buf[30];
  sprintf(pid_buf, "%d", getpid());
  char name_buf[512];
  name_buf[readlink("/proc/self/exe", name_buf, 511)] = 0;
  prctl(PR_SET_PTRACER, PR_SET_PTRACER_ANY, 0, 0, 0);
  int child_pid = fork();
  if (!child_pid) {
    dup2(2, 1); // redirect output to stderr - edit: unnecessary?
    execl("/usr/bin/gdb", "gdb", "--batch", "-n", "-ex", "thread", "-ex", "bt",
          name_buf, pid_buf, NULL);
    abort(); /* If gdb failed to start */
  } else {
    waitpid(child_pid, NULL, 0);
  }
}

extern const char *const sys_siglist[];

void handler(int sig) {
  cerr << "SIGNAL " << sig << " (" << sys_siglist[sig] << ")" << endl;
  print_trace();
  exit(1);
}

#define INDENT_SIZE 2
string indent;

void _E() { cerr << endl; }
template <class ARG, class... ARGS> void _E(ARG &&arg, ARGS &&...args) {
  cerr << std::forward<ARG>(arg) << " ";
  _E(std::forward<ARGS>(args)...);
}

#define E(...)                                                                 \
  {                                                                            \
    cerr << indent;                                                            \
    _E(__VA_ARGS__);                                                           \
  }

#define _V5(x) #x, "==", (x)
#define _V4(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V5(__VA_ARGS__))
#define _V3(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V4(__VA_ARGS__))
#define _V2(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V3(__VA_ARGS__))
#define _V1(x, ...) #x, "==", (x)__VA_OPT__(, "|", _V2(__VA_ARGS__))
#define V(...) P(_V1(__VA_ARGS__))
#define INDENT auto _indenter = Indenter();

struct Indenter {
  Indenter() { FOR(INDENT_SIZE) indent.push_back(' '); }
  ~Indenter() { FOR(INDENT_SIZE) indent.pop_back(); }
};

#define FAIL(str)                                                              \
  {                                                                            \
    cerr << "ASSERT FAILED   " << str << "   " << __FILE__ << ':' << __LINE__  \
         << endl;                                                              \
    print_trace();                                                             \
    abort();                                                                   \
  }

#define SLEEP this_thread::sleep_for(100ms);

#else
#define INDENT
#define SLEEP
#define FAIL(x)                                                                \
  {}
#define E(...)                                                                 \
  {}
#define V(...)                                                                 \
  {}
#endif

// asserts
#define CHECK(cond)                                                            \
  if (!(cond))                                                                 \
  FAIL(#cond)

#define CHECK_OP(op, a, b, res)                                                \
  if (!(res))                                                                  \
  FAIL(#a " " op " " #b "   (" + to_string(a) + " vs " + to_string(b) + ")")

#define CHECK_EQ(a, b) CHECK_OP("==", a, b, (a) == (b))
#define CHECK_NE(a, b) CHECK_OP("!=", a, b, (a) != (b))
#define CHECK_LE(a, b) CHECK_OP("<=", a, b, (a) <= (b))
#define CHECK_GE(a, b) CHECK_OP(">=", a, b, (a) >= (b))
#define CHECK_LT(a, b) CHECK_OP("<", a, b, (a) < (b))
#define CHECK_GT(a, b) CHECK_OP(">", a, b, (a) > (b))

#define CHECK_RANGE(x, a, b)                                                   \
  if (!(a <= x && x < b))                                                      \
  FAIL(#x " in [" #a "," #b ")")

template <class A, class B> auto divup(A a, B b) { return (a + b - 1) / b; }

// bit operations
int msb(int x) {
  CHECK_GT(x, 0)
  return 31 - __builtin_clz(x);
}

int msb(ll x) {
  CHECK_GT(x, 0)
  return 31 - __builtin_clzll(x);
}

int lsb(int x) {
  CHECK_GT(x, 0)
  return __builtin_ctz(x);
}

int lsb(ll x) {
  CHECK_GT(x, 0)
  return __builtin_ctzll(x);
}

int popcount(int x) { return __builtin_popcount(x); }
int popcount(ll x) { return __builtin_popcountll(x); }

#define FORB(b, mask)                                                          \
  for (auto m = mask, bit = lsb(m); m; m ^= (1 << b), bit = lsb(m))

#define FORS(s, mask)                                                          \
  for (auto s = mask; s; s = (s - 1) & mask) // iterate subsets

auto round_up_pow2(int x) { return 1 << (msb(x - 1) + 1); }

default_random_engine RNG(123);
#define SHUFFLE(c) shuffle(ALL(c), RNG);

// stdin
template <class T> T read() {
  T x;
  cin >> x;
  return x;
}
#define RI read<int>()
#define RLL read<LL>()

void _R() {}
template <class ARG, class... ARGS> void _R(ARG &&arg, ARGS &&...args) {
  cin >> arg;
  _R(forward<ARGS>(args)...);
}
#define R(...) _R(__VA_ARGS__);

// stdout
template <class T> void _print(T x) { cout << x << " "; }
template <class T> void _print(deq<T> &d) {
  for (auto &e : d)
    cout << e << " ";
}
void _P() { cout << '\n'; }
template <class ARG, class... ARGS> void _P(ARG &&arg, ARGS &&...args) {
  _print(arg);
  _P(forward<ARGS>(args)...);
}
#define P(...) _P(__VA_ARGS__);

// stderr
template <class T> auto &operator<<(ostream &os, deq<T> &v) {
  os << "{";
  bool first = true;
  for (auto &e : v) {
    if (first)
      first = false;
    else
      os << " ";
    os << e;
  }
  return os << "}";
}

template <class A, class B> auto &operator<<(ostream &os, pair<A, B> &p) {
  return os << "{" << p.first << " " << p.second << "}";
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// const int MOD = 1e9 + 7;
const int MOD = 998'244'353;

template <class T, class E> T fpow(T a, E exp) {
  T r = 1;
  while (exp) {
    if (exp & 1) {
      r *= a;
      --exp;
    } else {
      exp >>= 1;
      a *= a;
    }
  }
  return r;
}

class F {
public:
  using H = int;
  H h = 0;

public:
  F() = default;

  F(H x)
      : h((x + MOD) % MOD){CHECK_GE(x + MOD, 0)}

        F(const F &) = default;

public:
  F &operator+=(const F &o) {
    h += o.h;
    if (h >= MOD)
      h -= MOD;
    return *this;
  }

  F &operator-=(const F &o) {
    h = MOD + h - o.h;
    if (h >= MOD)
      h -= MOD;
    return *this;
  }

  F &operator*=(const F &o) {
    h = (1ULL * h * o.h) % MOD;
    return *this;
  }

  F &operator/=(const F &o) {
    const auto TOTIENT = MOD - 1;
    *this *= fpow(o, TOTIENT - 1);
    return *this;
  }

  bool operator==(const F &o) const { return h == o.h; }
  bool operator!=(const F &o) const { return h != o.h; }

  F operator+(const F &o) const { return F(*this) += o; }
  F operator-(const F &o) const { return F(*this) -= o; }
  F operator*(const F &o) const { return F(*this) *= o; }
  F operator/(const F &o) const { return F(*this) /= o; }

  F &operator--() {
    if (h == 0)
      h = MOD;
    --h;
    return *this;
  }
  F &operator++() {
    ++h;
    if (h == MOD)
      h = 0;
    return *this;
  }
  F operator--(int) {
    auto m = *this;
    --(*this);
    return m;
  }
  F operator++(int) {
    auto m = *this;
    ++(*this);
    return m;
  }

  explicit operator H() const { return h; }
};

ostream &operator<<(ostream &os, const F &modulo) { return os << modulo.h; }

////////////////////////////////////////////////////////////////////////////////

//
// snippets/binomial.hpp
//
template <class VAL> struct Binomial {
  int n = 0;
  int k = 0;
  VAL val = (VAL)1;

public:
  Binomial() = default;

  Binomial(int nn, int kk) { (*this)(nn, kk); }

  // hack
  Binomial(int nn, int kk, const VAL &vv) : n(nn), k(kk), val(vv) {}

  operator const VAL &() const { return val; }

  VAL operator()(int nn, int kk) {
    if (outside(nn, kk))
      return VAL(0);

    while (k > kk)
      move_l();
    while (n > nn)
      move_u();
    while (n < nn)
      move_d();
    while (k < kk)
      move_r();

    return val;
  }

  static bool outside(int nn, int kk) { return nn < 0 || kk < 0 || kk > nn; }

  void move_l() {
    --k;
    val *= VAL(k + 1);
    val /= VAL(n - k);
  }

  void move_r() {
    ++k;
    val *= VAL(n - k + 1);
    val /= VAL(k);
  }

  void move_d() {
    ++n;
    val *= VAL(n);
    val /= VAL(n - k);
  }

  void move_u() {
    --n;
    val *= VAL(n - k + 1);
    val /= VAL(n + 1);
  }
};

using B = Binomial<F>;

////////////////////////////////////////////////////////////////////////////////

const bool MULTIPLE_TEST_CASES = false;

struct TC {
  struct Pt {
    array<int, 2> x;
    int c;
    bool operator<(const Pt &o) const { return x < o.x; }
  };
  deq<Pt> pts;

  int n, k, q;
  dll in;

  TC() {
    R(n, k)
    // FOR(n) pts.push({{RI, RI}, RI});
    FOR(n) in.push(RI);
    //
    F dp[2][n + 1][n + 1];
    ZERO(dp);
    int c = 0;

    dp[c][0][0] = 1;

    int range[2][2];
    range[c][0] = 0;
    range[c][1] = 1;

    FOR(i, n) {
      c = !c;
      range[c][0] = max(0, in[i] - k);
      range[c][1] = min(n + 1, in[i] + k + 1);
      FOR(mex, range[c][0], range[c][1]) FOR(up, n + 1) {
        auto &v = dp[c][mex][up];
        v = 0;
        v += dp[!c][mex][up] * (mex + up);
        if (up - 1 >= 0)
          v += dp[!c][mex][up - 1] * up;
        FORR(pmex, range[!c][0], min(mex, range[!c][1])) {
          if (up + (mex - pmex) - 1 > n)
            break;
          v += dp[!c][pmex][up + (mex - pmex) - 1];
        }
      }
    }

    B binomial;

    V(range[c][0], range[c][1])

    F res = 0;
    FOR(mex, range[c][0], range[c][1]) {
      FOR(up, n + 1) {
        V(dp[c][mex][up])
        res += dp[c][mex][up] * binomial(n - mex, up);
      }
    }

    P(res);
  }

  int yes = -1;
};

////////////////////////////////////////////////////////////////////////////////

int main() {
#ifdef LOCAL
  signal(SIGSEGV, handler);
  signal(SIGABRT, handler);
#endif
  ios_base::sync_with_stdio(0);
  cout.precision(20);
  cout << fixed;

  int num_cases = 1;
  if (MULTIPLE_TEST_CASES)
    cin >> num_cases;

  FOR(i, num_cases) {
    E()
    E("TEST CASE", i + 1)
    INDENT
    TC tc;
    if (tc.yes != -1)
      P(tc.yes ? "YES" : "NO")
  }

  return 0;
}
