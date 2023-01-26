#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
template <class T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;
const double PI = 3.14159265359;
const double DEG = PI / 180.;
const vi dx4 = {1, 0, -1, 0};
const vi dy4 = {0, 1, 0, -1};
const vi dx8 = {1, 1, 0, -1, -1, -1, 0, 1};
const vi dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
const int INF = 1001001001;
const ll INFL = 2002002002002002002LL;
const double EPS = 1e-10;
struct fast_io {
  fast_io() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} fast_io_tmp;
template <class T>
inline ll pow(T n, int k) {
  ll v = 1;
  for (int i = 0, i_len = int(k); i < i_len; ++i) v *= n;
  return v;
}
template <class T>
inline bool chmax(T& M, const T& x) {
  if (M < x) {
    M = x;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& m, const T& x) {
  if (m > x) {
    m = x;
    return true;
  }
  return false;
}
template <class T, class U>
inline istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T, class U>
inline ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T, class U, class V>
inline istream& operator>>(istream& is, tuple<T, U, V>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return is;
}
template <class T, class U, class V>
inline ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
  os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")";
  return os;
}
template <class T, class U, class V, class W>
inline istream& operator>>(istream& is, tuple<T, U, V, W>& t) {
  is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t);
  return is;
}
template <class T, class U, class V, class W>
inline ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
  os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ","
     << get<3>(t) << ")";
  return os;
}
template <class T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : (v)) is >> x;
  return is;
}
template <class T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  for (const auto& x : (v)) os << x << " ";
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, const set<T>& s) {
  for (const auto& x : (s)) os << x << " ";
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, const unordered_set<T>& s) {
  for (const auto& x : (s)) os << x << " ";
  return os;
}
template <class T, class U>
inline ostream& operator<<(ostream& os, const map<T, U>& m) {
  for (const auto& p : (m)) os << p << " ";
  return os;
}
template <class T, class U>
inline ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
  for (const auto& p : (m)) os << p << " ";
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, stack<T> s) {
  while (!s.empty()) {
    os << s.top() << " ";
    s.pop();
  }
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, queue<T> q) {
  while (!q.empty()) {
    os << q.front() << " ";
    q.pop();
  }
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, deque<T> q) {
  while (!q.empty()) {
    os << q.front() << " ";
    q.pop_front();
  }
  return os;
}
template <class T>
inline ostream& operator<<(ostream& os, priority_queue<T> q) {
  while (!q.empty()) {
    os << q.top() << " ";
    q.pop();
  }
  return os;
}
int main() {
  int t;
  cin >> t;
  for (int hoge = 0, hoge_len = int(t); hoge < hoge_len; ++hoge) {
    int n;
    ll k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    a.push_back(18);
    ll res = 0;
    for (int i = int(1), i_end = int(n); i <= i_end; ++i) {
      ll m = pow(10, a[i] - a[i - 1]);
      if (k + 1 < m) {
        res += (k + 1) * pow(10, a[i - 1]);
        break;
      }
      res += (m - 1) * pow(10, a[i - 1]);
      k -= m - 1;
    }
    cout << res << "\n";
  }
}
