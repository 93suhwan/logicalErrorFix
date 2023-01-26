#include <bits/stdc++.h>
using namespace std;
int dx[]{-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long const mod = 1e9 + 7;
int const N = 1e5 + 10;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  if (c % 2) {
    ans = 3;
    if (b) {
      ans = 1;
      --b;
    }
  }
  if (b % 2) {
    ans += 2;
  }
  if (ans) {
    if (a >= ans) {
      a -= ans;
      ans = 0;
    } else {
      ans -= a % 2;
      a = 0;
    }
  }
  ans += (a % 2);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
