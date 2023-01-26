#include <bits/stdc++.h>
using namespace std;
const long double PI = (acosl(-1.0));
void clean(vector<pair<int, int>> &vp, vector<int> &pts) {
  set<int> st;
  for (int i = 0; i < pts.size(); i++) st.insert(pts[i]);
  int len = 0;
  for (int i = 0; i < vp.size(); i++) {
    auto it = st.lower_bound(vp[i].first);
    if (it == st.end() || *it > vp[i].second) vp[len++] = vp[i];
  }
  vp.erase(vp.begin() + len, vp.end());
  sort(vp.begin(), vp.end());
  len = 0;
  for (int i = 0; i < vp.size(); i++) {
    while (len > 0 && vp[len - 1].second >= vp[i].second) len--;
    vp[len++] = vp[i];
  }
  vp.erase(vp.begin() + len, vp.end());
  sort(pts.begin(), pts.end());
  return;
}
long long int dp[1000005];
long long int solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> pts(n);
  vector<pair<int, int>> vp(m);
  for (int i = 0; i < n; i++) scanf("%d", &pts[i]);
  for (int i = 0; i < m; i++) scanf("%d %d", &vp[i].first, &vp[i].second);
  clean(vp, pts);
  m = vp.size();
  n = pts.size();
  vector<pair<int, int>> allpts;
  for (int i = 0; i < n; i++) {
    allpts.push_back(make_pair(pts[i], 2));
  }
  for (int i = 0; i < m; i++) {
    allpts.push_back(make_pair(vp[i].first, 0));
    allpts.push_back(make_pair(vp[i].second, 1));
  }
  allpts.push_back(make_pair(-2e9, 2));
  sort(allpts.begin(), allpts.end());
  dp[0] = 0;
  int l = allpts.size();
  for (int i = 1; i < l; i++) dp[i] = 1000000000000000000LL;
  map<int, int> End, idx;
  for (int i = 0; i < vp.size(); i++) End[vp[i].first] = vp[i].second;
  for (int i = 0; i < allpts.size(); i++) idx[allpts[i].first] = i;
  for (int i = 1; i < allpts.size(); i++) {
    pair<int, int> p = allpts[i];
    if (p.second != 2) continue;
    dp[i] = min(dp[i - 1], dp[i]);
    long long int Next = p.first;
    long long int tp1 = dp[i] - Next, tp2 = dp[i] - 2 * Next;
    for (int j = i - 1; j >= 0; j--) {
      pair<int, int> q = allpts[j];
      if (q.second == 0)
        Next = End[q.first];
      else {
        tp1 = min(tp1, dp[j] - Next);
        tp2 = min(tp2, dp[j] - 2 * Next);
      }
      if (allpts[j].second == 2) break;
    }
    dp[i] = min(dp[i], p.first + tp1);
    for (int j = i + 1; allpts[j].second != 2 && j < allpts.size(); j++) {
      pair<int, int> q = allpts[j];
      if (q.second == 0) {
        long long int ret = min(2 * q.first - 2 * p.first + p.first + tp1,
                                q.first - p.first + 2 * p.first + tp2);
        dp[j] = min(dp[j], min(ret, dp[i - 1] + q.first - p.first));
        int k = idx[End[q.first]];
        dp[k] = dp[j];
      }
    }
  }
  return dp[(int)allpts.size() - 1];
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long int ans = solve();
    printf("%lld\n", ans);
  }
  return 0;
}
