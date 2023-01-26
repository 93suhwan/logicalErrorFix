#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> nums(n);
    for (int i = 0; i < (int)n; i++) cin >> nums[i];
    vector<int> nxt(n);
    for (int i = 0; i < (int)n; i++) nxt[i] = (i + d) % n;
    queue<int> q;
    vector<int> dist(n, INF);
    for (int i = 0; i < (int)n; i++)
      if (nums[i] == 0) {
        dist[i] = 0;
        q.push(i);
      }
    while (q.size()) {
      int p = q.front();
      q.pop();
      if (dist[nxt[p]] == INF) {
        dist[nxt[p]] = dist[p] + 1;
        q.push(nxt[p]);
      }
    }
    int ans = *max_element(dist.begin(), dist.end());
    if (ans == INF)
      cout << -1;
    else
      cout << ans;
    cout << '\n';
  }
}
