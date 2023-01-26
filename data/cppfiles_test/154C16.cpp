#include <bits/stdc++.h>
using namespace std;
bitset<1000005> prime;
vector<long long> primes;
void sieve(long long n) {
  prime.set();
  prime[0] = prime[1] = 0;
  for (long long p = 2; p * p <= n + 1; p++) {
    if (prime[p]) {
      for (long long i = p * p; i <= n + 1; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) primes.push_back(p);
}
void solve() {
  long long a[3], f;
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a, a + 3);
  f = 0;
  do {
    if (a[0] + a[1] == a[2])
      f = 1;
    else if (a[0] == a[1] && a[2] % 2 == 0)
      f = 1;
  } while (next_permutation(a, a + 3));
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    ;
    solve();
  }
  return 0;
}
