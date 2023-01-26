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
int n, m;
string s;
int k;
vector<pair<int, int> > pref;
bool valid_row(int x) { return x >= 0 and x < n; }
bool valid_col(int x) { return x >= 0 and x < m; }
void solve() {
  read(n, m);
  read(s);
  k = (int)(s).size();
  pref.assign(k + 1, {0, 0});
  for (auto(i) = 1; (i) < (k + 1); (i)++) {
    pref[i] = pref[i - 1];
    if (s[i - 1] == 'L') {
      pref[i].second--;
    } else if (s[i - 1] == 'R') {
      pref[i].second++;
    } else if (s[i - 1] == 'U') {
      pref[i].first--;
    } else {
      pref[i].first++;
    }
  }
  pair<int, int> ans = {0, 0}, cur;
  for (auto(i) = 0; (i) < (k + 1); (i)++) {
    if (pref[i].first < 0) {
      cur.first = abs(pref[i].first);
    } else {
      cur.first = n - pref[i].first - 1;
    }
    if (!valid_row(cur.first)) {
      continue;
    }
    if (pref[i].second < 0) {
      cur.second = abs(pref[i].second);
    } else {
      cur.second = m - pref[i].second - 1;
    }
    if (!valid_col(cur.second)) {
      continue;
    }
    ans = cur;
  }
  cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
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
