#include <bits/stdc++.h>
using namespace std;
bool sortbyfir(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
bool sr(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first < b.first;
}
bool compmx(int a, int b) { return (a < b); }
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool is_prime(long long int x) {
  if (x == 1) return false;
  if (x == 2 || x == 3) return true;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
vector<long long int> primes;
void getPrimes() {
  vector<bool> p(1001, true);
  for (long long int i = 2; i * i <= 1000; i++) {
    if (p[i]) {
      for (long long int j = i * i; j <= 1000; j += i) {
        p[j] = false;
      }
    }
  }
  for (long long int i = 2; i <= 1000; i++) {
    if (p[i]) {
      primes.push_back(i);
    }
  }
}
long long int dx[] = {-1, 0, 1, 0};
long long int dy[] = {0, -1, 0, 1};
long long int const N = 2 * 100000 + 1;
long long int power(long long int a, long long int b) {
  long long int res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b /= 2ll;
  }
  return res;
}
long long int fact[N], invfact[N];
void factorial() {
  fact[0] = fact[1] = 1;
  for (long long int i = 2; i < N; i++) fact[i] = (i * fact[i - 1]) % 998244353;
  invfact[N - 1] = power(fact[N - 1], 998244353 - 2);
  for (long long int i = N - 2; i >= 0; i--)
    invfact[i] = (invfact[i + 1] * (i + 1)) % 998244353;
}
long long int nCr(long long int n, long long int r) {
  return (((fact[n] * invfact[r]) % 998244353) * invfact[n - r]) % 998244353;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int Q;
  cin >> Q;
  factorial();
  while (Q--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    sort((a).begin(), (a).end());
    if (a[n - 1] - a[n - 2] == 0)
      cout << fact[n] % 998244353 << endl;
    else if (a[n - 1] - a[n - 2] == 1) {
      long long int c = 0;
      for (long long int i = 0; i < n; i++)
        if (a[i] == a[n - 2]) c++;
      long long int l = nCr(n, c + 1) % 998244353;
      l = (l * fact[c]) % 998244353;
      l = (l * fact[n - (c + 1)]) % 998244353;
      long long int ans = (fact[n] % 998244353 - l + 998244353) % 998244353;
      cout << ans << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
