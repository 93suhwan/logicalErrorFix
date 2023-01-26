#include <bits/stdc++.h>
using namespace std;
struct node {
  int idx, val;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n, m, mid = 0x3f3f3f3f, big = 0;
    cin >> n >> m;
    vector<vector<node>> arr(n, vector<node>(m));
    string ans(n, 'B');
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != m; ++j) cin >> arr[i][j].val, arr[i][j].idx = j;
      sort(arr[i].begin(), arr[i].end(),
           [](const node& lhs, const node& rhs) { return lhs.val > rhs.val; });
      if (arr[i][0].val >= big) {
        big = arr[i][0].val;
        int bm = arr[i][0].idx;
        int j;
        for (j = 0; j != m && arr[i][j].val == arr[i][j + 1].val;
             bm = max(bm, arr[i][j++].idx))
          ;
        bm = max(bm, arr[i][j++].idx);
        mid = min(bm, mid);
      }
    }
    int need = 0;
    for (int i = 0; i != n; ++i) {
      if (arr[i][0].idx <= mid) ++need, ans[i] = 'R';
    }
    if (need != n) {
      cout << "YES\n";
      cout << ans << ' ' << mid + 1 << '\n';
    } else
      cout << "NO\n";
  }
}
