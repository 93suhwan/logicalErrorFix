#include <bits/stdc++.h>
using namespace std;
int getnext(int a, int b, int c, int d) {
  vector<int> kek;
  if (b > a) kek.push_back(b);
  if (c > a) kek.push_back(c);
  if (d > a) kek.push_back(d);
  return *min_element(kek.begin(), kek.end());
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> arr(k);
  set<int> np;
  for (int i = 0; i < 2 * n; ++i) np.insert(i);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    arr[i] = {x, y};
    np.erase(x);
    np.erase(y);
  }
  vector<int> npp(np.size());
  int pp = 0;
  for (int i : np) npp[pp++] = i;
  pp = npp.size() / 2;
  for (int i = 0; i < pp; i++) {
    int j = (i + pp);
    arr.emplace_back(npp[i], npp[j]);
  }
  int ans = 0;
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = i + 1; j < arr.size(); ++j) {
      auto [x1, y1] = arr[i];
      auto [x2, y2] = arr[j];
      int nx = getnext(x1, y1, x2, y2);
      if (nx == y1) continue;
      int nx2 = getnext(x2, y2, x1, y1);
      if (nx2 == y2) continue;
      ans++;
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
