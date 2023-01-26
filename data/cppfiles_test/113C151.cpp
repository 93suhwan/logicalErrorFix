#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
string to_string(pair<T1, T2> p);
template <typename T1, typename T2, typename T3>
string to_string(tuple<T1, T2, T3> tup);
template <typename T1, typename T2, typename T3, typename T4>
string to_string(tuple<T1, T2, T3, T4> tup);
string to_string(const string& v) { return "{" + v + "}"; }
string to_string(const char* v) { return to_string((string)v); }
string to_string(const bool& v) { return (v ? "True" : "False"); }
string to_string(vector<bool> v) {
  string ret = "[";
  int n = (int)v.size();
  for (int i = 0; i < n - 1; i++) {
    ret += "[" + to_string(i) + "](" + to_string(v[i]) + "), ";
  }
  ret += "[" + to_string(n - 1) + "](" + to_string(v[n - 1]) + ")]";
  return ret;
}
template <size_t N>
string to_string(bitset<N> b) {
  string ret = "";
  for (int i = 0; i < N; i++) {
    ret += (char)(b[i] + '0');
  }
  return ret;
}
template <typename T>
string to_string(T v) {
  bool ok = true;
  string ret = "[";
  int cnt = 0;
  for (auto x : v) {
    if (!ok) {
      ret += ", ";
    }
    ok = false;
    ret += "[" + to_string(cnt++) + "](" + to_string(x) + ")";
  }
  return ret + "]";
}
template <typename T1, typename T2>
string to_string(pair<T1, T2> p) {
  return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}
template <typename T1, typename T2, typename T3>
string to_string(tuple<T1, T2, T3> tup) {
  return "{" + to_string(get<0>(tup)) + ", " + to_string(get<1>(tup)) + ", " +
         to_string(get<2>(tup)) + "}";
}
template <typename T1, typename T2, typename T3, typename T4>
string to_string(tuple<T1, T2, T3, T4> tup) {
  return "{" + to_string(get<0>(tup)) + ", " + to_string(get<1>(tup)) + ", " +
         to_string(get<2>(tup)) + ", " + to_string(get<3>(tup)) + "}";
}
void DEBUG() { cerr << '\n'; }
template <typename start, typename... end>
void DEBUG(start first, end... other) {
  cerr << " | " << to_string(first);
  DEBUG(other...);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  long long m;
  cin >> m;
  long long x, y;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    auto itr = lower_bound(a.begin(), a.end(), x);
    if (itr == a.end()) {
      cout << (x - a[n - 1]) + max((long long)0, y - (sum - a[n - 1])) << '\n';
    } else {
      long long ans = max((long long)0, y - (sum - *itr));
      if (itr != a.begin()) {
        itr--;
        ans = min(ans, (x - *itr) + max((long long)0, y - (sum - *itr)));
      }
      cout << ans << '\n';
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
