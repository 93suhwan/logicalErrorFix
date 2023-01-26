#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1000000007;
const int maxn = 100005;
vector<int> primes;
int phicache[maxn];
int counts[maxn];
vector<int> divisors[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<bool> sieve(maxn, 1);
  for (int i = 2; i < maxn; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      int j = 2 * i;
      while (j < maxn) {
        sieve[j] = 0;
        j += i;
      }
    }
  }
  for (int i = 1; i < maxn; i++) {
    counts[i] = 0;
    int j = i;
    while (j < maxn) {
      divisors[j].push_back(i);
      j += i;
    }
  }
  for (int i = 1; i < maxn; i++) {
    phicache[i] = i;
  }
  for (int p : primes) {
    int j = p;
    while (j < maxn) {
      phicache[j] = (p - 1) * (phicache[j] / p);
      j += p;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int d = 1; d <= n; d++) {
    vector<int> seen;
    for (int j = d - 1; j < n; j += d) {
      for (int div : divisors[a[j]]) {
        if (!counts[div]++) seen.push_back(div);
      }
    }
    for (int div : seen) {
      long long count = counts[div];
      ans += (count * count * phicache[div] * phicache[d]) % MOD;
      counts[div] = 0;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
