#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
inline long long Z(long long x) { return x >= 998244353 ? x - 998244353 : x; }
long long sum[1 << 21];
long long f[1 << 21][2], g[1 << 21];
long long n, a[21];
int main() {
  std::vector<int> A(5, 0);
  A[1] = 1, A[2] = 3, A[3] = 4, A[4] = 6;
  int pos = --upper_bound(A.begin() + 1, A.end(), 1) - A.begin();
  std::cout << pos << '\n';
  return 0;
}
