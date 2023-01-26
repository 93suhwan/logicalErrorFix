#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 998244353;
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
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first or (a.first == b.first and a.second <= b.second))
    return true;
  return false;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1 - arr[i].first;
  }
  vector<pair<long long, long long>> lis(1, {-1, 0});
  for (auto cur : arr) {
    if (cur.second == -1) continue;
    auto it = lower_bound(lis.begin(), lis.end(),
                          make_pair(cur.first + 1, cur.second));
    if (cur.second >= (it - 1)->second) {
      if (it == lis.end())
        lis.push_back(cur);
      else
        lis[it - lis.begin()] = cur;
    };
  }
  cout << lis.size() - 1;
}
int32_t main() {
  ios::sync_with_stdio(!cin.tie(NULL));
  solve();
}
