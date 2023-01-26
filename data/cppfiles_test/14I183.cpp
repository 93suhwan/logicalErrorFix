#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &x : v) out << x << ' ';
  return out;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
const bool tests = 1;
void solve_case() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  cin >> a;
  a.insert(a.begin(), 0);
  vector<long long> len(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] > a[j] && i - a[i] >= j - a[j]) len[i] = max(len[i], len[j] + 1);
    }
  }
  long long ans = LLONG_MAX;
  for (int i = 0; i <= n; i++) {
    if (len[i] >= k) ans = min(ans, i - a[i]);
  }
  if (ans == LLONG_MAX) ans = -1;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long testcase = 1;
  if (tests) cin >> testcase;
  cout << fixed << setprecision(10);
  for (long long test = 1; test <= testcase; test++) {
    solve_case();
  }
  return 0;
}
