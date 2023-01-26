#include <bits/stdc++.h>
using namespace std;
const int N = 51;
long long g[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    if (v >= N || u >= N) continue;
    g[v] |= (1LL << u);
    g[u] |= (1LL << v);
  }
  n = min(n, N);
  int f[5] = {};
  for (f[0] = (0 ? f[0 - 1] + 1 : 0); f[0] < n; f[0]++)
    for (f[1] = (1 ? f[1 - 1] + 1 : 0); f[1] < n; f[1]++)
      for (f[2] = (2 ? f[2 - 1] + 1 : 0); f[2] < n; f[2]++)
        for (f[3] = (3 ? f[3 - 1] + 1 : 0); f[3] < n; f[3]++)
          for (f[4] = (4 ? f[4 - 1] + 1 : 0); f[4] < n; f[4]++) {
            long long msk = 0, _or = 0, _and = (1LL << n) - 1;
            for (int i : f) {
              _or |= g[i];
              _and &= g[i];
              msk |= (1LL << i);
            }
            if (_and == msk || !(_or & msk)) {
              for (auto i : f) cout << i + 1 << " ";
              cout << "\n";
              return 0;
            }
          }
  cout << "-1\n";
}
