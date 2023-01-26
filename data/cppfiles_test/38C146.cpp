#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
inline double time() {
  return static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(
                                 chrono::steady_clock::now().time_since_epoch())
                                 .count()) *
         1e-9;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> sum(m + 1);
  for (int i = 0; i + 1 < m; i++) {
    int u = 0;
    for (int j = 1; j < n; j++) {
      if (s[j][i] == 'X' and s[j - 1][i + 1] == 'X') u = 1;
    }
    sum[i + 1] = sum[i] + u;
  }
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (x == y) {
      printf("YES\n");
      continue;
    }
    if (sum[y - 1] - sum[x - 1] > 0) {
      printf("NO\n");
      continue;
    } else {
      printf("YES\n");
      continue;
    }
  }
}
