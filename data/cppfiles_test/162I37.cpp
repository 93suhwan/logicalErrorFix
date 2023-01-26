#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using PII = pair<long long, long long>;
using VI = vector<long long>;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const ll md = 1000000007;
long long n;
vector<long long> V;
bool check(long long mid) {
  VI W = V;
  for (int64_t i = (2), _b = (n - 1); i <= _b; ++i) {
    long long take = max(0LL, (mid - W[i - 2]) / 2);
    if (take * 2 + W[i - 2] < mid) {
      take++;
    }
    if (take * 3 > W[i]) {
      return false;
    }
    W[i] -= take * 3;
    W[i - 1] += take;
    W[i - 2] += take * 2;
    take = max(0LL, (mid - W[i - 1]));
    if (take * 3 > W[i]) {
      take = W[i] / 3;
    }
    W[i] -= take * 3;
    W[i - 1] += take;
    W[i - 2] += take * 2;
  }
  for (long long _n = n, i = 0; i < _n; ++i) {
    if (W[i] < mid) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  V.resize(n);
  long long mx = 0;
  for (long long _n = n, i = 0; i < _n; ++i) {
    cin >> V[i];
    mx = max(mx, V[i]);
  }
  long long l = 1, r = mx;
  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (check(r)) {
    cout << r << "\n";
  } else {
    cout << l << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
