#include <bits/stdc++.h>
using namespace std;
auto fio = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
long long G[1010][1010];
int32_t main() {
  long long n, m;
  cin >> n >> m;
  auto isValid = [&](long long i, long long j) {
    return i >= 0 && i < n && j >= 0 && j < m && !G[i][j];
  };
  long long ans = 0;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) ans += min(i, j) * 4 + 1 + (i != j);
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    long long a = 0, b = 0;
    long long c = 0, d = 0;
    long long old = G[x][y];
    G[x][y] = 0;
    for (long long i = x, j = y; isValid(i, j); a++)
      if (a & 1)
        i--;
      else
        j--;
    for (long long i = x, j = y; isValid(i, j); b++)
      if (b & 1)
        j++;
      else
        i++;
    for (long long i = x, j = y; isValid(i, j); c++)
      if (c & 1)
        j--;
      else
        i--;
    for (long long i = x, j = y; isValid(i, j); d++)
      if (d & 1)
        i++;
      else
        j++;
    long long w = a * b + c * d - 1;
    if (old)
      ans += w;
    else
      ans -= w;
    G[x][y] = !old;
    cout << ans << endl;
  }
}
