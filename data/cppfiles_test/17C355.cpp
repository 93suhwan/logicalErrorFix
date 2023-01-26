#include <bits/stdc++.h>
using namespace std;
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(const pair<A, B>& p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0) res += ", ";
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
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 50004;
const int A = 5;
int n;
vector<int> arr[N];
bool lessThan(vector<int>& a, vector<int>& b) {
  int r = 0;
  for (int i = 0; i < A; i++) {
    r += a[i] < b[i];
  }
  return r >= 3;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    arr[i].clear();
    arr[i].resize(A + 1);
    for (int j = 0; j < A; j++) {
      cin >> arr[i][j];
    }
    arr[i][A] = i;
  }
  int idx = 0;
  for (int i = 1; i < n; i++) {
    if (lessThan(arr[i], arr[idx])) {
      idx = i;
    }
  }
  bool good = true;
  for (int i = 0; i < n; i++) {
    if (idx != i) {
      good &= lessThan(arr[idx], arr[i]);
    }
  }
  if (good) {
    cout << idx + 1 << '\n';
  } else {
    cout << -1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
