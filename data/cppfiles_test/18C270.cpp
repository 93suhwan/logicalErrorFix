#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "    ";
  err(++it, args...);
}
const int MOD = 1e9 + 7;
template <typename T>
struct SegTree {
  const T ID = 0;
  int n;
  vector<T> seg;
  SegTree(int _n) { n = _n, seg.assign(2 * n, ID); }
  T comb(T a, T b) { return a + b; }
  void update(int ind, T val) {
    for (seg[ind += n] = val; ind >>= 1;)
      seg[ind] = comb(seg[ind << 1], seg[ind << 1 | 1]);
  }
  T query(int l, int r) {
    if (l == r) return 0;
    T resl = ID, resr = ID;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = comb(resl, seg[l++]);
      if (r & 1) resr = comb(seg[--r], resr);
    }
    return comb(resl, resr);
  }
};
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v;
  set<int> st;
  for (int i = 1; i <= 2 * n; i++) st.insert(i);
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    v.push_back({x, y});
    st.erase(x);
    st.erase(y);
  }
  vector<int> temp;
  for (auto i : st) temp.push_back(i);
  sort(temp.begin(), temp.end());
  for (int i = 0; i < n - k; i++) {
    v.push_back({temp[i], temp[i + n - k]});
  }
  sort(v.begin(), v.end());
  SegTree<int> S(2 * n);
  int ans = 0;
  for (auto pt : v) {
    int x = pt.first, y = pt.second;
    x--;
    y--;
    ans += S.query(x + 1, y);
    S.update(x, 1);
    S.update(y, 1);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt;
  cin >> tt;
  while (tt--) solve();
}
