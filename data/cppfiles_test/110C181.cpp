#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int d[200010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int T = (0); T < (t); T++) {
    int n;
    cin >> n;
    for (int i = (0); i < (n); i++) {
      int x;
      cin >> x;
      for (int j = (0); j < (x); j++) {
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
      }
      d[i] = x;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    vector<int> nxt;
    int ans = 1;
    int cnt = 0;
    for (int i = (0); i < (n); i++)
      if (d[i] == 0) {
        q.push(i);
        cnt++;
      }
    while (!q.empty() || !nxt.empty()) {
      if (q.empty()) {
        ans++;
        for (auto it = nxt.begin(); it != nxt.end(); it++) q.push(*it);
        nxt.clear();
      }
      int aux = q.top();
      q.pop();
      for (auto it = g[aux].begin(); it != g[aux].end(); it++) {
        d[*it]--;
        if (d[*it] == 0) {
          cnt++;
          if (aux < *it)
            q.push(*it);
          else
            nxt.push_back(*it);
        }
      }
    }
    if (cnt == n)
      cout << ans << '\n';
    else
      cout << -1 << '\n';
    for (int i = (0); i < (n); i++) {
      d[i] = -1;
      g[i].clear();
    }
  }
  return 0;
}
