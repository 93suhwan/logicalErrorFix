#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
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
    res += static_cast<char>('0' + v[i]);
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
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << "   "; }
void debug_out_nl() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename Head, typename... Tail>
void debug_out_nl(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out_nl(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long random(long long st, long long dr) {
  assert(st <= dr);
  return st + rng() % (dr - st + 1);
}
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int n, q;
string s;
void solve(int test, istream &cin, ostream &cout) {
  cin >> n >> q;
  cin >> s;
  vector<string> h = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<int> > v(6, vector<int>(n, 0));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = (j > 0 ? v[i][j - 1] : 0) + (s[j] != h[i][j % 3]);
    }
  }
  42;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int mn = INT_MAX;
    for (int i = 0; i < 6; i++) {
      mn = min(mn, v[i][r] - (l > 0 ? v[i][l - 1] : 0));
    }
    cout << mn << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  bool multiTest = false;
  int t;
  if (multiTest) {
    cin >> t;
  } else {
    t = 1;
  }
  for (int test = 1; test <= t; test++) {
    solve(test, cin, cout);
  }
  return 0;
}
