#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mod = 1e9 + 7;
long long fact[N];
void init() {
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
}
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    long long ans = 2 * x;
    long long sum = 0;
    sum = fact[ans] * qmi(2, mod - 2) % mod;
    printf("%lld\n", sum);
  }
  return 0;
}
