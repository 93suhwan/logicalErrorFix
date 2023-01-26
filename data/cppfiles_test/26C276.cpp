#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 110, P = 131;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const double eps = 1e-8;
long long fact[N * 2];
void init() {
  fact[2] = 1;
  for (int i = 3; i < 2 * N; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fact[2 * n]);
  }
  return 0;
}
