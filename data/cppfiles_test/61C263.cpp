#include <bits/stdc++.h>
using namespace std;
long long primes[1000001];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieveOfEratosthenes(long long N) {
  N += 2;
  primes[1] = 1;
  for (long long i = 2; i < N; i++) primes[i] = i;
  for (long long i = 4; i < N; i += 2) primes[i] = 2;
  for (long long i = 3; i * i < N; i++) {
    if (primes[i] == i) {
      for (long long j = i * i; j < N; j += i)
        if (primes[j] == j) primes[j] = i;
    }
  }
}
long long findPrimeFactors(long long num) {
  long long c = 0;
  sieveOfEratosthenes(num);
  long long factor;
  while (num != 1) {
    factor = primes[num];
    c++;
    num /= factor;
  }
  return c;
}
bool find(vector<long long> v, long long start, long long end,
          long long value) {
  if (start > end) return false;
  long long mid = (start + end) / 2;
  if (v[mid] == value) return true;
  if (v[mid] < value)
    return find(v, mid + 1, end, value);
  else
    return find(v, start, mid - 1, value);
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  long i, j, k, n, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    i = 0;
    j = n - 1;
    while (s[i] == '?') {
      i++;
    }
    for (k = i - 1; k >= 0; k--) {
      if (k + 1 < n && s[k + 1] == 'R') {
        s[k] = 'B';
      } else {
        s[k] = 'R';
      }
    }
    while (s[j] == '?') {
      j--;
    }
    for (k = j + 1; k < n; k++) {
      if (k - 1 >= 0 && s[k - 1] == 'R')
        s[k] = 'B';
      else
        s[k] = 'R';
    }
    for (k = i; k <= j; k++) {
      if (s[k] == '?') {
        if (s[k - 1] == 'R')
          s[k] = 'B';
        else
          s[k] = 'R';
      }
    }
    cout << s << "\n";
  }
}
