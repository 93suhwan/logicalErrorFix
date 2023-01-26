#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 998244353;
int fact[N], invfact[N];
int power(int x, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = (1LL * ret * x) % M;
    x = (1LL * x * x) % M;
    p >>= 1;
  }
  return ret;
}
int inv(int x) { return power(x, M - 2); }
void go() {
  fact[0] = 1;
  invfact[0] = inv(fact[0]);
  for (int i = 1; i < N; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % M;
    invfact[i] = inv(fact[i]);
  }
}
int nCr(int n, int c) {
  if (c > n) return 0;
  return 1LL * fact[n] * invfact[n - c] % M * invfact[c] % M;
}
int main() {
  go();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr.rbegin(), arr.rend());
    if (arr[0] == arr[1]) {
      printf("%d\n", fact[n]);
      continue;
    }
    if (arr[0] - arr[1] > 1) {
      printf("0\n");
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[1] == arr[i]) ++cnt;
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
      res = (res + fact[n - 1]) % M;
      res =
          (res -
           (1LL * nCr(n - cnt - 1, n - i) * fact[i - 1] % M * fact[n - i] % M) +
           M) %
          M;
    }
    printf("%d\n", res);
  }
  return 0;
}
