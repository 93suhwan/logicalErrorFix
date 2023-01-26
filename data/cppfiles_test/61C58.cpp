#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
void solve() {
  long long n;
  cin >> n;
  unordered_map<long long, vector<long long>> topc_diff;
  unordered_map<long long, vector<long long>> diff_topc;
  for (int i = 0; i < n; i++) {
    long long t1, t2;
    cin >> t1;
    cin >> t2;
    topc_diff[t1].push_back(t2);
    diff_topc[t2].push_back(t1);
  }
  long long total = (n * (n - 1) * (n - 2)) / 6, ans = 0;
  for (auto &topc : topc_diff) {
    long long temp1 = topc.second.size() - 1;
    for (long long diff : topc.second) {
      long long temp2 = diff_topc[diff].size() - 1;
      ans += temp1 * temp2;
    }
  }
  cout << total - ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
