#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long M = (1e9) + 7;
const long long N = 100005;
const long long NF = 1010;
long long n, m;
long long zyx[NF][NF];
void dfs(long long x, long long y) {
  if (x < 1 || y < 1 || x > m || y > n) {
    cout << x << " ";
    return;
  } else {
    if (!(zyx[y][x] - 1)) {
      zyx[y][x] = 2;
      dfs(1 + x, y);
    } else if (!(zyx[y][x] - 2)) {
      zyx[y][x] = 2;
      dfs(x, 1 + y);
    } else if (!(zyx[y][x] - 3)) {
      zyx[y][x] = 2;
      dfs(x - 1, y);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  for (long long t = 1; t <= tc; t++) {
    long long k, z;
    cin >> n >> m >> k;
    for (long long i = 1; i < n + 1; i++)
      for (long long j = 1; j < m + 1; j++) cin >> zyx[i][j];
    while (k--) {
      cin >> z;
      dfs(z, 1);
    }
  }
  return 0;
}
