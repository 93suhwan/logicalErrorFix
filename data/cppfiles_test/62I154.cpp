#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
string yon[] = {"NO", "YES"};
const long long N = 100005;
const long long mod = 1000000007;
void scan1(vector<long long> &v, long long n) {
  for (auto &i : v) cin >> i;
}
void print(vector<long long> v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pow(long long a, long long b, long long r) {
  a %= r;
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % r;
    a = (a * a) % r;
    b >>= 1;
  }
  return res;
}
long long mod_inverse(long long a, long long p) { return pow(a, p - 2, p); }
long double dist(pair<long long, long long> a, pair<long long, long long> b) {
  long double x = (a.first - b.first) * (a.first - b.first) +
                  (a.second - b.second) * (a.second - b.second);
  return sqrt(x);
}
bool is_prime(long long n) {
  if (n == 1) return false;
  for (long long i = 2; i < (long long)sqrt(n) + 1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long fac(long long n) {
  if (n < 2) return 1;
  return n * fac(n - 1);
}
long long nCr(long long n, long long r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long res = 1;
  for (long long i = 0; i < r; i++) {
    res = res * (n - i) / (i + 1);
  }
  return res;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v(n), res(n + 1);
    res[n] = n + 1;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      res[i] = i + 1;
    }
    if (v[n - 1] == 0) {
      print(res);
      continue;
    }
    bool flag = false;
    for (long long i = 0; i < n - 1; i++) {
      if (v[i] == 0 && v[i + 1] == 1) {
        res[i + 1] = n + 1;
        res[i + 2] = i + 2;
        for (long long j = i + 3; j < n + 1; j++) {
          res[j] -= 1;
        }
        flag = true;
        break;
      }
    }
    if (flag) {
      print(res);
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
