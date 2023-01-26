#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, INF = 1e18;
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long test = 1; test <= t; test++) {
    long long n, m;
    cin >> n >> m;
    long long k = sqrt(m) + 1;
    vector<vector<long long> > temp(k);
    for (int i = 0; i < k; i++) temp[i].resize(i, 0);
    vector<long long> temp1(m, 0);
    vector<pair<long long, long long> > train(n);
    long long u, v;
    for (int i = 0; i < n; i++) {
      cin >> u >> v;
      train[i] = {u, v};
    }
    vector<long long> vis(n, -1);
    vector<long long> temp2(m, -1);
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      --v;
      if (i) temp1[i] += temp1[i - 1];
      long long mod1 = train[v].first + train[v].second;
      if (mod1 >= k) {
        if (vis[v] != -1) {
          for (int j = vis[v]; j < m; j += mod1) {
            if (j + train[v].first <= i) {
              if (j + mod1 > i) {
                temp1[i]--;
                if (j + mod1 < m) temp1[j + mod1]++;
              }
            } else {
              if (j + train[v].first < m) temp1[j + train[v].first]--;
              if (j + mod1 < m) temp1[j + mod1]++;
            }
          }
          vis[v] = -1;
        } else {
          vis[v] = i;
          for (int j = vis[v]; j < m; j += mod1) {
            if (j + train[v].first < m) temp1[j + train[v].first]++;
            if (j + mod1 < m) temp1[j + mod1]--;
          }
        }
      } else {
        if (u == 1) {
          vis[v] = i;
          for (int j = train[v].first; j < mod1; j++) {
            temp[mod1][(j + vis[v]) % mod1]++;
          }
        } else {
          for (int j = train[v].first; j < mod1; j++) {
            temp[mod1][(j + vis[v]) % mod1]--;
          }
          vis[v] = -1;
        }
      }
      long long ans = temp1[i];
      for (int j = 1; j < k; j++) {
        ans += temp[j][i % j];
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
