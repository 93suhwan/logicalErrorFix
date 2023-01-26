#include <bits/stdc++.h>
using namespace std;
vector<int> res;
const int N = 3E5 + 7;
long long pre[10][2];
long long dp[20][2];
int a[20];
int cnt[12];
priority_queue<pair<int, int> > q;
void solve() {
  int s, n;
  res.clear();
  while (!q.empty()) q.pop();
  memset(cnt, 0, sizeof(cnt));
  scanf("%d%d", &s, &n);
  int sum = 0, m = s;
  while (m) {
    sum += m % 10;
    m /= 10;
  }
  int u = n, o = 1, k = s;
  while (u && k) {
    if (k % 10) {
      if (o == 1)
        res.push_back(1);
      else
        q.push({1, -o});
      k--;
      u--;
    } else {
      k /= 10;
      o *= 10;
    }
  }
  if (u == 0) {
    while (!q.empty()) {
      res.push_back(-q.top().second);
      q.pop();
    }
    for (int i = 0; i < res.size(); i++) {
      if (i != res.size() - 1)
        printf("%d ", res[i]);
      else
        printf("%d\n", res[i] + k * o);
    }
    return;
  }
  while (u) {
    auto y = q.top();
    q.pop();
    if (y.first == 1) {
      int r = -y.second, w = -y.second / 10;
      r -= w;
      if (r != 1)
        q.push({9, -r});
      else
        res.push_back(r);
      if (w != 1)
        q.push({1, -w});
      else
        res.push_back(w);
    } else {
      int w = -y.second / y.first;
      int r = -y.second - w;
      if (w != 1)
        q.push({1, -w});
      else
        res.push_back(w);
      if (r != 1)
        q.push({y.first - 1, -r});
      else
        res.push_back(r);
    }
    u--;
  }
  for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
  while (!q.empty()) {
    printf("%d ", -q.top().second);
    q.pop();
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
