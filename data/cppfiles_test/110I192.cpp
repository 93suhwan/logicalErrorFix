#include <bits/stdc++.h>
using namespace std;

// loops
#define FOR_3(i, a, b) for (int i = (a), bb = (b); i < bb; ++i)
#define FORR_3(i, a, b) for (int i = (b)-1, aa = (a); i >= aa; --i)

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
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define REMIN(a, b) ((a) = MIN(a, b))
#define REMAX(a, b) ((a) = MAX(a, b))

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

template <class V> auto remap(const V &v) {
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

const bool MULTIPLE_TEST_CASES = false;

struct TC {
  struct Pt {
    array<int, 2> x;
    int c;
    bool operator<(const Pt &o) const { return x < o.x; }
  };
  deq<Pt> pts;

  void flip() {
    for (auto &p : pts)
      p.x[0] *= -1;
  }

  void flipd() {
    for (auto &p : pts)
      swap(p.x[0], p.x[1]);
  }

  void ccycle() {
    for (auto &p : pts)
      p.c = (p.c + 1) % 3;
  }

  void cflip() {
    for (auto &p : pts)
      p.c == 2 ? 2 : !p.c;
  }

  int n, k, q;
  dll in;

  int best = 0;

  void solve() {
    SORT(pts);
    int num0 = n / 3;
    int idx = 0;

    set<int> l, r;

    while (idx < n) {
      int x0 = pts[idx].x[0];
      int next_idx = idx;

      while (next_idx < n && pts[next_idx].x[0] == x0)
        ++next_idx;

      int dnum0 = 0;

      FOR(i, idx, next_idx) {
        if (pts[i].c == 0)
          ++dnum0;
      }

      FOR(dnum0 + 1) {
        CHECK_GE(num0, 0)
        while (SZ(l) > num0)
          l.erase(prev(l.end()));

        while (SZ(r) > num0)
          r.erase(r.begin());

        if (num0 == SZ(l) && num0 == SZ(r) && num0 > 0 &&
            *l.rbegin() < *r.begin())
          REMAX(best, num0);

        --num0;
      }
      ++num0;

      FOR(i, idx, next_idx) {
        if (pts[i].c == 1)
          l.insert(pts[i].x[1]);
        else if (pts[i].c == 2)
          r.insert(pts[i].x[1]);
      }

      idx = next_idx;
    }
  }

  void solve_c() {
    FOR(3) {
      solve();

      cflip();
      solve();
      cflip();

      ccycle();
    }
  }

  TC() {
    R(n)
    FOR(n) pts.push({{RI, RI}, RI - 1});
    // FOR(n) in.push(RI);
    //

    FOR(4) {
      solve_c();

      flip();
      flipd();
    }

    P(best * 3)
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
