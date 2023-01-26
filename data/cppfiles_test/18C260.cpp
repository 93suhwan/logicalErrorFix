#include <bits/stdc++.h>
using namespace std;
void rozw() {
  int n, k;
  cin >> n >> k;
  vector<bool> vis(2 * n + 1);
  vector<pair<int, int>> v;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    vis[x] = 1;
    vis[y] = 1;
    v.push_back(make_pair(x, y));
  }
  vector<int> u;
  for (int i = 1; i < 2 * n + 1; i++) {
    if (!vis[i]) u.push_back(i);
  }
  for (int i = 0; i < u.size() / 2; i++) {
    v.push_back(make_pair(u[i], u[i + (u.size() / 2)]));
  }
  long long ans = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v.size(); j++) {
      if (v[i].first < v[j].first and v[j].first < v[i].second and
          v[i].second < v[j].second)
        ans++;
      if (v[j].first < v[i].first and v[i].first < v[j].second and
          v[j].second < v[i].second)
        ans++;
    }
  }
  cout << ans / 2 << '\n';
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int Z;
  cin >> Z;
  while (Z--) rozw();
}
