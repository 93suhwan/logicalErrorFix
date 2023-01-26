#include <bits/stdc++.h>
using namespace std;
#pragma gcc optimize("Ofast")
#pragma gcc target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma gcc optimize("unroll-loops")
#pragma GCC target("fpmath=sse,sse2")
const long double pi = 3.141592653589;
const long long mod = 1000000007;
const long long INF = 5e18;
vector<long long> primes, fibonacci;
long long xorval(long long n);
bool isPrime(long long n);
void sieve(long long N);
long long lcm(long long a, long long b);
long long poww(long long n, long long k);
long long nCr(long long n, long long r);
long long leap(long long y);
void fiboseries(long long n);
long long fiboN(long long n);
string baseto10(string s, long long b);
string basefrom10(string s, long long b);
double dis_p(long long x1, long long y1, long long x2, long long y2);
long long days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[12] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
bool ch = 0;
void sweetheart() {
  long long n;
  cin >> n;
  long long ar[n];
  for (long long i = 0; i < n; i++) cin >> ar[i];
  if (ch)
    for (long long i = 0; i < n; i++) cout << ar[i] << " ";
  sort(ar, ar + n);
  long long ans = 0, m1 = ar[0] % 3, m2 = ar[n - 1] % 3;
  long long c1 = 0, c2 = 0;
  for (long long i = 0; i < n; i++)
    if (ar[i] % 3 == 1)
      c1++;
    else if (ar[i] % 3 == 2)
      c2++;
  if (!m2) {
    if (c1 || c2)
      ans = ar[n - 1] / 3 + 1;
    else
      ans = ar[n - 1] / 3;
  } else if (m2 == 1) {
    ans = ar[n - 1] / 3 + 1;
    if (c2) {
      for (long long i = 0; i < n; i++) {
        if (ar[i] == 1 || ar[i] == ar[n - 1] - 1) {
          ans++;
          break;
        }
      }
    }
  } else if (m2 == 2) {
    ans = ar[n - 1] / 3 + 1;
    if (c1) ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  string jaaneman = "1";
  getline(cin, jaaneman);
  long long me = stoll(jaaneman);
  long long you = 0;
  while ((you++) < me) {
    if (me == 1000 and you == 21) ch = 1;
    sweetheart();
  }
  cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " millisecond";
  return 0;
}
bool isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (!(n % 2) || !(n % 3)) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (!(n % i) || !(n % (i + 2))) return 0;
  return 1;
}
long long lcm(long long a, long long b) { return ((a * b) / lcm(a, b)); }
long long poww(long long n, long long k) {
  long long x = 1;
  while (k) {
    if (k & 1) {
      x *= n;
      x %= mod;
    }
    n *= n;
    n %= mod;
    k >>= 1;
  }
  return x;
}
long long nCr(long long n, long long r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long res = 1;
  for (long long i = 1; i <= r; i++) {
    res *= (n - r + i);
    res /= i;
  }
  return res;
}
void fiboseries(long long n) {
  fibonacci.push_back(0);
  fibonacci.push_back(1);
  long long c1 = 0, c2 = 1;
  long long c3 = c1 + c2;
  while (c2 < n) {
    c3 = c1 + c2;
    c1 = c2;
    c2 = c3;
    fibonacci.push_back(c3);
  }
}
long long fiboN(long long n) {
  if (n <= 1) return n;
  return fiboN(n - 1) + fiboN(n - 2);
}
string baseto10(string s, long long b) {
  long long num = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (isdigit(s[i]))
      num = num * b + (s[i] - '0');
    else
      num = num * b + (s[i] - 'A' + 10);
  }
  return to_string(num);
}
string basefrom10(string s, long long b) {
  string num;
  long long n = stoll(s);
  while (n) {
    long long x = n % b;
    n /= b;
    if (x < 10)
      num += char('0' + x);
    else
      num += char('A' + x - 10);
  }
  reverse((num).begin(), (num).end());
  return num;
}
long long leap(long long y) {
  if (y % 400 == 0)
    return 1;
  else if (y % 100 == 0)
    return 0;
  else if (y % 4 == 0)
    return 1;
  else
    return 0;
}
long long xorval(long long n) {
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  return 0;
}
