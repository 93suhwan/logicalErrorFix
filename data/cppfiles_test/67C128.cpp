#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long> >;
template <typename T, typename Y>
istream& operator>>(istream& is, pair<T, Y>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename Y>
ostream& operator<<(ostream& os, pair<T, Y> p) {
  os << p.first << ' ' << p.second << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
const long long NUM = 1000030;
const long long N = 10000000;
vector<long long> lp, sieve;
vector<long long> pr;
void primefactor();
long long binpow(long long a, long long b);
long long binpow(long long a, long long b, long long mod);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool comp(long long a, long long b);
long long inversemod(long long a, long long mod);
void calc_sieve();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void test() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  long long n = (b - a) * 2;
  if (c > n || a > n || b > n) {
    cout << -1 << "\n";
    return;
  } else {
    if (c + n / 2 <= n)
      cout << c + n / 2 << endl;
    else
      cout << c - n / 2 << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) test();
  return 0;
}
void calc_sieve() {
  sieve.resize(NUM + 1, 0);
  for (long long x = 2; x <= NUM; x++) {
    if (sieve[x]) continue;
    for (long long u = x; u <= NUM; u += x) {
      sieve[u] = x;
    }
  }
}
void primefactor() {
  lp.resize(N + 1, 0);
  for (long long i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (long long j = 0;
         j < (long long)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
bool comp(long long a, long long b) { return a > b; }
long long inversemod(long long a, long long mod) {
  return binpow(a, mod - 2, mod);
}
