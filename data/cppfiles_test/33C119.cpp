#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1e18 + 18;
const long long MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) {
  return s << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
istream &operator>>(istream &i, vector<T> &v) {
  for (long long j = (0); j < (v.size()); j++) i >> v[j];
  return i;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1) s << "	";
  }
  return s;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<vector<T>> &vv) {
  s << '\n';
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << '\n';
  }
  return s;
}
int solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  long long mx = 701;
  vector<long long> dp(mx + 1, INF);
  dp[0] = 0;
  for (long long i = (0); i < (n); i++) {
    vector<long long> pre(mx + 1, INF);
    swap(pre, dp);
    for (long long j = (0); j < (mx + 1); j++) {
      long long v = a[i];
      if (pre[j] < v) {
        if ((j ^ v) <= 701) {
          chmin(dp[j ^ v], v);
        }
      }
      chmin(dp[j], pre[j]);
    }
  }
  vector<long long> ans;
  for (long long i = (0); i < (mx); i++) {
    if (dp[i] != INF) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (long long i = (0); i < (ans.size()); i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);
  solve();
}
