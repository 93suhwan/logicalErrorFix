#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1000000000000000000LL;
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
  for (auto val : vec) out << val << " ";
  return out;
}
void debug_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int N = 1e5 + 5;
template <class T>
struct Seg {
  T ID1 = 0, ID2 = 1000000007;
  T c1(T a, T b) { return max(a, b); }
  T c2(T a, T b) { return min(a, b); }
  vector<T> seg1, seg2;
  int n;
  void init(int _n) {
    n = _n;
    seg1.assign(2 * n, ID1);
    seg2.assign(2 * n, ID2);
  }
  void pull(int p) {
    seg1[p] = c1(seg1[2 * p], seg1[2 * p + 1]);
    seg2[p] = c2(seg2[2 * p], seg2[2 * p + 1]);
  }
  void upd(int p, T v) {
    p += n;
    seg1[p] = v;
    seg2[p] = v;
    for (p /= 2; p; p /= 2) pull(p);
  }
  T q1(int l, int r) {
    T ra = ID1, rb = ID1;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) ra = c1(ra, seg1[l++]);
      if (r & 1) rb = c1(seg1[--r], rb);
    }
    return c1(ra, rb);
  }
  T q2(int l, int r) {
    T ra = ID2, rb = ID2;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) ra = c2(ra, seg2[l++]);
      if (r & 1) rb = c2(seg2[--r], rb);
    }
    return c2(ra, rb);
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  int a[N], b[N], c[N];
  c[0] = 0;
  for (int x = 1; x <= n; x++) cin >> a[x];
  for (int x = 1; x <= n; x++) cin >> b[x], c[x] = c[x - 1] + b[x] - a[x];
  Seg<int> st;
  st.init(N);
  for (int x = 1; x <= n; x++) st.upd(x, c[x]);
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = st.q1(l, r) - c[l - 1];
    if (c[r] - c[l - 1] != 0 or st.q2(l, r) - c[l - 1] < 0) ans = -1;
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t_c = 1;
  for (int x = 1; x <= t_c; x++) {
    solve();
  }
  return 0;
}
