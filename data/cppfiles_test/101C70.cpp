#include <bits/stdc++.h>
using namespace std;
int e[1000005];
int first[1000005], second[1000005];
pair<int, int> a[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int k, n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> first[i];
    for (int i = 1; i <= m; ++i) cin >> second[i];
    for (int i = 1; i <= k; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + k + 1);
    int j = 1;
    long long res = 0;
    for (int i = 1; i < n; ++i) {
      int sl = 0;
      while (j <= k && a[j].first >= first[i] && a[j].first <= first[i + 1]) {
        if (a[j].first > first[i] && a[j].first < first[i + 1])
          e[++sl] = a[j].second;
        ++j;
      }
      sort(e + 1, e + sl + 1);
      long long cnt = (long long)sl * (sl - 1) / 2, o = 1;
      for (int z = 1; z <= sl; ++z) {
        if (z == sl || e[z] != e[z + 1]) {
          cnt -= o * (o - 1) / 2;
          o = 1;
        } else
          o++;
      }
      res += cnt;
    }
    for (int i = 1; i <= k; ++i) {
      swap(a[i].first, a[i].second);
    }
    sort(a + 1, a + k + 1);
    j = 1;
    for (int i = 1; i < m; ++i) {
      int sl = 0;
      while (j <= k && a[j].first >= second[i] && a[j].first <= second[i + 1]) {
        if (a[j].first > second[i] && a[j].first < second[i + 1])
          e[++sl] = a[j].second;
        ++j;
      }
      sort(e + 1, e + sl + 1);
      long long cnt = (long long)sl * (sl - 1) / 2, o = 1;
      for (int z = 1; z <= sl; ++z) {
        if (z == sl || e[z] != e[z + 1]) {
          cnt -= o * (o - 1) / 2;
          o = 1;
        } else
          o++;
      }
      res += cnt;
    }
    cout << res << endl;
  }
}
