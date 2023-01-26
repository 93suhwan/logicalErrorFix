#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  if (a % b == 0) {
    return b;
  }
  return (b, a % b);
}
void sieve() {
  long long prime[10000000];
  memset(prime, 1, sizeof(prime));
  for (long long i = 2; i * i <= (long long)1e7 + 7; i++) {
    if (prime[i]) {
      for (long long j = i * i; j < (long long)1e7 + 7; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (long long i = 3; i <= (long long)1e7 + 7; i++) {
    prime[i] += prime[i - 1];
  }
}
long long pow1(long long a, long long b) {
  long long x = 1;
  while (b) {
    if (b & 1) {
      x = (x * a) % (long long)1e9 + 7;
    }
    a = (a * a) % (long long)1e9 + 7;
    b = b >> 1;
  }
  return x;
}
long long max3(long long a, long long b, long long c) {
  if (a >= b && a >= c) {
    return 0;
  }
  if (b >= a && b >= c) {
    return 1;
  }
  return 2;
}
long long min3(long long a, long long b, long long c) {
  if (a <= b && a <= c) {
    return 0;
  }
  if (b <= a && b <= c) {
    return 1;
  }
  return 2;
}
long long maxar(long long ar[], long long n) {
  long long k = ar[0];
  for (long long i = 1; i < n; i++) {
    if (k < ar[i]) {
      k = ar[i];
    }
  }
  return k;
}
long long minar(long long ar[], long long n) {
  long long k = ar[0];
  for (long long i = 1; i < n; i++) {
    if (ar[i] < k) {
      k = ar[i];
    }
  }
  return k;
}
void swap(long long *a, long long *b) {
  long long c = *a;
  *a = *b;
  *b = c;
}
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void factor(long long n, long long k) {
  vector<long long> P;
  while (n % 2 == 0) {
    P.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      n = n / i;
      P.push_back(i);
    }
  }
  if (n > 2) {
    P.push_back(n);
  }
  if (P.size() < k) {
    printf("-1");
    return;
  }
  for (long long i = 0; i < k - 1; i++) {
    printf("%lld ", P[i]);
  }
}
void printmat(vector<vector<long long> > &G, long long n, long long m) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << G[i][j] << " ";
    }
    cout << "\n";
  }
}
long long mulmod(long long a, long long b, long long m) {
  long long x = 0, y = a % m;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % m;
    }
    y = (y * 2) % m;
    b /= 2;
  }
  return x % m;
}
long long modulo(long long base, long long e, long long m) {
  long long x = 1;
  long long y = base;
  while (e > 0) {
    if (e % 2 == 1) x = (x * y) % m;
    y = (y * y) % m;
    e = e / 2;
  }
  return x % m;
}
bool Miller(long long p, long long iteration) {
  if (p < 2) {
    return false;
  }
  if (p != 2 && p % 2 == 0) {
    return false;
  }
  long long s = p - 1;
  while (s % 2 == 0) {
    s /= 2;
  }
  for (long long i = 0; i < iteration; i++) {
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = modulo(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}
bool check(long long a[], long long n) {
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      return false;
    }
  }
  return true;
}
void fun(long long *a, long long *b) {
  if (*a > *b) {
    long long k = *a;
    *a = *b;
    *b = k;
  }
}
long long XOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
vector<long long> ans;
void pre() {
  long long x = 0;
  ans.push_back(0);
  for (long long i = 1; i <= 300000; i++) {
    ans.push_back(x);
    x ^= i;
  }
}
long long fact(long long n);
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
void solve() {
  string s;
  cin >> s;
  long long ans = 0;
  long long p = 0;
  while (p < s.length()) {
    long long fl = 0;
    while (s[p] == '0') {
      if (fl == 0) {
        ans++;
        fl = 1;
      }
      p++;
    }
    while (s[p] == '1') {
      p++;
    }
  }
  cout << min(ans, (long long)2) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
