#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
const long long large = 2000000000000000000LL;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a;
    for (int i = 0; i < n * m; i++) {
      int x;
      cin >> x;
      a.push_back(pair<int, int>(x, i));
    }
    sort(a.begin(), a.end());
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    vector<pair<int, int> > b;
    for (int i = 0; i < n; i++) {
      int f = i * m;
      int en = (i + 1) * m;
      if (a[f].second == a[en - 1].second) continue;
      for (int j = f; j < en; j++) b.push_back(a[j]);
    }
    n = b.size() / m;
    for (int i = 0; i < n; i++) {
      int f = i * m;
      int en = (i + 1) * m;
      int p = f;
      while (p < en) {
        int pp = p;
        while (pp < en && b[p].first == b[pp].first) pp++;
        reverse(b.begin() + p, b.begin() + pp);
        p = pp;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int f = i * m;
      int en = (i + 1) * m;
      for (int j = f; j < en; j++) {
        for (int k = f; k < j; k++) {
          if (b[k].second < b[j].second) ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
