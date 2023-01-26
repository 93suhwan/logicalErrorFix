#include <bits/stdc++.h>
const long long inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int MAX_N = 5e5 + 7;
using namespace std;
int a[MAX_N];
int ans = inf, N;
bool check(int x, int y, int z, int val) {
  if (x >= val / 3 - 1) {
    if (val % 3 == 1 && (y >= 2 || y == 1 && z == 2)) return true;
    if (val % 3 == 0 && y && z) return true;
    if (val % 3 == 2 && y == 2 && z) return true;
  }
  if (x >= val / 3) {
    if (val % 3 == 1) {
      if (z) return true;
    } else if (val % 3 == 2) {
      if (y || z >= 2) return true;
    } else
      return true;
  }
  return false;
}
void solve(int x, int y, int z) {
  if (x < 0 || y < 0 || z < 0) return;
  for (int i = 1; i <= N; i++) {
    if (!check(x, y, z, a[i])) return;
  }
  ans = min(ans, x + y + z);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    int Max = 0;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      Max = max(Max, a[i]);
    }
    Max /= 3;
    ans = inf;
    for (int i = Max - 2; i <= Max + 3; i++) {
      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 2; k++) {
          solve(i, j, k);
        }
      }
    }
    cout << ans << endl;
  }
}
