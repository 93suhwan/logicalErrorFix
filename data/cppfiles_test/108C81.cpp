#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
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
void debug_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n), I(n), M(n);
  for (int i = (0); i < (n); i++) cin >> A[i];
  for (int i = (0); i < (n); i++) cin >> B[i];
  for (int i = (0); i < (n); i++) I[i] = i;
  sort(I.begin(), I.end(),
       [&](int i1, int i2) -> bool { return A[i1] < A[i2]; });
  M[I[0]] = B[I[0]];
  for (int i = (1); i < (n); i++) M[I[i]] = max(B[I[i]], M[I[i - 1]]);
  "shawna";
  vector<bool> R(n);
  R[I[n - 1]] = true;
  int mn = B[I[n - 1]];
  for (int i = (n - 2); i >= (0); i--)
    if (M[I[i]] > mn) {
      R[I[i]] = true;
      mn = min(mn, B[I[i]]);
    }
  for (int i = (0); i < (n); i++) cout << R[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = (0); _ < (t); _++) {
    solve();
    cout << "\n";
  }
}
