#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1\n";
    exit(0);
  }
  vector<long long> primes(n + 1);
  vector<long long> prime_hash(n + 1, 0);
  iota(primes.begin(), primes.end(), 0);
  for (long long i = 2; i <= n; i++) {
    if (primes[i] == i) {
      for (long long j = i; j <= n; j += i) {
        primes[j] = min(primes[j], i);
      }
      prime_hash[i] = rng();
    }
  }
  vector<long long> fact_hash(n + 1, 0);
  map<long long, long long> rev_fact_hash;
  for (long long i = 2; i <= n; i++) {
    fact_hash[i] = fact_hash[i - 1];
    long long x = i;
    while (x != 1) {
      fact_hash[i] ^= prime_hash[primes[x]];
      x = x / primes[x];
    }
    rev_fact_hash[fact_hash[i]] = i;
  }
  long long cum_hash = 0;
  for (long long i = 1; i <= n; i++) {
    cum_hash ^= fact_hash[i];
  }
  vector<long long> remove;
  if (cum_hash != 0) {
    if (rev_fact_hash.find(cum_hash) != rev_fact_hash.end()) {
      remove.push_back(rev_fact_hash[cum_hash]);
    } else {
      for (long long i = 2; i <= n; i++) {
        long long new_hash = cum_hash ^ fact_hash[i];
        if (rev_fact_hash.find(new_hash) != rev_fact_hash.end()) {
          remove = {i, rev_fact_hash[new_hash]};
          break;
        }
      }
    }
    if ((long long)remove.size() == 0) {
      n--;
      remove = {2, n / 2};
    }
  }
  cout << n - (long long)remove.size() << "\n";
  for (long long i = 1; i <= n; i++) {
    if (find(remove.begin(), remove.end(), i) == remove.end()) cout << i << " ";
  }
  cout << "\n";
  return 0;
}
