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
  vector<pair<int, int> > queries;
  while (q--) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      queries.push_back({x, -1});
    } else {
      int x, y;
      cin >> x >> y;
      queries.push_back({x, y});
    }
  }
  reverse((queries).begin(), (queries).end());
  0;
  vector<int> ans;
  map<int, int> final;
  for (auto x : queries) {
    if (x.second == -1) {
      if (final.find(x.first) == final.end())
        ans.push_back(x.first);
      else
        ans.push_back(final[x.first]);
    } else {
      if (final.find(x.second) == final.end())
        final[x.first] = x.second;
      else
        final[x.first] = final[x.second];
    }
  }
  reverse((ans).begin(), (ans).end());
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
