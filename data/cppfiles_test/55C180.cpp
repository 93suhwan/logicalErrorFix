#include <bits/stdc++.h>
using namespace std;
long long k, MOD = 1e9 + 7;
long long p(long long a, long long b) {
  if (b == 0) return 1;
  long long child = p(a, b / 2);
  long long t = (child * child) % MOD;
  if (b % 2)
    return (t * a) % MOD;
  else
    return t % MOD;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ;
  cin >> k;
  cout << (p(4, ((1LL << k) - 2)) % MOD * 6 % MOD) % MOD;
}
