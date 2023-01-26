#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline int read() {
  char ch;
  bool sign = 0;
  int res = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = 1;
  while (isdigit(ch)) res = res * 10 + (ch ^ 48), ch = getchar();
  if (sign)
    return -res;
  else
    return res;
}
const int maxn = 500 + 10;
const int mod = 1e9 + 7;
int n, k;
inline int mul(int a, int b) { return 1LL * a * b % mod; }
inline int add(int a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
  else if (a < 0)
    a += mod;
  return a;
}
inline int fpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) ans = mul(ans, a);
  }
  return ans;
}
inline int solve() {
  int b = ((1LL << k) - 2) % (mod - 1);
  int ans = mul(6, fpow(4, b));
  return ans;
}
int main(void) {
  scanf("%d", &(k));
  printf("%d\n", solve());
  return 0;
}
