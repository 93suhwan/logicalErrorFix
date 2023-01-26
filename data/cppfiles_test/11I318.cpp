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
string s[200000 + 50];
long long n;
long long f(char x) {
  vector<long long> v;
  for (int i = 0; i < (n); i++) {
    long long c = 0;
    for (int j = 0; j < (s[i].size()); j++) {
      if (s[i][j] == x)
        c++;
      else
        c--;
    }
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long ans = 0, sum = 0;
  for (int i = 0; i < (v.size()); i++) {
    if (v[i] + sum > 0) sum += v[i], ans++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int tc = 1;
  cin >> tc;
jump:
  while (tc--) {
    cin >> n;
    for (int i = 0; i < (n); i++) cin >> s[i];
    long long ans = -1;
    for (char x = 'a'; x <= 'e'; x++) ans = max(ans, f(x));
    cout << ans << "\n";
  }
}
