#include <bits/stdc++.h>
using namespace std;
const long double PI = acosl(-1);
struct FenwickTree {
  vector<int> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  int sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  int sum(int l, int r) { return sum(r) - sum(l); }
  void add(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    map<int, int> sight;
    for (int i = 0; i < n * m; i++) {
      cin >> a[i].second;
      a[i].first = i + 1;
      sight[a[i].first] = a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
      if (a.second != b.second) return b.second > a.second;
      return a.first < b.first;
    });
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int st = sight[a[i * m].first];
      int s = i * m, e = i * m;
      for (int j = 1; j < m; j++) {
        int nst = sight[a[i * m + j].first];
        if (nst == st)
          e++;
        else {
          reverse(a.begin() + s, a.begin() + e + 1);
          st = nst;
          s = e = i * m + j;
        }
      }
      reverse(a.begin() + s, a.begin() + e + 1);
    }
    for (int i = 0; i < n * m; i++) a[i].second = i + 1;
    sort(a.begin(), a.end());
    FenwickTree tree = FenwickTree(n * m + 1);
    for (int i = 0; i < n * m; i++) {
      int seat = a[i].second;
      int row = ((seat - 1) / m) + 1;
      int prevRowLastSeat = (row - 1) * m;
      ans += tree.sum(prevRowLastSeat, seat - 1);
      tree.add(seat, 1);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
