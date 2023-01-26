#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int mod = 1e9 + 7;
inline int rd() {
  int x = 0;
  int f = 1;
  char s = getchar();
  while (!isdigit(s)) {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (isdigit(s)) {
    x = (x << 1) + (x << 3) + s - '0';
    s = getchar();
  }
  return x * f;
}
inline int qpow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    b >>= 1;
    a = 1ll * a * a % mod;
  }
  return ans;
}
int n;
int main() {
  cin >> n;
  long long t = (qpow(2, n, mod - 1) - 2 + (mod - 1)) % (mod - 1);
  long long ans = 1ll * 6 * qpow(4, t, mod) % mod;
  cout << ans << endl;
  return 0;
}
