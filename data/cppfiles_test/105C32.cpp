#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 5;
vector<tuple<int, int, int>> v[2 * mxN];
void testCase() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), c(n);
  vector<int> ansx(n), ansy(n);
  set<int> chk;
  for (int i = 0; i < n; i++) {
    int a, b, m;
    cin >> a >> b >> m;
    x[i] = a;
    y[i] = b;
    c[i] = m;
    int t = min(a, m);
    int nt = min(b, m);
    a -= t;
    m -= t;
    ansx[i] = t;
    b -= m;
    ansy[i] = m;
    int line = a + b;
    chk.insert(line);
    v[line].push_back({y[i] - nt, b, i});
  }
  int ans = 0;
  for (int line : chk) {
    sort(v[line].begin(), v[line].end(),
         [&](tuple<int, int, int> a, tuple<int, int, int> b) {
           return get<1>(a) < get<1>(b);
         });
    int cur = -1;
    int sz = v[line].size();
    for (int i = 0; i < sz; i++) {
      int l = get<0>(v[line][i]);
      int r = get<1>(v[line][i]);
      if (cur < l) {
        ans++;
        cur = r;
      }
      int id = get<2>(v[line][i]);
      int dif = r - cur;
      ansx[id] -= dif;
      ansy[id] += dif;
    }
    v[line].clear();
    v[line].shrink_to_fit();
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << ansx[i] << " " << ansy[i] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}
