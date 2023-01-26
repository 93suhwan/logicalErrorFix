#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int a[MAXN * MAXN], bit[MAXN * MAXN], x[MAXN][MAXN], n, m;
pair<int, int> b[MAXN * MAXN];
int baris(int x) { return (x + m - 1) / m; }
void update(int now, int val) {
  for (int i = now; i <= n * m; i += (i & (-i))) bit[i] += val;
}
int query(int now) {
  int ret = 0;
  for (int i = now; i > 0; i -= (i & (-i))) ret += bit[i];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
      cin >> a[i];
      b[i] = {a[i], i};
    }
    sort(b + 1, b + n * m + 1);
    int last = 1;
    for (int i = 1; i <= n * m; i++) {
      if (i == n * m || b[i].first != b[i + 1].first) {
        vector<int> v;
        int last2 = last;
        for (int j = last; j <= i; j++) {
          v.push_back(b[j].second);
          if (j == i || baris(j) != baris(j + 1)) {
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            for (int k = last2; k <= j; k++) {
              int col = k - (baris(k) - 1) * m;
              x[baris(k)][col] = v[k - last2];
            }
            last2 = j + 1;
            v.clear();
          }
        }
        last = i + 1;
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans += query(x[i][j] - 1);
        update(x[i][j], 1);
      }
      for (int j = 1; j <= m; j++) {
        update(x[i][j], -1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
