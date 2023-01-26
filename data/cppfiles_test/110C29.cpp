#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
template <class t, class u>
bool chmax(t& first, u second) {
  if (first < second) {
    first = second;
    return true;
  } else
    return false;
}
template <class t, class u>
bool chmin(t& first, u second) {
  if (second < first) {
    first = second;
    return true;
  } else
    return false;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, int suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0) {
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = read() + off;
  return v;
}
pi readpi(int off = 0) {
  int first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
}
template <class t, class u>
void print(const pair<t, u>& p, int suc = 1) {
  print(p.first, 2);
  print(p.second, suc);
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
template <class T>
void print_offset(const vector<T>& v, ll off, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i] + off, i == int(v.size()) - 1 ? suc : 2);
}
template <class T, size_t N>
void print(const array<T, N>& v, int suc = 1) {
  for (int i = int(0); i < int(N); i++) print(v[i], i == int(N) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
int botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
bool inc(int first, int second, int c) {
  return first <= second && second <= c;
}
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (int i = int(0); i < int(int(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
int lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vvc<int> readGraph(int n, int m) {
  vvc<int> g(n);
  for (int i = int(0); i < int(m); i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<int> readTree(int n) { return readGraph(n, n - 1); }
struct P {
  int x, y, c;
  void readinit() {
    cin >> x >> y >> c;
    c--;
  }
  void rot() { tie(x, y) = pi(-y, x); }
};
void slv() {
  int n;
  cin >> n;
  vc<P> ps(n);
  for (int i = int(0); i < int(n); i++) ps[i].readinit();
  int lw = 0, up = n / 3 + 1;
  vi first, second, c;
  while (up - lw > 1) {
    const int mid = (lw + up) / 2;
    bool ok = false;
    for (int dir = int(0); dir < int(4); dir++)
      if (!ok) {
        for (int ini = int(0); ini < int(3); ini++)
          if (!ok) {
            first.clear();
            for (int i = int(0); i < int(n); i++)
              if (ps[i].c == ini) first.push_back(ps[i].x);
            nth_element(first.begin(), first.begin() + (mid - 1), first.end());
            int lf = first[mid - 1];
            for (int _ = int(0); _ < int(2); _++) {
              second.clear();
              c.clear();
              for (int i = int(0); i < int(n); i++)
                if (lf < ps[i].x) {
                  if (ps[i].c == (ini + 1) % 3) {
                    second.push_back(_ == 0 ? ps[i].x : ps[i].y);
                  } else if (ps[i].c == (ini + 2) % 3) {
                    c.push_back(_ == 0 ? ps[i].x : ps[i].y);
                  }
                }
              if (int(second.size()) >= mid && int(c.size()) >= mid) {
                for (int $ = int(0); $ < int(2); $++) {
                  nth_element(second.begin(), second.begin() + (mid - 1),
                              second.end());
                  nth_element(c.begin(), c.end() - mid, c.end());
                  if (second[mid - 1] < c[int(c.size()) - mid]) {
                    ok = true;
                  }
                  swap(second, c);
                }
              }
            }
          }
        for (int i = int(0); i < int(n); i++) {
          ps[i].rot();
        }
      }
    if (ok)
      lw = mid;
    else
      up = mid;
  }
  print(lw * 3);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  slv();
}
