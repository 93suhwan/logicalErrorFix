#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    int p[300];
    int vst[300] = {0};
    vector<pair<int, int> > ch;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      ch.push_back(make_pair(x, y));
      vst[x] = 1;
      vst[y] = 1;
    }
    int l = 1;
    for (int i = 1; i <= 2 * n; i++) {
      if (vst[i] == 0) {
        p[l] = i;
        l++;
      }
    }
    for (int i = 1; i <= n - k; i++) {
      int x = p[i], y = p[i + n - k];
      ch.push_back(make_pair(x, y));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = ch[i].first, y = ch[i].second;
        int p = ch[j].first, q = ch[j].second;
        if (x > y) {
          int c = x;
          x = y;
          y = c;
        }
        if (p > q) {
          int c = p;
          p = q;
          q = c;
        }
        if (x < p && p < y && y < q || p < x && x < q && q < y) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
