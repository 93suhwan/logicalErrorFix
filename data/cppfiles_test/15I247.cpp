#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 111;
int q[N], dist[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int> > comb(N, vector<int>(N));
  for (int m = 0; m < (int)(N); m++) {
    comb[m][0] = 1;
    for (int n = (int)(1); n < ((int)m + 1); n++)
      comb[m][n] = (comb[m - 1][n - 1] + comb[m - 1][n]) % MOD;
  }
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > adj(n);
    for (int _ = 0; _ < (int)(n - 1); _++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (k == 2) {
      cout << comb[n][2] << endl;
      continue;
    }
    long long int ans = 0;
    for (int s = 0; s < (int)(n); s++) {
      fill_n(dist, n, INF);
      int l = 0, r = 0;
      dist[s] = 0;
      q[r++] = s;
      while (l < r) {
        int u = q[l++];
        for (auto v : adj[u]) {
          if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            q[r++] = v;
          }
        }
      }
      vector<int> cnt(n);
      for (int u = 0; u < (int)(n); u++) cnt[dist[u]]++;
      for (int sz = 0; sz < (int)(n); sz++) {
        ans += comb[cnt[sz]][k];
      }
    }
    cout << ans % MOD << endl;
  }
  return 0;
}
