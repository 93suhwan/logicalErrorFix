#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 1e5 + 15;
long long rev[maxn], multy[maxn];
long long ksm(long long a, long long p) {
  long long ans = 1, multy = a;
  while (p) {
    if (p & 1) {
      ans *= multy;
      ans %= mod;
    }
    p >>= 1;
    multy *= multy;
    multy %= mod;
  }
  return ans;
}
long long C(int n, int m) { return multy[n] * rev[n - m] % mod * rev[m] % mod; }
int main() {
  ios::sync_with_stdio(false);
  char now[maxn][2];
  int n, i, j, k;
  int rB = 0, rWait = 0, lW = 0, lWait = 0, waitWait = 0, waitB = 0, wWait = 0,
      wB = 0;
  bool hasBB = false;
  cin >> n;
  multy[0] = multy[1] = 1;
  rev[0] = rev[1] = 1;
  for (i = 2; i <= n; i++) {
    multy[i] = multy[i - 1] * i % mod;
    rev[i] = rev[i - 1] * ksm(i, mod - 2) % mod;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    cin >> now[i][0] >> now[i][1];
    if (now[i][1] == 'B') {
      rB++;
      if (now[i][0] == 'B') {
        hasBB = true;
      } else if (now[i][0] == '?') {
        waitB++;
      } else {
        wB++;
      }
    } else if (now[i][1] == '?') {
      rWait++;
      if (now[i][0] == '?') {
        waitWait++;
      } else if (now[i][0] == 'W') {
        wWait++;
      }
    }
    if (now[i][0] == 'W') {
      lW++;
    } else if (now[i][0] == '?') {
      lWait++;
    }
  }
  for (int add = 0; add <= rWait; add++) {
    if (hasBB) {
      int b = rB + add;
      if (rB + add >= lW && rB + add <= lW + lWait) {
        ans += C(rWait, add) * C(lWait, b - lW) % mod;
        ans %= mod;
      }
    } else {
      int bNum = rB + add;
      if (rB + add >= lW && rB + add <= lW + lWait) {
        ans += C(rWait, add) * C(lWait, bNum - lW) % mod;
        ans %= mod;
        if (bNum != n && bNum != 0) {
          int hasWaitL = lWait - waitB;
          int nowW = lW + waitB;
          if (nowW <= bNum) {
            ans -=
                C(waitWait, bNum - nowW) * C(wWait, add - (bNum - nowW)) % mod;
            ans %= mod;
          }
        }
      }
    }
  }
  if (ans < 0) {
    ans += mod;
  }
  printf("%lld", ans);
  return 0;
}
