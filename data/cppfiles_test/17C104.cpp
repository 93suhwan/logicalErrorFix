#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const unsigned _mod = 998244353;
const unsigned mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
void rd(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == 45) f = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
long long ksm(long long x, long long y = mod - 2, long long m = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % m;
    y >>= 1ll;
    x = x * x % m;
  }
  return ret;
}
long long qpow(long long x, long long y = 2) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1ll) ret = ret * x;
    y >>= 1ll;
    x = x * x;
  }
  return ret;
}
int n, r[50010][6], mx[6];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int pos = -1;
    cin >> n;
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (5); ++j) rd(r[i][j]);
    for (int i = (1); i <= (5); ++i) mx[i] = inf;
    for (int i = (1); i <= (n); ++i) {
      int cnt = 0;
      for (int j = (1); j <= (5); ++j)
        if (r[i][j] < mx[j]) cnt++;
      if (cnt >= 3) {
        for (int j = (1); j <= (5); ++j) mx[j] = r[i][j];
        pos = i;
      }
    }
    for (int i = (1); i <= (n); ++i)
      if (i != pos) {
        int cnt = 0;
        for (int j = (1); j <= (5); ++j)
          if (r[i][j] > mx[j]) cnt++;
        if (cnt < 3) {
          pos = -1;
          break;
        }
      }
    cout << pos << '\n';
  }
  return 0;
}
