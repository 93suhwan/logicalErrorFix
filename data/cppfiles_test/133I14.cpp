#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long log_a_to_base_b(long long a, long long b) { return log(a) / log(b); }
bool isPrime(long long n) {
  if (n == 1) {
    return false;
  }
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
vector<long long> prime_fact(long long n) {
  vector<long long> v;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      v.push_back(i);
    }
  if (n > 1) v.push_back(n);
  return v;
}
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2)
      res *= a, n--;
    else
      a *= a, n /= 2;
  }
  return res;
}
long long euler_totient(long long n) {
  long long res = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res /= i;
      res *= (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res /= n, res *= (n - 1);
  return res;
}
bool isKthBitSet(long long n, long long k) {
  if (n & (1 << k))
    return true;
  else
    return false;
}
long long no_of_set_bits(long long n) {
  long long cnt = 0;
  while (n > 0) {
    cnt++;
    n = n & (n - 1);
  }
  return cnt;
}
bool is_perfect_square(long long n) {
  if (n < 0) return false;
  long long root(round(sqrt(n)));
  return n == root * root;
}
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  init();
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ab = 0;
    long long bb = 0;
    vector<string> v(n - 2);
    for (auto &i : v) {
      cin >> i;
      if (i == "ab" || i == "ba")
        ab = 1;
      else if (i == "bb")
        bb = 1;
    }
    string s;
    for (long long i = 0; i < n; i++) s += "a";
    if (ab) s[1] = 'b';
    if (bb) {
      s[n - 2] = 'b';
      s[n - 1] = 'b';
    }
    cout << s << "\n";
  }
  return 0;
}
