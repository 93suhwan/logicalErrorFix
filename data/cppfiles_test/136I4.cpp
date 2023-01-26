#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long ncr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
vector<long long> FA, INV;
void fact(long long n, long long M) {
  FA.resize(n + 1);
  FA[0] = 1;
  for (long long i = 1; i <= n; i++) {
    FA[i] = (FA[i - 1] * i) % M;
  }
}
void icalc(long long n, long long M) {
  INV.resize(n + 1);
  INV[n] = mod_inv(FA[n], M);
  for (long long i = n - 1; i >= 0; i--) {
    INV[i] = (INV[i + 1] * (i + 1)) % M;
  }
}
long long ncrm(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long a = FA[n];
  a *= INV[r];
  a %= M;
  a *= INV[n - r];
  a %= M;
  return a;
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
ifstream fin;
ofstream fout;
template <typename T>
ostream& operator<<(ostream& output, const vector<T>& data) {
  for (const T& x : data) output << x << " ";
  return output;
}
template <typename T>
istream& operator>>(istream& input, vector<T>& data) {
  for (auto& item : data) {
    input >> item;
  }
  return input;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    s += v[i];
  }
  long long t = n * (n + 1) / 2;
  s = s / t;
  if (n <= s) {
    cout << "YES" << '\n';
    for (long long i = 0; i < n - 1; i++) {
      cout << "1"
           << " ";
    }
    cout << s - (n - 1) << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
