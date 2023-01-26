#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int father[N], a[N], b[N];
int getfather(int x) {
  return father[x] == x ? x : father[x] = getfather(father[x]);
}
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    father[i] = i;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] > i)
      mp[n - a[i] + i]++;
    else
      mp[i - a[i]]++;
  }
  vector<int> res, tp;
  for (auto i : mp) {
    if (i.second >= n - 2 * m) tp.push_back(i.first);
  }
  sort(tp.begin(), tp.end());
  tp.erase(unique(tp.begin(), tp.end()), tp.end());
  for (auto k : tp) {
    for (int i = 1; i <= n; ++i) {
      if (i <= k)
        b[i] = i + n - k;
      else
        b[i] = i - k;
    }
    init(n);
    for (int j = 1; j <= n; j++) father[getfather(a[j])] = getfather(b[j]);
    map<int, int> c;
    for (int j = 1; j <= n; j++) c[getfather(j)]++;
    int cnt = 0;
    for (auto x : c) cnt += x.second - 1;
    if (cnt <= m) res.push_back(k);
  }
  sort(res.begin(), res.end());
  cout << res.size() << " ";
  for (int i = 0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
