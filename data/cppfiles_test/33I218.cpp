#include <bits/stdc++.h>
using namespace std;
long long po(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = 1;
  if (b % 2 == 0) {
    ans = po(a, b / 2) % 1000000007;
    ans = (ans % 1000000007 * ans % 1000000007) % 1000000007;
  } else {
    ans = po(a, (b - 1) / 2) % 1000000007;
    ans = (ans % 1000000007 * ans % 1000000007 * a) % 1000000007;
  }
  return ans % 1000000007;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
vector<string> tokens;
void separate_string(string line) {
  stringstream check1(line);
  string lav;
  while (getline(check1, lav, '*')) {
    tokens.push_back(lav);
  }
}
vector<long long> divisors;
void get_Divisors(long long n) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        divisors.push_back(n / i);
      } else {
        divisors.push_back(i);
        divisors.push_back(n / i);
      }
    }
  }
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
vector<long long> prim;
void primeFactors(long long n) {
  while (n % 2 == 0) {
    prim.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      prim.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) prim.push_back(n);
}
vector<long long> fact(10005);
long long modInv(long long n, long long p) { return power(n, p - 2, p); }
long long ncr(long long n, long long r) {
  return (n >= r ? (fact[n] * modInv(fact[r], 1000000007)) % 1000000007 *
                       modInv(fact[n - r], 1000000007) % 1000000007
                 : 0);
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ma = INT_MIN;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    ma = max(ma, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == ma) v.push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    if (x - 1 >= 0) {
      ans = max(ans, a[x] * 1LL * a[x - 1]);
    }
    if (x + 1 < n) {
      ans = max(ans, a[x] * 1LL * a[x + 1]);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
