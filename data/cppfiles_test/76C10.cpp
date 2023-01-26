#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MOD = 1000000007;
map<int, map<int, int> > g;
bool func(int ara[]) {
  int cnt = 0;
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 5; j++) cnt += g[ara[i]][ara[j]];
  return cnt == 10 or cnt == 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  int i, j, k;
  int n, m;
  cin >> n >> m;
  for (i = 0; i < m; i++) cin >> j >> k, g[j][k] = 1, g[k][j] = 1;
  int ara[5];
  for (ara[0] = 1; ara[0] <= min(48, n); ara[0]++)
    for (ara[1] = ara[0] + 1; ara[1] <= min(48, n); ara[1]++)
      for (ara[2] = ara[1] + 1; ara[2] <= min(48, n); ara[2]++)
        for (ara[3] = ara[2] + 1; ara[3] <= min(48, n); ara[3]++)
          for (ara[4] = ara[3] + 1; ara[4] <= min(48, n); ara[4]++)
            if (func(ara)) {
              for (i = 0; i < 5; i++) cout << ara[i] << " ";
              cout << endl;
              return 0;
            }
  cout << -1 << endl;
}
