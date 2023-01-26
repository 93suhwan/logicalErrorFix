#include <bits/stdc++.h>
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
using namespace std;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const long long int INF = 1e18;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 1000023;
long long int InvFact[N];
long long int InvNum[N];
long long int fact[N];
void InvOfNum(long long int p) {
  InvNum[0] = 1;
  InvNum[1] = 1;
  for (long long int i = 2; i < N; i++) {
    InvNum[i] = InvNum[p % i] * (p - p / i) % p;
  }
}
void InverseofFactorial(long long int p) {
  InvFact[0] = 1;
  InvFact[1] = 1;
  for (long long int i = 2; i < N; i++) {
    InvFact[i] = (InvFact[i - 1] * InvNum[i]) % p;
  }
}
void factorial(long long int p) {
  fact[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long int nCr_mod_p(long long int N, long long int R, long long int p) {
  long long int ans = ((fact[N] * InvFact[R]) % p * InvFact[N - R]) % p;
  return ans;
}
void solve() {
  long long int n, k, i;
  cin >> n >> k;
  long long int fact = 0;
  if (n % 2) fact++;
  fact = fact + power(2, n - 1);
  fact %= 1000000007;
  long long int ans = (power(fact, k));
  if ((n % 2) == 0) {
    long long int extra = 0;
    for (i = 1; i < k; i += 2) {
      extra = extra + (nCr_mod_p(k, i, 1000000007)) *
                          (power(2, ((i * (n - 1)) % 1000000007)));
      extra %= 1000000007;
    }
    extra /= 2;
    ans = ans + extra;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int p = 1000000007;
  InvOfNum(p);
  InverseofFactorial(p);
  factorial(p);
  int TC = 1, te = 0;
  cin >> TC;
  while (te++ < TC) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
