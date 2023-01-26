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
  long long n, m;
  cin >> n >> m;
  vector<long long> x(n);
  cin >> x;
  vector<string> s(n);
  cin >> s;
  vector<long long> ans(m);
  long long ansv = -1;
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<long long> cnt(m, 0);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (s[j][k] == '1') cnt[k] += 2 * ((mask & (1 << j)) > 0) - 1;
      }
    }
    vector<long long> vec(m);
    iota(vec.begin(), vec.end(), 0);
    sort(vec.begin(), vec.end(), [&](const long long &a, const long long &b) {
      return cnt[a] < cnt[b];
    });
    vector<long long> q(m);
    for (int i = 0; i < m; i++) {
      q[vec[i]] = i;
    }
    bool flag = 0;
    long long tempans = 0;
    for (int j = 0; j < n; j++) {
      long long sm = 0;
      for (int k = 0; k < m; k++) {
        if (s[j][k] == '1') sm += q[k] + 1;
      }
      if (mask & (1 << j)) {
        if (sm < x[j]) {
          flag = 1;
          break;
        }
        tempans += sm - x[j];
      } else {
        if (sm > x[j]) {
          flag = 1;
          break;
        }
        tempans += x[j] - sm;
      }
    }
    if (flag) continue;
    if (ansv < tempans) {
      ansv = tempans;
      ans = q;
    }
  }
  for (long long x : ans) cout << ++x << ' ';
  cout << "\n";
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
