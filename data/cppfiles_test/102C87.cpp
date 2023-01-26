#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001;
struct mi {
  long long v;
  explicit operator long long() const { return v; }
  mi() { v = 0; }
  mi(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    v = v * m.v % MOD;
    return *this;
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  mi operator++(int) {
    mi temp;
    temp.v = v++;
    return temp;
  }
  mi operator--(int) {
    mi temp;
    temp.v = v--;
    return temp;
  }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mi& m) {
    os << m.v;
    return os;
  }
  friend istream& operator>>(istream& is, mi& m) {
    long long x;
    is >> x;
    m.v = x;
    return is;
  }
};
void __print(mi X) { cout << X.v; }
int K;
mi A, H;
mi vals[6];
int places[6];
map<int, map<mi, vector<int>>> get(vector<int> B) {
  int nm = (1 << (K - 1)) - 1;
  map<int, map<mi, vector<int>>> res;
  for (int m = 0; m < (1 << nm); m++) {
    int p = 0;
    int v = K;
    vector<int> cur;
    for (int i = 0; i < ((int)(B).size()); i++) cur.push_back(i);
    vector<int> place((int)(B).size());
    mi value = 0;
    while ((int)(cur).size() > 1) {
      vector<int> nxt;
      for (int i = 0; i < ((int)(cur).size() / 2); i++) {
        if (m & (1 << p)) {
          nxt.push_back(cur[i * 2]);
          place[cur[i * 2 + 1]] = places[v];
          value += B[cur[i * 2 + 1]] * vals[v];
        } else {
          nxt.push_back(cur[i * 2 + 1]);
          place[cur[i * 2]] = places[v];
          value += B[cur[i * 2]] * vals[v];
        }
        p++;
      }
      cur = nxt;
      v--;
    }
    place[cur[0]] = 2;
    value += B[cur[0]] * vals[1];
    res[B[cur[0]]][value] = (place);
  }
  return res;
}
void solve() {
  cin >> K >> A >> H;
  vals[0] = A;
  for (int i = 1; i < (6); i++) {
    vals[i] = pow(mi(A), (pow(mi(2), i - 1) + 1).v);
  }
  places[0] = 1;
  places[1] = 2;
  places[2] = 3;
  places[3] = 5;
  places[4] = 9;
  places[5] = 17;
  vector<int> A1, A2;
  for (int i = 0; i < (1 << (K - 1)); i++) {
    A1.push_back(i + 1);
    A2.push_back(i + 1 + (1 << (K - 1)));
  }
  map<int, map<mi, vector<int>>> res1 = get(A1), res2 = get(A2);
  for (auto& a : res1) {
    for (auto& b : res2) {
      for (auto& x : a.second) {
        mi cur1 = x.first + a.first * vals[0] - a.first * vals[1];
        if (b.second.count(H - cur1)) {
          vector<int> ans1 = x.second, ans2 = b.second[H - cur1];
          ans1[a.first - 1] = 1;
          for (auto& c : ans1) cout << c << " ";
          for (auto& c : ans2) cout << c << " ";
          return;
        }
        mi cur2 = x.first + b.first * vals[0] - b.first * vals[1];
        if (b.second.count(H - cur2)) {
          vector<int> ans1 = x.second, ans2 = b.second[H - cur2];
          ans2[b.first - (1 << (K - 1)) - 1] = 1;
          for (auto& c : ans1) cout << c << " ";
          for (auto& c : ans2) cout << c << " ";
          return;
        }
      }
    }
  }
  cout << -1 << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
