#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VI = vector<int>;
using VVI = vector<VI>;
const ll MOD = 1e9 + 7;
VVL C(101, VL(101, -1));
ll combi(int x, int y) {
  if (y < 0 or y > x) return 0;
  ll& res = C[x][y];
  if (res != -1) return res;
  if (x == 0) return 1;
  return res = (combi(x - 1, y) + combi(x - 1, y - 1)) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    VVI G(n);
    for (int r = 0; r < n - 1; ++r) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if (k == 2)
      cout << n * (n - 1) / 2 << endl;
    else {
      ll res = 0;
      for (int x = 0; x < n; ++x) {
        VI num(n, 0);
        VI dist(n, -1);
        queue<int> Q;
        dist[x] = 0;
        Q.push(x);
        while (not Q.empty()) {
          int y = Q.front();
          Q.pop();
          for (int z : G[y])
            if (dist[z] == -1) {
              dist[z] = dist[y] + 1;
              Q.push(z);
              ++num[dist[z]];
            }
        }
        for (int i = 1; i < n; ++i) res = (res + combi(num[i], k)) % MOD;
      }
      cout << res << endl;
    }
  }
}
