#include <bits/stdc++.h>
using namespace std;
class segment_tree {
  vector<long long> t;
  long size;

 public:
  segment_tree(long n) {
    if (1)
      t.assign(4 * n + 1, 0);
    else
      t.assign(4 * n + 1, (1LL << 60));
    size = n;
  }
  void initialize_array(vector<long long>& v) {
    initialize_with_array(1, 0, size - 1, v);
  }
  void initialize_with_array(long startpos, long l, long r,
                             vector<long long>& v) {
    if (l == r) {
      t[startpos] = v[l];
    } else {
      long m = (l + r) / 2;
      initialize_with_array(2 * startpos, l, m, v);
      initialize_with_array(2 * startpos + 1, m + 1, r, v);
      if (1 == 1)
        t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
      else
        t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
    }
  }
  void update(long index, long long val) {
    update_full(1, 0, size - 1, index, val);
  }
  void update_full(long startpos, long l, long r, long index, long long val) {
    if (l == r) {
      t[startpos] = val;
    } else {
      long m = (l + r) / 2;
      if (index <= m)
        update_full(2 * startpos, l, m, index, val);
      else
        update_full(2 * startpos + 1, m + 1, r, index, val);
      if (1)
        t[startpos] = max(t[startpos * 2], t[startpos * 2 + 1]);
      else
        t[startpos] = min(t[startpos * 2], t[startpos * 2 + 1]);
    }
  }
  long long query(long l, long r) {
    if (l > r) {
      if (1)
        return 0;
      else
        return (1LL << 60);
    }
    return query_full(1, 0, size - 1, l, r);
  }
  long long query_full(long startpos, long left, long right, long l, long r) {
    if ((left >= l) && (right <= r)) return t[startpos];
    long m = (left + right) / 2;
    long long ans;
    if (1)
      ans = -(1LL << 60);
    else
      ans = (1LL << 60);
    if (m >= l) {
      if (1)
        ans = max(ans, query_full(startpos * 2, left, m, l, r));
      else
        ans = min(ans, query_full(startpos * 2, left, m, l, r));
    }
    if (m + 1 <= r) {
      if (1)
        ans = max(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
      else
        ans = min(ans, query_full(startpos * 2 + 1, m + 1, right, l, r));
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int MAXX = 200100, n, i, j, k, ans, x;
  cin >> n;
  vector<int> a(n + 1), dp(n + 1, 0);
  vector<pair<int, int>> plist;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (i >= a[i]) plist.push_back({i - a[i], a[i]});
  }
  sort(plist.begin(), plist.end());
  segment_tree st(n + 1);
  ans = 0;
  for (auto p : plist) {
    x = st.query(0, p.second - 1);
    if (x + 1 > dp[p.second]) {
      dp[p.second] = x + 1;
      st.update(p.second, x + 1);
      ans = max(ans, x + 1);
    }
  }
  cout << ans << "\n";
  return 0;
}
