#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
vector<int> v[100005];
bool sepoate(int val, int n, int m) {
  int i, j;
  int ok = 0;
  for (i = 1; i <= n; ++i) {
    int okc = 0;
    for (j = 1; j <= m; ++j) {
      if (v[j][i] >= val) okc = 1;
    }
    if (!okc) return false;
  }
  for (i = 1; i <= m; ++i) {
    int cnt = 0;
    for (j = 1; j <= n; ++j) {
      if (v[i][j] >= val) ++cnt;
    }
    if (cnt > 1) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q, n, h, k, s = 0, t;
  long long i, j, m;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (i = 1; i <= m; ++i) {
      v[i].resize(n + 3);
      for (j = 1; j <= n; ++j) cin >> v[i][j];
    }
    k = 0;
    int pas = 1 << 29;
    while (pas) {
      if (sepoate(k + pas, n, m)) k += pas;
      pas >>= 1;
    }
    cout << k << '\n';
  }
}
