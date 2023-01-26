#include <bits/stdc++.h>
using namespace std;
long long mod1(long long x) {
  if (x >= 0) {
    return x;
  }
  return -x;
}
vector<long long> countDigit(long long n) {
  vector<long long> ret;
  while (n != 0) {
    ret.push_back(n % 10);
    n = n / 10;
  }
  return ret;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm1(long long a, long long b) { return (a / gcd(a, b)) * b; }
bool prime[1000000];
void SieveOfEratosthenes(long long n) {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool PowerOfFour(long long num) {
  if (num <= 0) return false;
  while (num != 1) {
    if (num % 4 != 0) return false;
    num = num / 4;
  }
  return true;
}
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first != p2.first) {
    return p1.first > p2.first;
  } else {
    p1.second > p2.second;
  }
}
bool compare1(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.second != p2.second) {
    return p1.second < p2.second;
  } else {
    p1.first < p2.first;
  }
}
bool isPalindrome(string str) {
  long long l = 0;
  long long h = str.size() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
vector<long long> primef(long long n) {
  vector<long long> v;
  if (n == 1) {
    return v;
  }
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
long long mod = 1000000007;
long long fact1(long long x) {
  if (x < 2) {
    return 1;
  }
  return (x * fact1(x - 1)) % mod;
}
long long power1(long long x, long long y) {
  long long r = 1;
  while (y > 0) {
    r = (r % mod * x % mod) % mod;
    y--;
  }
  return r;
}
bool isp(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
bool isPri(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long power2(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long b, long long m) {
  long long x, y;
  long long g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long ask(long long val) {
  cout << val << endl;
  fflush(stdout);
  long long x;
  cin >> x;
  return x;
}
void solve() {
  string s, t;
  cin >> s >> t;
  long long st = 0;
  long long n = s.size();
  long long m = t.size();
  long long o = n % 2;
  long long e = m % 2;
  if (o != e) {
    st++;
  }
  long long ind = 0;
  while (st < n && ind < m) {
    if (s[st] == t[ind]) {
      st++;
      ind++;
    } else {
      st = st + 2;
    }
  }
  if (ind == m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
