#include <bits/stdc++.h>
using namespace std;
const int N = 30 + 1;
const int mod = 1e9 + 7;
int bigmod(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * 1ll * a) % mod;
    }
    a = (a * 1ll * a) % mod;
    b >>= 1;
  }
  return ans;
}
inline int add(int x, int y) { return (x + y >= mod ? x + y - mod : x + y); }
inline int sub(int x, int y) { return (x - y < 0 ? x - y + mod : x - y); }
inline int gun(int x, int y) { return ((x * 1ll * y) % mod); }
inline int vag(int x, int y) { return (x * 1ll * bigmod(y, mod - 2)) % mod; }
int koto[N];
int koto2[N];
void TEST_CASES() {
  int n, k;
  cin >> n >> k;
  koto2[0] = 1;
  for (int i = 1; i < N; i++) {
    koto2[i] = gun(koto2[i - 1], n);
  }
  int ans = 0;
  while (k != 0) {
    for (int i = 0; i < N; i++) {
      if (koto[i] > k) {
        i--;
        ans = add(ans, koto2[i]);
        k -= koto[i];
        break;
      }
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  koto[0] = 1;
  for (int i = 1; i < N; i++) {
    koto[i] = (1 << (i));
  }
  int t = 1;
  cin >> t;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
