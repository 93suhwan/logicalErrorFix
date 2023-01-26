#include <bits/stdc++.h>
using namespace ::std;
long long int MOD = 1000000007;
long long int a[100001], b[100001];
long long int power(long long int base, long long int exp1) {
  if (exp1 == 0) return 1;
  long long int val1 = power(base, exp1 / 2);
  long long int ans = (val1 * val1) % MOD;
  if (exp1 & 1) ans = (ans * base) % MOD;
  return ans;
}
long long int solveRecursively(long long int n, long long int k,
                               long long int numBits) {
  if (k == 0) return 0;
  if (numBits == 1) {
    if (k == 1)
      return 1;
    else
      return 0;
  } else if (double(k) > (double(power(2, numBits - 1) - 1))) {
    return ((((long long int)power(n, numBits - 1)) % MOD) +
            (solveRecursively(n, k - power(2, numBits - 1), numBits - 1) %
             MOD)) %
           MOD;
  } else {
    return solveRecursively(n, k, numBits - 1) % MOD;
  }
}
long long int solve(long long int n, long long int k) {
  long long int interm = k;
  long long int num = 0;
  while (interm > 0) {
    num++;
    interm = interm / 2;
  }
  return solveRecursively(n, k, num);
}
vector<long long int> v;
int main() {
  long long int t, n, m, m2, j, k, i, x;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }
  return 0;
}
