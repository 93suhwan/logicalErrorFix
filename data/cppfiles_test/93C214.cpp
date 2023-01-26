#include <bits/stdc++.h>
using namespace std;
long long re() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long mod = 1000000007;
const int maxn = 4000005;
const int pr = 3;
const int phi = 998244352;
const int dx[8] = {1, 0, 0, -1, -1, -1, 1, 1},
          dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
int lowbit(int x) { return x & (-x); }
long long qk(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return ans;
}
int c[1000005];
void solve() {
  int _;
  cin >> _;
  for (int i = 1; i <= 300000; i++) {
    c[i] = c[i - 1] ^ i;
  }
  while (_--) {
    int a, b;
    cin >> a >> b;
    if (c[a - 1] == b) {
      cout << a << '\n';
    } else if ((c[a - 1] ^ b) == a) {
      cout << a + 2 << '\n';
    } else {
      cout << a + 1 << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
