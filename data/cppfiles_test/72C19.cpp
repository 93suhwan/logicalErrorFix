#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 3e5 + 5;
const long long MOD = 998244353;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline long long pw(long long x, long long y, long long md = MOD) {
  long long ret = 1;
  x %= md;
  while (y) {
    if (y & 1) ret = ret * x % md;
    x = x * x % md, y >>= 1;
  }
  return ret;
}
inline void add(int &a, int b, int md = MOD) {
  a = a + b >= md ? a + b - md : a + b;
}
int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int le, ri, mid, ori, a, res;
int main() {
  int x1, x2, y1, y2;
  ori = query(1, 1);
  le = 2, ri = 999999999;
  while (le <= ri) {
    mid = le + ri >> 1;
    a = query(1, mid);
    if (a == ori - mid + 1)
      res = mid, le = mid + 1;
    else
      ri = mid - 1;
  }
  y1 = res;
  x1 = ori + 2 - y1;
  x2 = 1000000000 - (query(1000000000, 1) - y1 + 1);
  y2 = 1000000000 - (query(1, 1000000000) - x1 + 1);
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
