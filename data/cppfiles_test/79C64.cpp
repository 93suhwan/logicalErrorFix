#include <bits/stdc++.h>
using namespace std;
const int MAXn = 3e5 + 5;
int a[MAXn];
int b[MAXn];
int dis[MAXn][2];
pair<int, int> pi[MAXn][2];
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 0; i <= n; i++) dis[i][0] = dis[i][1] = INF;
  set<int> st;
  for (int i = 0; i < n; i++) st.insert(st.end(), i);
  dis[n][0] = dis[n][1] = 0;
  deque<pair<int, int> > dq;
  dq.push_back({n, 1});
  while (((int)dq.size())) {
    auto [x, tp] = dq.front();
    dq.pop_front();
    if (x == 0) {
      cout << dis[0][0] << endl;
      pair<int, int> now = {0, 0};
      vector<int> his;
      while (now.first != n) {
        if (now.second == 0) his.push_back(now.first);
        now = pi[now.first][now.second];
      }
      reverse(his.begin(), his.end());
      for (long long x : his) cout << x << " ";
      cout << endl;
      return 0;
    }
    if (tp == 0) {
      int y = x + b[x];
      if (dis[y][1] > dis[x][tp])
        dis[y][1] = dis[x][tp], dq.push_front({y, 1}), pi[y][1] = {x, tp};
    } else {
      while (1) {
        auto it = st.lower_bound(x - a[x]);
        if (it == st.end() || (*it) > x) break;
        int y = *it;
        st.erase(it);
        if (dis[y][0] > dis[x][tp] + 1)
          dis[y][0] = dis[x][tp] + 1, dq.push_back({y, 0}), pi[y][0] = {x, tp};
      }
    }
  }
  cout << -1 << endl;
}
