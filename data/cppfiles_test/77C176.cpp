#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 10;
long long sol[MAXN];
long long sum[MAXN];
long long sub_mod(long long a, long long b, long long m) {
  if (a >= b)
    return a - b;
  else
    return m - b + a;
}
long long add_mod(long long a, long long b, long long m) {
  if (0 == b) return a;
  b = m - b;
  if (a >= b)
    return a - b;
  else
    return m - b + a;
}
int main() {
  long long n, m;
  cin >> n >> m;
  sol[n] = 1;
  sum[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    sol[i] = sum[i + 1];
    for (long long j = 2;; j++) {
      if (i * j > n) break;
      if (i * j + j <= n) {
        sol[i] = sub_mod(add_mod(sol[i], sum[i * j], m), sum[i * j + j], m);
      } else {
        sol[i] = sub_mod(add_mod(sol[i], sum[i * j], m), 0, m);
      }
    }
    sum[i] = add_mod(sol[i], sum[i + 1], m);
  }
  cout << sol[1] << '\n';
  return 0;
}
