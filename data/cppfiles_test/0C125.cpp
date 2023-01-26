#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
long long cl(long long n, long long d) { return (n + d - 1) / d; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
long long madd(long long a, long long b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
long long mmul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long msub(long long a, long long b) {
  return ((a % 1000000007) - (b % 1000000007) + 1000000007) % 1000000007;
}
long long fpow(long long x, long long y, long long p = 1000000007) {
  x %= p;
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x;
    sum %= p;
    y = y >> 1;
    x = x * x;
    x %= p;
  }
  return sum;
}
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
string bin(long long n) { return bitset<64>(n).to_string(); }
long long countBits(long long number) { return (long long)log2(number) + 1; }
bool is(string temp) {
  char c = temp[0];
  string s((temp).size(), c);
  return s <= temp;
}
void print(std::vector<long long> a) {
  for (auto i : a) cout << i << " ";
  "\n";
}
void LetsSolveIt() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  vector<pair<string, long long>> v;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(make_pair(s, i + 1));
  }
  for (long long j = 1; j < k; j++) {
    if (j % 2 == 0) continue;
    for (long long i = 0; i < n; i++) {
      v[i].first[j] = char(90 - v[i].first[j] + 65);
    }
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  LetsSolveIt();
}
