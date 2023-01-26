#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, d, mn[1000010], ans = 0;
pair<int, int> suf[500010];
vector<pair<int, int> > all, a, b, bb;
vector<int> dsc;
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  cin >> n >> d;
  int x, y;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    if (x < d) continue;
    all.push_back(make_pair(x, y));
    dsc.push_back(x);
    dsc.push_back(y);
  }
  dsc.push_back(d);
  sort(dsc.begin(), dsc.end());
  dsc.erase(unique(dsc.begin(), dsc.end()), dsc.end());
  for (int i = 0; i < all.size(); ++i) {
    all[i].first =
        lower_bound(dsc.begin(), dsc.end(), all[i].first) - dsc.begin();
    all[i].second =
        lower_bound(dsc.begin(), dsc.end(), all[i].second) - dsc.begin();
    if (all[i].first >= all[i].second)
      a.push_back(all[i]);
    else
      b.push_back(all[i]);
  }
  d = lower_bound(dsc.begin(), dsc.end(), d) - dsc.begin();
  for (int i = 0; i < dsc.size() + 5; ++i) mn[i] = 1e9;
  for (int i = 0; i < a.size(); ++i)
    if (a[i].second > 0) chmin(mn[a[i].second - 1], a[i].first);
  for (int i = dsc.size() - 2; i >= 0; --i) chmin(mn[i], mn[i + 1]);
  for (int i = 0; i < b.size(); ++i)
    if (b[i].second <= mn[b[i].first]) bb.push_back(b[i]);
  sort(bb.begin(), bb.end());
  suf[bb.size()] = make_pair(1e9, 1e9);
  for (int i = (int)(bb.size()) - 1; i >= 0; --i)
    suf[i] = min(suf[i + 1], make_pair(bb[i].second, i));
  ans = a.size();
  int cur = 0;
  while (true) {
    while (cur < bb.size() && bb[cur].first < d) ++cur;
    if (cur == bb.size()) break;
    ++ans;
    d = max(d, suf[cur].first);
    cur = suf[cur].second + 1;
  }
  cout << ans << endl;
  return 0;
}
