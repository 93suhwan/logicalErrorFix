#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long modx = 998244353;
long double PI = 3.1415926535897;
const long long N = 200010;
long long pows(long long x1, long long y1) {
  long long r1 = 1;
  x1 = x1 % mod;
  while (y1 > 0) {
    if (y1 & 1) r1 = (r1 * x1) % mod;
    y1 = y1 >> 1;
    x1 = (x1 * x1) % mod;
  }
  return r1;
}
void Unstoppable_1();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    Unstoppable_1();
    cout << "\n";
  }
  return 0;
}
void Unstoppable_1() {
  long long n, k, ans = 0;
  cin >> n >> k;
  long long a[32], b[32];
  memset(b, 0, sizeof(b));
  for (long long i = 0; i < 32; i++) {
    a[i] = pows(n, i);
  }
  long long i = 0;
  while (k > 0) {
    b[i] = k % 2;
    k = k / 2;
    i++;
  }
  for (long long i = 0; i < 32; i++) {
    ans = (ans + (a[i] * b[i]) % mod) % mod;
  }
  cout << ans;
}
