#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long infll = 1e18;
const int M = 1000000007;
const int N = 5e5;
int mult(int a, int b, int m) { return (a * 1LL * b) % m; }
int fp(int a, int b, int m) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = mult(ret, a, m);
    b >>= 1;
    a = mult(a, a, m);
  }
  return ret;
}
void testCase() {
  int n;
  scanf("%d", &n);
  int numberOfNodesWithoutRoot =
      ((long long)fp(2, n, M - 1) - 2 + (M - 1) + (M - 1)) % (M - 1);
  printf("%d\n", mult(6, fp(4, numberOfNodesWithoutRoot, M), M));
}
int main() {
  int T = 1;
  while (T--) {
    testCase();
  }
}
