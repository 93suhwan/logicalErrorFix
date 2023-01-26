#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7, mod = 998244353;
int f[N];
int qmi(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res *= a, res %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) f[i] = 0;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x == 0)
        cnt++, f[0]++;
      else if (x == 1)
        sum += f[x - 1], sum++;
      else
        sum += f[x - 1] + f[x - 2];
      f[x] += f[x - 1];
      f[x] %= mod;
      sum %= mod;
    }
    cout << (sum + qmi(2, cnt) - 1) % mod << endl;
  }
  return 0;
}
