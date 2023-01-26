#include <bits/stdc++.h>
using namespace std;
int t, n, tr, x;
map<int, int> vis;
vector<int> v, s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    tr = 0;
    v.clear();
    s.clear();
    vis.clear();
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x <= n and !vis[x])
        vis[x] = 1;
      else
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
      if (!vis[i]) s.push_back(i);
    for (int i = 0; i < s.size(); i++)
      if (s[i] * 2 >= v[i]) tr = 1;
    if (!tr)
      cout << v.size();
    else
      cout << -1;
    cout << "\n";
  }
}
