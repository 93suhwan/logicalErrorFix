#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int a[N];
int vis[N];
vector<pair<int, int> > v;
int check(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) swap(a, b);
  return a.second < b.second && b.first < a.second;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    v.clear();
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= k; i++) {
      int first, second;
      cin >> first >> second;
      if (first > second) swap(first, second);
      vis[first] = 1, vis[second] = 1;
      v.push_back({first, second});
    }
    int cnt = 1;
    for (int i = 1; i <= 2 * n; i++)
      if (!vis[i]) a[cnt++] = i;
    for (int i = 1; i <= n - k; i++) v.push_back({a[i], a[i + n - k]});
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (check(v[i], v[j])) ans++;
    cout << ans << endl;
  }
}
