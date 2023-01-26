#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
bool isPrime(long long n);
long long modInv(long long a, long long b);
long long gcdExtended(long long a, long long b, long long *x, long long *y);
long long mpower(long long a, long long b, long long p);
bool sorted(vector<long long> v, long long n, long long strict);
const long long inf = (long long)1e17;
const long long N = (long long)3e5 + 5;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  map<long long, vector<long long> > same;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    same[v[i]].push_back(i);
  }
  vector<long long> colored_(n, 0);
  for (auto color : same) {
    long long current_color = 1;
    for (auto positions : color.second) {
      colored_[positions] = current_color;
      current_color += 1;
      if (current_color > k) break;
    }
  }
  for (auto i : colored_) cout << i << ' ';
  ;
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  clock_t start, end;
  start = clock();
  long long x;
  cin >> x;
  while (x--) {
    solve();
  };
  end = clock();
  double time_taken = double(end - start) / (double)CLOCKS_PER_SEC;
  return 0;
}
long long modInv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = (x % m + m) % m;
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
long long mpower(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (long long i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool sorted(vector<long long> v, long long n, long long strict) {
  if (n <= 1) return 1;
  for (long long i = 1; i < n; i++) {
    if (strict) {
      if (v[i] <= v[i - 1]) return 0;
    } else {
      if (v[i] < v[i - 1]) return 0;
    }
  }
  return 1;
}
