#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int a[300300], Log[300300];
deque<pair<int, int> > que;
struct subseq {
  vector<int> c;
  vector<long long> dp;
  vector<vector<int> > rmq;
  void cal_dp() {
    int n = c.size();
    dp.resize(n + 1, 0);
    stack<pair<int, int> > s;
    for (int i = (n - 1); i >= (0); i--) {
      while (!s.empty() && s.top().second >= c[i]) s.pop();
      int nxt;
      if (s.empty())
        nxt = n;
      else
        nxt = s.top().first;
      dp[i] = dp[nxt] + (long long)c[i] * (nxt - i);
    }
  }
  void init_rmq() {
    int n = c.size(), llog = 0;
    while ((1 << llog) <= n) llog++;
    rmq.resize(n, vector<int>(llog + 1));
    for (int i = (n - 1); i >= (0); i--) {
      rmq[i][0] = i;
      for (int p = (1); p <= (llog); p++)
        if (i + (1 << p) <= n) {
          int a = rmq[i][p - 1], b = rmq[i + (1 << (p - 1))][p - 1];
          rmq[i][p] = (c[a] <= c[b] ? a : b);
        }
    }
  }
  int query(int l, int r) {
    int p = Log[r - l + 1];
    int a = rmq[l][p], b = rmq[r - (1 << p) + 1][p];
    return (c[a] <= c[b] ? a : b);
  }
};
vector<subseq> seq;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q >> k;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  seq.resize(k);
  for (int i = (1); i <= (n); i++) {
    while (que.front().first < i - k) que.pop_front();
    while (!que.empty() && que.back().second >= a[i]) que.pop_back();
    que.push_back({i, a[i]});
    seq[i % k].c.push_back(que.front().second);
  }
  for (int i = (0); i <= (k - 1); i++) seq[i].cal_dp(), seq[i].init_rmq();
  Log[0] = -1;
  for (int i = (1); i <= (n); i++) Log[i] = Log[i >> 1] + 1;
  int l, r;
  while (q--) {
    cin >> l >> r;
    if (r - l < k) {
      cout << a[l] << endl;
      continue;
    }
    int id = l % k, lb = l / k + 1, rb = r / k;
    int pos = seq[id].query(lb, rb);
    cout << a[l] + seq[id].dp[lb] - seq[id].dp[pos] +
                (rb - pos + 1) * seq[id].c[pos]
         << endl;
  }
  return 0;
}
