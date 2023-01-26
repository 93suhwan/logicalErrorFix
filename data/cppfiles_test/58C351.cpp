#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MM = 998244353;
const long long inf = LLONG_MAX;
const long long dif = LLONG_MIN;
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v);
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << p.first << " " << p.second;
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  for (long long i = 0; i < (long long)((v).size()); ++i) {
    cout << v[i] << " ";
  }
  return cout << "\n";
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p) {
  cin >> p.first;
  return cin >> p.second;
}
template <typename A>
istream& operator>>(istream& cin, vector<A>& v) {
  for (auto& x : v) cin >> x;
  return cin;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long i = 0; i < static_cast<long long>(v.size()); ++i) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; ++i) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void dbg_out() { cout << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  dbg_out(T...);
}
void solve() {
  long long n;
  string a, b;
  cin >> n >> a >> b;
  bool safe = 1;
  for (long long i = 0; i < n; ++i) {
    if (a[i] == '1' and a[i] == b[i]) {
      safe = 0;
      break;
    }
  }
  cout << (safe ? "YES\n" : "NO\n");
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) solve();
}
