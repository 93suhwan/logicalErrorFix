#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (ll i = (0); i < (int((v).size())); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res;
  for (ll i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void dbgOut() { cerr << "]" << endl; }
template <typename H, typename... T>
void dbgOut(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  dbgOut(t...);
}
void solve() {
  int q;
  cin >> q;
  map<int, vector<vector<int>>> m;
  int idx = 0, n = 0;
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      ++n;
      int k;
      cin >> k;
      m[k].push_back({idx++});
    } else {
      int k1, k2;
      cin >> k1 >> k2;
      if (int((m[k1]).size()) == 0) {
        continue;
      }
      auto it = m.find(k1);
      m[k2].insert(m[k2].end(), it->second.begin(), it->second.end());
      m.erase(it);
    }
    0;
  }
  vector<int> ans(n);
  for (auto& x : m) {
    for (auto& y : x.second) {
      ans[y[0]] = x.first;
    }
  }
  for (auto& x : ans) {
    cout << x << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
