#include <bits/stdc++.h>
using namespace std;
using INT = int;
template <class T>
using refT = reference_wrapper<T>;
template <class T>
using crefT = reference_wrapper<const T>;
auto &_ = std::ignore;
using ll = long long;
template <class T>
using vec = vector<T>;
template <bool B, class T = void>
using enableif_t = typename enable_if<B, T>::type;
template <class U>
struct canOut {
  template <class T>
  constexpr static auto is(int i) -> decltype((cout << *(T *)(0)), true) {
    return true;
  }
  template <class T>
  constexpr static bool is(...) {
    return false;
  }
  static const bool value = is<U>(1);
};
template <class U>
struct canFor {
  template <class T>
  constexpr static auto is(int i) -> decltype(begin(*(T *)(0)), true) {
    return true;
  }
  template <class T>
  constexpr static bool is(...) {
    return false;
  }
  static const bool value = is<U>(1);
};
constexpr struct {
  template <class T>
  constexpr operator T() const {
    return numeric_limits<T>::max();
  }
} INF;
constexpr struct {
  template <class T>
  constexpr operator T() const {
    return numeric_limits<T>::min();
  }
} MINF;
template <size_t i, class T>
auto operator>>(istream &is, T &r)
    -> decltype(enableif_t<i == tuple_size<T>::value>(1), is) {
  return is;
}
template <size_t i = 0, class T>
auto operator>>(istream &is, T &r)
    -> decltype(enableif_t<i != tuple_size<T>::value>(1), is) {
  is >> get<i>(r);
  return operator>><i + 1>(is, r);
}
template <class T>
auto __format(ostream &os, const char *c, const T &cv)
    -> decltype(enableif_t<canOut<T>::value>(1), c + 1) {
  os << cv;
  while (*c != '}') c++;
  return c + 1;
}
template <size_t i, class T>
auto __format(ostream &os, const char *c, const T &cv)
    -> decltype(enableif_t<!canFor<T>::value>(1),
                enableif_t<i == tuple_size<T>::value>(1), c + 1) {
  return c;
}
template <size_t i = 0, class T>
auto __format(ostream &os, const char *c, const T &cv)
    -> decltype(enableif_t<!canFor<T>::value>(1),
                enableif_t<i != tuple_size<T>::value>(1), c + 1) {
  while (*c != '{') os << *c++;
  c = __format(os, c, get<i>(cv));
  return __format<i + 1>(os, c, cv);
}
template <class T>
auto __format(ostream &os, const char *c, const T &cv)
    -> decltype(enableif_t<!canOut<T>::value>(1),
                enableif_t<canFor<T>::value>(1), c + 1) {
  const char *ct = c + 1;
  if (cv.size() == 0) {
    while (*ct != '}') ct++;
    ct++;
    while (*ct != '}') ct++;
  } else {
    for (auto &i : cv) {
      const char *cc = c + 1;
      while (*cc != '{') os << *cc++;
      cc = __format(os, cc, i);
      while (*cc != '}') os << *cc++;
      ct = cc;
    }
  }
  return ct + 1;
}
void _format(ostream &os, const char *c) {
  while (*c != '{' && *c != '\0') os << *c++;
}
template <class T, class... Args>
void _format(ostream &os, const char *c, const T &a, Args &&...rest) {
  while (*c != '{' && *c != '\0') os << *c++;
  if (*c == '{') c = __format(os, c, a);
  _format(os, c, forward<Args>(rest)...);
}
template <class... Args>
string format(const char *c, Args &&...rest) {
  ostringstream os;
  _format(os, c, forward<Args>(rest)...);
  return os.str();
}
template <class... Args>
ostream &print(const char *c, Args &&...rest) {
  return _format(cout, c, forward<Args>(rest)...), cout;
}
template <class T, class... Args>
struct Rtar {
  T &a;
  tuple<Args...> n;
  Rtar(T &a, tuple<Args...> n) : a(a), n(n) {}
};
template <class T, class... Args>
Rtar<T, Args &...> rtar(T &a, Args &...rest) {
  return Rtar<T, Args &...>(a, tie(rest...));
}
template <size_t i, class U, class... Args, class T = tuple<Args &...>>
auto operator>>(istream &is, Rtar<U, Args &...> r)
    -> decltype(enableif_t<i == tuple_size<T>::value>(1), is) {
  return is >> r.a;
}
template <size_t i = 0, class U, class... Args, class T = tuple<Args &...>>
auto operator>>(istream &is, Rtar<U, Args &...> r)
    -> decltype(enableif_t<i != tuple_size<T>::value>(1), is) {
  r.a = typename decay<U>::type(get<i>(r.n));
  for (auto &w : r.a)
    operator>><i + 1>(is, Rtar<decltype(w), Args &...>(w, r.n));
  return is;
}
template <class T1, class T2>
bool cmin(T1 &a, const T2 b) {
  return a > b ? a = b, 1 : 0;
}
template <class T1, class T2>
bool cmax(T1 &a, const T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <class T1, class T2, class... T3>
bool cmin(T1 &a, const T2 b, const T3... rest) {
  return cmin(a, b) | cmin(a, rest...);
}
template <class T1, class T2, class... T3>
bool cmax(T1 &a, const T2 b, const T3... rest) {
  return cmax(a, b) | cmax(a, rest...);
}
bool MULTIDATA = true;
struct solution {
  int n;
  vector<int> v;
  void scan() { cin >> n >> rtar(v, n); }
  void solve() {
    int a1 = n / 2, a0 = n - a1;
    array<int, 2> c = {};
    for (auto i : v) c[i % 2]++;
    ll minn = INF;
    if (c[0] == a0) {
      ll c = 0;
      bool f = 0;
      array<deque<int>, 2> p, q;
      for (int i = 0; i < n; i++) q[v[i] % 2].push_back(i);
      for (int i = 0; i < n; i++, f = !f) {
        c += abs(i - q[f].front());
        q[f].pop_front();
      }
      cmin(minn, c);
    }
    if (c[1] == a0) {
      ll c = 0;
      bool f = 1;
      array<deque<int>, 2> p, q;
      for (int i = 0; i < n; i++) q[v[i] % 2].push_back(i);
      for (int i = 0; i < n; i++, f = !f) {
        c += abs(i - q[f].front());
        q[f].pop_front();
      }
      cmin(minn, c);
    }
    if (minn == (ll)INF)
      cout << -1 << endl;
    else
      cout << minn / 2 << endl;
  }
};
INT main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  if (MULTIDATA) cin >> (T);
  while (T--) {
    auto a = unique_ptr<solution>(new solution());
    a->scan();
    a->solve();
    if (!cin.good()) break;
  }
  return 0;
}
