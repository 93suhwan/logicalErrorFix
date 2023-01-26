#include <bits/stdc++.h>
using namespace std;
vector<long long int> g[200003];
long long int ind[200003];
long long int mx[200003];
bool vis[200003];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (long long int i = 1ll; i <= n; i++) {
      g[i].clear();
      ind[i] = 0ll;
      mx[i] = 0ll;
      vis[i] = 0;
    }
    for (long long int i = 1ll; i <= n; i++) {
      long long int k;
      cin >> k;
      for (long long int j = 1ll; j <= k; j++) {
        long long int x;
        cin >> x;
        g[x].push_back(i);
        ind[i]++;
      }
    }
    queue<long long int> q;
    for (long long int i = 1ll; i <= n; i++) {
      if (ind[i] == 0ll) {
        q.push(i);
        mx[i] = 1ll;
      }
    }
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      vis[node] = 1;
      for (auto it : g[node]) {
        ind[it]--;
        if (it < node) {
          mx[it] = max(mx[it], mx[node] + 1ll);
        } else {
          mx[it] = max(mx[it], mx[node]);
        }
        if (ind[it] == 0ll) {
          q.push(it);
        }
      }
    }
    bool flg = 1;
    long long int ans = 0ll;
    for (long long int i = 1ll; i <= n; i++) {
      if (!vis[i]) {
        flg = 0ll;
        break;
      }
      ans = max(ans, mx[i]);
    }
    if (!flg) {
      cout << "-1"
           << "\n";
    } else {
      cout << ans << "\n";
    }
  }
}
