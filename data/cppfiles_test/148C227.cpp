#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long INF = 2e18;
void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void printll(long long a[], long long n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
int prime[1000005];
vector<int> allPrimes;
void sieve() {
  memset(prime, 0, sizeof(prime));
  prime[0] = prime[1] = 1;
  for (int i = 4; i < 1000005; i += 2) prime[i] = 1;
  for (int i = 3; i * i < 1000005; i += 2) {
    if (prime[i] == 0) {
      for (int j = i * i; j < 1000005; j += i) prime[j] = 1;
    }
  }
  for (int i = 2; i < 1000005; i++)
    if (prime[i] == 0) allPrimes.push_back(i);
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
long long nsum(long long n) { return (n * (n + 1)) / 2; }
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * n;
    n = n * n;
    p = p / 2;
  }
  return ans;
}
long long mpower(long long n, long long p, long long mod) {
  if (p == -1) p = mod - 2;
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * n) % mod;
    n = (n * n) % mod;
    p = p / 2;
  }
  return ans;
}
bool isPalindrome(string s) {
  int N = s.size();
  for (int i = 0; i < (N / 2); i++) {
    if (s[i] != s[N - 1 - i]) return 0;
  }
  return 1;
}
long long onbit(long long N, long long pos) { return N = N | (1 << pos); }
long long offbit(long long N, long long pos) { return N = N & ~(1 << pos); }
long long flipbit(long long N, long long pos) { return N = N ^ (1 << pos); }
bool checkbit(long long N, long long pos) { return (bool)(N & (1 << pos)); }
long long mod = 1e9 + 7;
long long f(vector<pair<long long, long long>> a,
            vector<pair<long long, long long>> b) {
  long long x1 = a[0].first;
  long long y1 = a[0].second;
  long long x3 = a[a.size() - 1].first;
  long long y3 = a[a.size() - 1].second;
  long long ans = 0;
  for (int i = 0; i < (b.size()); i++) {
    long long x2 = b[i].first;
    long long y2 = b[i].second;
    long long tem = x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
    tem = abs(tem);
    ans = max(ans, tem);
  }
  return ans;
}
void solve() {
  long long w, h;
  cin >> w >> h;
  vector<pair<long long, long long>> down, left, up, right;
  long long ans = 0;
  long long x;
  cin >> x;
  for (int i = 0; i < (x); i++) {
    long long y;
    cin >> y;
    down.push_back({y, 0});
  }
  cin >> x;
  for (int i = 0; i < (x); i++) {
    long long y;
    cin >> y;
    up.push_back({y, h});
  }
  cin >> x;
  for (int i = 0; i < (x); i++) {
    long long y;
    cin >> y;
    left.push_back({0, y});
  }
  cin >> x;
  for (int i = 0; i < (x); i++) {
    long long y;
    cin >> y;
    right.push_back({w, y});
  }
  sort(down.begin(), down.end());
  sort(up.begin(), up.end());
  sort(right.begin(), right.end());
  sort(left.begin(), left.end());
  ans = max(ans, f(down, up));
  ans = max(ans, f(up, down));
  ans = max(ans, f(right, left));
  ans = max(ans, f(left, right));
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
}
