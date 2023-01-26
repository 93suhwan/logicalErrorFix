#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], dp[N], ww, ww1;
struct nod {
  int val;
  int idx;
  int x;
};
nod b[4 * N];
multiset<pair<int, int> >::iterator it;
multiset<pair<int, int> > ms[4 * N];
void upd(int node, pair<int, int> vall) {
  if (!ms[node].size()) {
    ms[node].insert(vall);
    return;
  }
  int abr = 0;
  it = ms[node].lower_bound({vall.first, 0});
  vector<pair<int, int> > vv;
  vv.clear();
  if (it != ms[node].begin()) {
    it--;
    while (true) {
      if ((*it).second <= vall.second)
        vv.push_back({(*it).first, (*it).second});
      else
        break;
      if (it == ms[node].begin()) break;
      it--;
    }
  }
  it = ms[node].lower_bound({vall.first, 0});
  while (true) {
    if (it == ms[node].end() || (*it).first > vall.first) break;
    if ((*it).second <= vall.second)
      vv.push_back({(*it).first, (*it).second});
    else
      break;
    it++;
  }
  for (int i = 0; i < vv.size(); i++) {
    pair<int, int> jj = {vv[i].first, vv[i].second};
    ms[node].erase(ms[node].find(jj));
  }
  ms[node].insert(vall);
}
void update(int node, int le, int ri, int idx, pair<int, int> vall) {
  if (le > idx || ri < idx) {
    return;
  }
  if (le == ri) {
    upd(node, vall);
    return;
  }
  int mid = (le + ri) / 2;
  if (idx <= mid)
    update(2 * node, le, mid, idx, vall);
  else
    update(2 * node + 1, mid + 1, ri, idx, vall);
  upd(node, vall);
}
int go(int node, int vall) {
  it = (ms[node].lower_bound({vall, 0}));
  if (it == ms[node].end())
    return 0;
  else
    return (*it).second;
}
int getans(int node, int le, int ri, int start, int end, int vall) {
  if (start > ri || end < le) return 0;
  if (le >= start && ri <= end) {
    return go(node, vall);
  }
  int mid = (le + ri) / 2;
  return max(getans(2 * node, le, mid, start, end, vall),
             getans(2 * node + 1, mid + 1, ri, start, end, vall));
}
int main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i].val = a[i];
    b[i].idx = i;
    b[i].x = a[i] - i;
  }
  int mx = 200000;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ww1 = i;
    dp[i] = getans(1, 1, mx, 1, b[i].val - 1, b[i].x) + 1;
    if (dp[i] == 1 && b[i].x > 0) dp[i] = 0;
    update(1, 1, mx, b[i].val, {b[i].x, dp[i]});
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
