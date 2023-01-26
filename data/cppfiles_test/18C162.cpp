#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const long long mod = 1000 * 1000 * 1000 + 7;
int Inf = (int)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> s;
  vector<bool> used(2 * n);
  int x, y;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    x--;
    y--;
    s.push_back({min(x, y), max(x, y)});
    used[x] = 1;
    used[y] = 1;
  }
  vector<int> can;
  for (int(i) = 0; (i) < 2 * n; (i)++)
    if (!used[i]) can.push_back(i);
  int t = can.size();
  t /= 2;
  for (int i = 0; i < t; i++) {
    s.push_back({can[i], can[i + t]});
  }
  int ans = 0;
  for (int(i) = 0; (i) < s.size(); (i)++) {
    x = s[i].first;
    y = s[i].second;
    for (int j = i + 1; j < s.size(); j++) {
      int xx = s[j].first;
      int yy = s[j].second;
      if (xx > x && yy > y && xx < y)
        ans++;
      else if (xx < x && yy < y && yy > x)
        ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
