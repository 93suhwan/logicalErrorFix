#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1010;
int n, m;
bool z[MAXN][MAXN];
LL ans = 0;
int GetUp(int a, int b, int dir) {
  int ans = 0;
  while (1 <= a && a <= n && 1 <= b && b <= m && !z[a][b]) {
    ++ans;
    if (dir == 1)
      --a;
    else
      --b;
    dir ^= 1;
  }
  return ans;
}
int GetDown(int a, int b, int dir) {
  int ans = 0;
  while (1 <= a && a <= n && 1 <= b && b <= m && !z[a][b]) {
    ++ans;
    if (dir == 1)
      ++a;
    else
      ++b;
    dir ^= 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    int L = GetDown(i, 1, 1);
    ans += L * (L + 1) / 2;
  }
  for (int i = 1; i <= m; ++i) {
    int L = GetDown(1, i, 0);
    ans += L * (L + 1) / 2;
  }
  ans -= n * m;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (z[a][b]) {
      int L = GetUp(a, b - 1, 1);
      int R = GetDown(a + 1, b, 0);
      ans -= L * (L + 1) / 2;
      ans -= R * (R + 1) / 2;
      ans += (L + R + 2) * (L + R + 1) / 2;
      L = GetUp(a - 1, b, 0);
      R = GetDown(a, b + 1, 1);
      ans -= L * (L + 1) / 2;
      ans -= R * (R + 1) / 2;
      ans += (L + R + 2) * (L + R + 1) / 2;
      --ans;
    } else {
      int L = GetUp(a, b - 1, 1);
      int R = GetDown(a + 1, b, 0);
      ans += L * (L + 1) / 2;
      ans += R * (R + 1) / 2;
      ans -= (L + R + 2) * (L + R + 1) / 2;
      L = GetUp(a - 1, b, 0);
      R = GetDown(a, b + 1, 1);
      ans += L * (L + 1) / 2;
      ans += R * (R + 1) / 2;
      ans -= (L + R + 2) * (L + R + 1) / 2;
      ++ans;
    }
    z[a][b] = !z[a][b];
    cout << ans << "\n";
  }
  return 0;
}
