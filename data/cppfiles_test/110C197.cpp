#include <bits/stdc++.h>
using namespace std;
int n, in[200005], ans[200005];
vector<int> ve[200005];
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int m;
      cin >> m;
      for (int j = 1, u; j <= m; j++) {
        cin >> u;
        ve[u].push_back(i);
        in[i]++;
      }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    queue<int> tq;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (!in[i]) q.push(i), cnt++;
    while (!q.empty()) {
      int now = q.top();
      q.pop();
      for (auto it : ve[now]) {
        if (it < now)
          ans[it] = max(ans[now] + 1, ans[it]);
        else
          ans[it] = max(ans[now], ans[it]);
        in[it]--;
        if (!in[it]) {
          if (it > now)
            q.push(it);
          else
            tq.push(it);
          cnt++;
        }
      }
      if (q.empty())
        while (!tq.empty()) q.push(tq.front()), tq.pop();
    }
    if (cnt != n)
      cout << -1 << endl;
    else
      cout << "" << *(max_element(ans + 1, ans + 1 + n)) + 1 << endl;
    for (int i = 1; i <= n; i++) {
      ans[i] = in[i] = 0;
      ve[i].clear();
    }
  }
}
