#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long infll = 1e18;
const int M = 1000000007;
const int N = 5e5;
int mult(int a, int b) { return (a * 1LL * b) % M; }
int add(int a, int b) { return (0LL + a + b + M + M) % M; }
void ad(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
  if (a < 0) a += M;
}
int fp(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = mult(ret, a);
    b >>= 1;
    a = mult(a, a);
  }
  return ret;
}
void testCase() {
  int n;
  scanf("%d", &n);
  printf("%d\n",
         mult(6, fp(4, (fp(2, n) - 2ll + M - 1ll + M - 1ll) % (M - 1))));
}
int main() {
  int T = 1;
  while (T--) {
    testCase();
  }
}
