#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = (ll)1e9 + 7;
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <typename XPAX>
bool ckma(XPAX &x, XPAX y) {
  return (x < y ? x = y, 1 : 0);
}
template <typename XPAX>
bool ckmi(XPAX &x, XPAX y) {
  return (x > y ? x = y, 1 : 0);
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  int n;
  cin >> n;
  V<int> a(n);
  V<int> cnt(n + 1);
  for (int &c : a) cin >> c, cnt[c]++;
  V<int> ans(n + 1);
  int sm = 0;
  map<int, int> sp;
  int bf = INF;
  for (int i = 0; i <= n; ++i) {
    ans[i] += cnt[i];
    if (i < n) {
      while ((int)sp.size() && sp.rbegin()->second <= 0)
        sp.erase(sp.rbegin()->first);
      if (!cnt[i]) {
        if (!(int)sp.size())
          ckmi(bf, i + 1);
        else {
          int x = sp.rbegin()->first;
          assert(sp[x] > 0);
          sm += i - x;
          cnt[i]++;
          sp[x] -= 1;
        }
      }
      ans[i + 1] = sm;
    }
    if (cnt[i] > 1) sp[i] += cnt[i] - 1;
  }
  for (int i = bf; i <= n; ++i) ans[i] = -1;
  for (auto c : ans) cout << c << ' ';
  cout << '\n';
}
void test_case() {
  int t;
  cin >> t;
  for (int p = 0; p < (t); ++p) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test_case();
}
