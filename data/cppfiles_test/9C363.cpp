#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
int fact[N];
void precalc() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mod_mul(fact[i - 1], i, 1000000007);
  }
}
long long mod(long long x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long inv(long long x) { return expo(x, 1000000007 - 2, 1000000007); }
long long divide(long long a, long long b) {
  return mod_mul(a, inv(b), 1000000007);
}
long long nCr(long long n, long long r) {
  return divide(fact[n], mod_mul(fact[r], fact[n - r], 1000000007));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long> m;
    long long cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      m[s[i]]++;
    }
    for (auto x : m) {
      if (x.second <= 2)
        cnt += x.second;
      else
        cnt += 2;
    }
    if (cnt % 2 != 0) cnt--;
    cout << cnt / 2 << ("\n");
  }
}
