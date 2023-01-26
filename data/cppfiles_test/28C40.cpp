#include <bits/stdc++.h>
using namespace std;
long long a[300030];
long long stay[300030];
bool vis[300030];
signed main() {
  ;
  ;
  ;
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  ;
  ;
  long long N;
  cin >> N;
  while (N--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i <= n - 1; i++) stay[i] = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      stay[(i - a[i] + n) % n]++;
    }
    vector<long long> ans;
    for (long long k = 0; k <= n - 1; k++) {
      if ((n - stay[k] + 1) / 2 > m) continue;
      for (long long i = 1; i <= n; i++) vis[i] = 0;
      long long tot = 0;
      for (long long i = 1; i <= n; i++)
        if (!vis[i]) {
          long long now = i;
          while (!vis[now]) {
            vis[now] = 1;
            now = a[(now + k - 1) % n + 1];
          }
          tot++;
        }
      if (n - tot <= m) ans.emplace_back(k);
    }
    cout << ((long long)ans.size());
    for (auto &i : ans) cout << " " << i;
    cout << "\n";
  }
  return 0;
}
