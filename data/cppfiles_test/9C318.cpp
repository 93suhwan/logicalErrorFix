#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
vector<long long> b(100000);
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
void sieve(long long upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  for (long long i = 2; i <= _sieve_size; i++)
    if (bs[i]) {
      for (long long j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      primes.push_back((int)i);
    }
}
bool isPrime(long long N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}
bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count = 0;
    vector<int> v(123);
    for (int i = 0; i < s.size(); i++) {
      v[s[i]]++;
      if (v[s[i]] < 3) {
        count++;
      }
    }
    cout << count / 2 << endl;
  }
  return 0;
}
