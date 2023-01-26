#include <bits/stdc++.h>
using namespace std;
int x[10], re[10001], anss[10001];
string s[10];
pair<int, int> h[10001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = INT_MIN;
    for (int bm = 0; bm < (1 << n); bm++) {
      for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          if (s[j][i - 1] == '1') {
            if ((bm >> j) & 1)
              cnt++;
            else
              cnt--;
          }
        }
        h[i] = make_pair(cnt, i);
      }
      int t = 0;
      for (int i = 0; i < n; i++) t += ((bm >> i) & 1 ? -1 : 1) * x[i];
      sort(h + 1, h + m + 1);
      for (int i = 1; i <= m; i++) t += h[i].first * i;
      if (t > ans) {
        ans = t;
        for (int i = 1; i <= m; i++) anss[h[i].second] = i;
      }
    }
    for (int i = 1; i <= m; i++) cout << anss[i] << ' ';
    cout << '\n';
  }
  return 0;
}
