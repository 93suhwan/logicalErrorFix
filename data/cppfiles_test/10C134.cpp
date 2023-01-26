#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> f(n + 1, 0), a(n), out(n, 0), temp(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i], f[a[i]]++, adj[a[i]].push_back(i);
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
      if (f[i] < k) cnt += f[i];
    }
    int cycle = cnt / k;
    int index = 1;
    int maxa = cycle * k;
    int curr = 0;
    for (int i = 0; i < n; i++) {
      if (f[a[i]] >= k) {
        if (temp[a[i]] < k) out[i] = ++temp[a[i]];
      }
    }
    for (int i = 0; i <= n; i++) {
      if (curr >= maxa) break;
      if (adj[i].size() >= k) continue;
      for (auto j : adj[i]) {
        out[j] = index;
        curr++;
        index++;
        if (index == k + 1) index = 1;
        if (curr == maxa) break;
      }
    }
    for (int i = 0; i < n; i++) cout << out[i] << " ";
    cout << "\n";
  }
  return 0;
}
