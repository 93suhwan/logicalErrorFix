#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
long long f[N];
int n;
long long inv;
long long qmi(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = a * ans % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  f[0] = 1;
  for (int i = 1; i <= N; i++) f[i] = f[i - 1] * i % mod;
  inv = qmi(2, mod - 2);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    n *= 2;
    cout << f[n] * inv % mod << endl;
  }
  return 0;
}
