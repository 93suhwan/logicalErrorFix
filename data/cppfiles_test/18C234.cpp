#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[410], b[410], h[410];
int ans[410], aacnt;
vector<int> aa[410];
bool inter(pair<int, int> x, pair<int, int> y) {
  if (x.first > x.second) swap(x.first, x.second);
  if (y.first > y.second) swap(y.first, y.second);
  if (x > y) swap(x, y);
  if (x.second < y.first) return 0;
  if (x.second > y.second) return 0;
  if (x.second < y.second) return 1;
}
void solve() {
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  memset(h, 0, sizeof h);
  memset(ans, 0, sizeof ans);
  aacnt = 0;
  cin >> n >> m;
  for (int i = 1; i <= n + n; i++) aa[i].clear();
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i], h[a[i]]++, h[b[i]]++;
  int cnt = n - m, tot = 0;
  int i, j;
  for (i = 1, j = 1; i <= n + n && j <= cnt; i++, j++) {
    while (h[i]) i++;
    ans[i] = j;
  }
  for (j = 1; i <= n + n && j <= cnt; i++, j++) {
    while (h[i]) i++;
    ans[i] = j;
  }
  for (int i = 1; i <= n + n; i++)
    if (ans[i] != 0) aa[ans[i]].push_back(i), aacnt++;
  aacnt /= 2;
  for (int i = 1; i <= m; i++)
    aa[++aacnt].push_back(a[i]), aa[aacnt].push_back(b[i]);
  int ret = 0;
  for (int i = 1; i <= aacnt; i++)
    for (int j = i + 1; j <= aacnt; j++)
      if (inter(make_pair(aa[i][0], aa[i][1]), make_pair(aa[j][0], aa[j][1])))
        ret++;
  cout << ret << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
