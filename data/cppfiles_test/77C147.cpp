#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 4e6 + 10;
int f[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, P;
  cin >> n >> P;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i] + 2 * f[i - 1] % P + (i != 2 ? f[1] : 0)) % P;
    for (int j = 2; j * i <= n; j++) {
      f[j * i] = ((f[j * i] + f[i]) % P - f[i - 1] + P) % P;
    }
  }
  cout << f[n] << '\n';
  return 0;
}
