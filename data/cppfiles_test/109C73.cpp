#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 2e5 + 15;
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
      wB = 0, wNum = 0, bNum = 0, wb = 0, subtract = 0;
  bool hasWWBB = false;
  cin >> n;
  multy[0] = multy[1] = 1;
  rev[0] = rev[1] = 1;
  for (i = 2; i < maxn; i++) {
    multy[i] = multy[i - 1] * i % mod;
    rev[i] = rev[i - 1] * ksm(i, mod - 2) % mod;
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    cin >> now[i][0] >> now[i][1];
    if (now[i][0] == now[i][1]) {
      if (now[i][0] != '?') {
        hasWWBB = true;
      } else {
        waitWait++;
      }
    }
    if (now[i][0] == 'W') {
      wNum++;
      if (now[i][1] == '?') {
        subtract++;
      }
    } else if (now[i][0] == 'B') {
      bNum++;
    }
    if (now[i][1] == 'W') {
      wNum++;
      if (now[i][0] == '?') {
        subtract++;
      }
    } else if (now[i][1] == 'B') {
      bNum++;
    }
  }
  if (bNum > n || wNum > n) {
    ans = 0;
  } else {
    ans = C(2 * n - wNum - bNum, n - bNum);
    if (!hasWWBB) {
      if (n - bNum - subtract >= 0) {
        ans -= ksm(2, waitWait);
        bool hasBL = false;
        for (i = 1; i <= n; i++) {
          if (now[i][0] == 'B' || now[i][1] == 'W') {
            hasBL = true;
          }
        }
        if (!hasBL) {
          ans++;
        }
        bool hasWL = false;
        for (i = 1; i <= n; i++) {
          if (now[i][0] == 'W' || now[i][1] == 'B') {
            hasWL = true;
          }
        }
        if (!hasWL) {
          ans++;
        }
      }
    }
  }
  if (ans < 0) ans += mod;
  printf("%lld", ans);
  return 0;
}
