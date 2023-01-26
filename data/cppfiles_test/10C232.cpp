#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
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
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  map<int, vector<int>> ids;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ids[arr[i]].push_back(i);
  }
  vector<int> cols[k];
  vector<int> out(n);
  int cur{};
  for (auto &p : ids) {
    for (int i = 0; i < min((int)(p.second).size(), k); i++) {
      cols[cur].push_back(p.second[i]);
      cur = (cur + 1) % k;
    }
  }
  int mn = INT_MAX;
  for (auto &v : cols) mn = min(mn, (int)(v).size());
  for (int col = 0; col < k; col++) {
    if ((int)(cols[col]).size() > mn) {
      cols[col].pop_back();
    }
    for (int idx : cols[col]) {
      out[idx] = col + 1;
    }
  }
  for (int e : out) {
    cout << e << " ";
  }
  cout << '\n';
}
int main() {
  fastio();
  cout << setprecision(15) << fixed;
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
