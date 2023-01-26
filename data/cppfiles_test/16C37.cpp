#include <bits/stdc++.h>
using namespace std;
int cs = 1;
void file();
void time();
int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool valid(int r, int c, int n, int m) {
  return (r >= 0 && r < n && c >= 0 && c < m);
}
long long bigMod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (long long)ret;
}
long long modInverse(long long a, long long M) { return bigMod(a, M - 2, M); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
vector<long long> findPrimeFactors(long long n) {
  vector<long long> primeFactors;
  while (n % 2 == 0) primeFactors.push_back(2), n = n / 2;
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      primeFactors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) primeFactors.push_back(n);
  return primeFactors;
}
vector<long long> allDivisiors(long long n) {
  vector<long long> divisors;
  long long limit = sqrt(n + 1);
  for (long long i = 1; i <= limit; i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisors.push_back(i);
      else
        divisors.push_back(i), divisors.push_back(n / i);
    }
  }
  return divisors;
}
bool isPrime(long long n) {
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0) return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long rem = 1;
  while (p) {
    if (p & 1) rem = rem * n;
    n = n * n;
    p = p / 2;
  }
  return rem;
}
bool isPalindrome(string s) {
  int N = s.size();
  for (int i = 0; i < N / 2; i++) {
    if (s[i] != s[N - 1 - i]) return 0;
  }
  return 1;
}
long long onbit(long long N, long long pos) { return N = N | (1 << pos); }
long long offbit(long long N, long long pos) { return N = N & ~(1 << pos); }
long long flipbit(long long N, long long pos) { return N = N ^ (1 << pos); }
bool checkbit(long long N, long long pos) { return (bool)(N & (1 << pos)); }
const long long inf = 2000000000;
const long long infLL = 9000000000000000000;
const long long lim = 1e10;
const long long Mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  priority_queue<pair<long long, long long> > pq;
  for (int i = 1; i <= n; i++) {
    long long rem;
    cin >> rem;
    pq.push({rem, i});
  }
  vector<pair<long long, long long> > ans;
  while (1) {
    if (pq.size() < 2) break;
    long long a = pq.top().first, x = pq.top().second;
    pq.pop();
    long long b = pq.top().first, y = pq.top().second;
    pq.pop();
    if (a > 0 && b > 0) {
      ans.push_back({x, y});
      a--, b--;
    }
    if (a > 0) pq.push({a, x});
    if (b > 0) pq.push({b, y});
  }
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it.first << " " << it.second << "\n";
}
int main() {
  clock_t tStstoret = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  file();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
void file() {}
