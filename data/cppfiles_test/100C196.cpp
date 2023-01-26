#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long F[N];
const long long M = 998244353;
long long amodb(long long a) { return a - (a / M * M); }
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = bigmod(a, b / 2);
  ans = amodb(ans * ans);
  if (b % 2) {
    ans = amodb(ans * a);
  }
  return ans;
}
void precal() {
  F[0] = 1;
  for (long long i = 1; i < N; i++) {
    F[i] = ((F[i - 1] % M) * (i % M)) % M;
  }
}
int main() {
  long long t = 1;
  precal();
  scanf("%lld", &t);
  while (t--) {
    long long n, i, j, k = 0, mx = 0, smx, cnt = 0, l, r, ans = 0;
    scanf("%lld", &n);
    vector<long long> v(n);
    for (i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
    }
    sort(v.rbegin(), v.rend());
    if (v[0] - v[1] > 1) {
      printf("0\n");
    } else if (v[0] - v[1] == 0) {
      printf("%lld\n", F[n]);
    } else {
      for (i = 1; i < n; i++) {
        if (v[i] == v[1]) {
          k++;
        }
      }
      long long baad = (F[n] * bigmod(k + 1, M - 2)) % M;
      ans = (F[n] - baad) % M;
      ans += M;
      ans %= M;
      printf("%lld\n", ans);
    }
  }
}
