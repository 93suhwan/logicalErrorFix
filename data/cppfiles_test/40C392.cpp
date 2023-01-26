#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int lim = 1e6;
bool check(int elem) { return true; }
void bsearch() {
  int lo = 0, hi = 1e9, res = -1, mid;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      res = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
}
struct Node {};
struct Compare {
  bool operator()(const Node &a, const Node &b) { return true; }
};
bool compare(const Node &a, const Node &b) { return true; }
void pre_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int32_t main() {
  pre_io();
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int pref[2][n + 2], v[2][n + 1];
    for (int i = 0; i < n; i++) cin >> v[0][i];
    for (int i = 0; i < n; i++) cin >> v[1][i];
    pref[0][n + 1] = 0;
    for (int i = n; i >= 1; i--) pref[0][i] = pref[0][i + 1] + v[0][i - 1];
    pref[1][0] = 0;
    for (int i = 1; i <= n; i++) pref[1][i] = pref[1][i - 1] + v[1][i - 1];
    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
      res = min(res, max(pref[1][i - 1], pref[0][i + 1]));
    }
    cout << res << "\n";
  }
}
