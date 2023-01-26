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
  for (int i = (0); i < (int((v).size())); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res;
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  string s;
  cin >> s;
  vector<int> red, blu;
  for (int i = (0); i < (n); ++i) {
    if (s[i] == 'R') {
      red.push_back(a[i]);
    } else {
      blu.push_back(a[i]);
    }
  }
  int r = int((red).size()), b = int((blu).size());
  sort((red).begin(), (red).end());
  sort((blu).begin(), (blu).end());
  int rr(0), bb(0);
  for (int i = (0); i < (n); ++i) {
    bool op1 = 0, op2 = 0;
    while (bb < b) {
      if (blu[bb] >= i + 1) {
        op1 = 1;
      }
      ++bb;
      if (op1) break;
    }
    if (op1) continue;
    while (rr < r) {
      if (red[rr] <= i + 1) {
        op2 = 1;
      }
      ++rr;
      if (op2) break;
    }
    if (op2) continue;
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tn = (0); tn < (tc); ++tn) solve();
}
