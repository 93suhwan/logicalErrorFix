#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
long long ans = 500000004;
long long jie(int n) {
  if (n == 1) return ans;
  return n * jie(n - 1) % mod;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long ans = 500000004;
    for (int i = 1; i <= 2 * n; i++) {
      ans *= i;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
