#include <bits/stdc++.h>
using namespace std;
void setIO(const string &name = "") {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (name.length()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
template <typename T>
void read(vector<T> &a) {
  for (auto &x : a) cin >> x;
}
template <typename T>
void read(vector<T> &a, int n) {
  a.resize(n);
  for (auto &x : a) cin >> x;
}
template <class T, class U>
ostream &operator<<(ostream &out, const pair<T, U> &v) {
  out << "(";
  out << v.first << "," << v.second;
  return out << ")";
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (auto(i) = 0; (i) < ((int)(v).size()); (i)++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
template <typename T>
void print(vector<T> &a) {
  for (const auto &x : a) cout << x << ' ';
  cout << '\n';
}
void MOD(int &x, int m = 1000000007) {
  x %= m;
  if (x < 0) x += m;
}
void MOD(int64_t &x, int m = 1000000007) {
  x %= m;
  if (x < 0) x += m;
}
template <typename T>
void dbg(const char *name, T &&arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename T, typename... U>
void dbg(const char *names, T &&arg1, U &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  dbg(comma + 1, args...);
}
template <class T>
void read(T &x) {
  cin >> x;
}
template <class T, class... U>
void read(T &t, U &...u) {
  read(t);
  read(u...);
}
int gcd(int a, int b) { return !a ? b : gcd(b % a, a); }
using ll = int64_t;
int n;
vector<int> a;
vector<int> cnt;
void solve() {
  read(n);
  read(a, n);
  cnt.assign(31, 0);
  for (auto(i) = 0; (i) < (31); (i)++) {
    for (auto(j) = 0; (j) < (n); (j)++) {
      if ((1 << i) & a[j]) {
        cnt[i]++;
      }
    }
  }
  int g = 0;
  for (auto(i) = 0; (i) < (n); (i)++) {
    g = gcd(cnt[i], g);
  }
  if (g == 0) {
    for (auto(i) = 1; (i) < (n + 1); (i)++) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  set<int> s;
  for (int i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      s.insert(i);
      s.insert(g / i);
    }
  }
  for (auto &(c) : (s)) {
    cout << c << ' ';
  }
  cout << '\n';
}
int32_t main() {
  setIO();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
