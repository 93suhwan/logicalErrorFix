#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(char x) { return (string) "\'" + x + "\'"; }
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
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
void debug_out() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H) << (sizeof...(T) != 0 ? ", " : "");
  debug_out(T...);
}
template <typename T>
void debug_out(T A[], long long SZ) {
  cerr << "{";
  for (long long i = 0; i < SZ; i++) cerr << A[i] << (i != SZ - 1 ? ", " : "");
  cerr << "}]\n";
}
const long long INF = (long long)2e18;
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long>> grid(m, vector<long long>(n));
  for (long long i = 0; i < m; i++)
    for (long long j = 0; j < n; j++) cin >> grid[i][j];
  auto isPossible = [&](long long val) {
    long long flag1 = true, flag2 = false;
    set<long long> st;
    for (long long j = 0; j < n; j++) {
      bool possible = false;
      for (long long i = 0; i < m; i++) {
        if (grid[i][j] >= val) {
          possible = true;
          if (st.find(i) != st.end()) {
            flag2 = true;
          }
          st.insert(i);
        }
      }
      flag1 &= possible;
    }
    return (flag1 && flag2);
  };
  long long s = 0, e = INF, res = s;
  while (s <= e) {
    long long mid = s + (e - s) / 2;
    if (isPossible(mid)) {
      res = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
