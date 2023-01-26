#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mod1 = 998244353;
template <class T>
bool cmn(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool cmx(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
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
  for (size_t i = 0; i < N; i++) {
    res.push_back(static_cast<char>('0' + v[i]));
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
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
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(pair<int, int>(a[i], i));
  }
  sort((v).rbegin(), (v).rend());
  string s;
  cin >> s;
  vector<long long> ans(n, 0);
  int val = n, val1 = n - count(s.begin(), s.end(), '1');
  for (int i = 0; i < n; i++) {
    if (s[v[i].second] == '1') {
      ans[v[i].second] = val;
      val--;
    } else {
      ans[v[i].second] = val1;
      val1--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
