#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int> > rng;
vector<pair<int, int> > st;
long long dp[200010];
long long pre[200010], suc[200010];
int a[200010];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first != b.first ? a.first < b.first : a.second > b.second;
}
bool cmpr(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    rng.resize(m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &rng[i].first, &rng[i].second);
    }
    sort(rng.begin(), rng.end(), cmp), st.clear();
    for (auto it : rng) {
      while (st.size() && st.back().second >= it.second) st.pop_back();
      st.push_back(it);
    }
    rng.clear();
    for (auto it : st) {
      int l = it.first, r = it.second;
      int pos = lower_bound(a, a + n, l) - a;
      if (pos < n && a[pos] <= r) continue;
      rng.push_back(make_pair(l, r));
    }
    if (!rng.size()) {
      printf("0\n");
      continue;
    }
    long long val = rng.front().first < a[0] ? INF : 0;
    int ll = 0,
        rr = lower_bound(rng.begin(), rng.end(), make_pair(a[0], a[0])) -
             rng.begin();
    for (int j = ll; j < rr; j++) {
      dp[j] = j == ll ? 0 : INF;
    }
    a[n] = 2000000000;
    for (int i = 1; i <= n; i++) {
      for (int j = ll; j < rr; j++) {
        pre[j] = dp[j] + (a[i - 1] - rng[j].second);
        suc[j] = dp[j] + (a[i - 1] - rng[j].second) * 2;
      }
      for (int j = ll + 1; j < rr; j++) {
        pre[j] = min(pre[j], pre[j - 1]);
      }
      for (int j = rr - 2; j >= ll; j--) {
        suc[j] = min(suc[j], suc[j + 1]);
      }
      int l =
          lower_bound(rng.begin(), rng.end(), make_pair(a[i - 1], a[i - 1])) -
          rng.begin();
      int r = lower_bound(rng.begin(), rng.end(), make_pair(a[i], a[i])) -
              rng.begin();
      for (int j = l; j <= r; j++) {
        int dist = j == l ? 0 : rng[j - 1].first - a[i - 1];
        long long res = val + dist;
        int pos = lower_bound(rng.begin() + ll, rng.begin() + rr,
                              make_pair(0, a[i - 1] - dist), cmpr) -
                  rng.begin();
        if (pos < rr) res = min(res, suc[pos] + dist);
        if (pos > ll) res = min(res, pre[pos - 1] + dist * 2);
        if (j < r)
          dp[j] = res;
        else
          val = res;
      }
      ll = l, rr = r;
    }
    printf("%lld\n", val);
  }
  return 0;
}
