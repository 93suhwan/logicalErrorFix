#include <bits/stdc++.h>
using namespace std;
const long long mxN = 1e6 + 6, md = 998244353;
long long R[mxN][2][2], C[mxN][2][2];
long long N, M;
long long A, B;
long long G[2][2];
map<pair<long long, long long>, long long> mp;
long long exp(long long x, long long y, long long md) {
  long long ans = 1;
  x = x % md;
  while (y > 0) {
    if (y & 1) ans = ans * x % md;
    y = y >> 1;
    x = x * x % md;
  }
  return ans;
}
pair<long long, long long> empty(long long x, long long y) {
  long long f1 = 0, f2 = 0;
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      f1 += R[x][i][j];
      f2 += C[y][i][j];
    }
  }
  return {(f1 == 0), (f2 == 0)};
}
pair<long long, long long> conflict(long long x, long long y) {
  bool f1 = ((R[x][0][0] + R[x][1][1] > 0) && (R[x][0][1] + R[x][1][0] > 0));
  bool f2 = ((C[y][0][0] + C[y][1][1] > 0) && (C[y][0][1] + C[y][1][0] > 0));
  return {f1, f2};
}
long long chess() {
  bool f1 = ((G[0][0] + G[1][1] > 0) && (G[0][1] + G[1][0] > 0));
  long long f2 = G[0][0] + G[1][1] + G[0][1] + G[1][0];
  if (f1) return 0;
  return (f2 ? 1 : 2);
}
void clear(long long x, long long y) {
  if (mp.count({x, y})) {
    long long z = mp[{x, y}];
    mp.erase(mp.find({x, y}));
    auto [f1, f2] = conflict(x, y);
    R[x][z][(x + y) & 1]--;
    C[y][z][(x + y) & 1]--;
    G[z][(x + y) & 1]--;
    auto [f3, f4] = conflict(x, y);
    auto [a, b] = empty(x, y);
    N += a, M += b;
    A += f3 - f1, B += f4 - f2;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m, k;
  cin >> n >> m >> k;
  N = n, M = m;
  while (k--) {
    long long x, y, t;
    cin >> x >> y >> t;
    clear(x, y);
    if (t == -1) {
      long long ans = exp(2, M, md) * (!B) + exp(2, N, md) * (!A) - chess();
      cout << (ans % md + md) % md << '\n';
      continue;
    }
    auto [a, b] = empty(x, y);
    N -= a, M -= b;
    auto [f1, f2] = conflict(x, y);
    R[x][t][(x + y) & 1]++;
    C[y][t][(x + y) & 1]++;
    G[t][(x + y) & 1]++;
    mp[{x, y}] = t;
    auto [f3, f4] = conflict(x, y);
    A += f3 - f1, B += f4 - f2;
    long long ans = exp(2, M, md) * (!B) + exp(2, N, md) * (!A) - chess();
    cout << (ans % md + md) % md << '\n';
  }
}
