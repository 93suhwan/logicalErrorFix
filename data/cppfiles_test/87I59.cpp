#include <bits/stdc++.h>
using namespace std;
const int eps = 998244353;
const int N = 5e2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int a[m + 1];
    bool vis[m + 1];
    for (int i = 1; i <= m; i++) vis[i] = 0;
    vector<int> v, w;
    for (int i = 1; i <= m; i++) {
      cin >> a[i];
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= m; i++) {
      int x = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
      if (!vis[x]) {
        w.push_back(x);
        ans += lower_bound(w.begin(), w.end(), x) - w.begin();
        vis[x] = 1;
      } else {
        w.push_back(x + 1);
        ans += lower_bound(w.begin(), w.end(), x) - w.begin();
        vis[x + 1] = 1;
      }
    }
    cout << ans << endl;
  }
}
