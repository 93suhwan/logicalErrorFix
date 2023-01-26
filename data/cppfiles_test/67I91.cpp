#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
using vi = vector<long long>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  if (p == 1) return 0;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
long long random_modul() {
  uniform_int_distribution<long long> u1(1e9, 2e9);
  long long pepega = u1(rnd);
  while (prime(pepega) != 1) pepega = u1(rnd);
  return pepega;
}
template <typename T1>
void ifmax(T1& max, T1 kek) {
  if (kek > max) max = kek;
  return;
}
template <typename T1>
void ifmin(T1& min, T1 kek) {
  if (kek < min) min = kek;
  return;
}
template <typename T1>
istream& operator>>(std::istream& in, pair<T1, T1>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1>
istream& operator>>(std::istream& in, vector<T1>& a) {
  for (long long i = 0; i < a.size(); i++) in >> a[i];
  return in;
}
template <typename T1>
ostream& operator<<(std::ostream& out, vector<T1>& b) {
  for (long long i = 0; i < b.size(); i++) out << b[i] << " ";
  out << "\n";
  return out;
}
template <typename T1>
void sort(vector<T1>& m) {
  sort(m.begin(), m.end());
}
template <typename T1>
void reverse(vector<T1>& m) {
  reverse(m.begin(), m.end());
}
long long mod = 1000000007;
long long fac[200005];
long long inv_fac[200005];
long long co(long long a, long long b) {
  long long ans = 1;
  ans *= fac[b];
  ans *= inv_fac[b - a];
  ans %= mod;
  ans *= inv_fac[a];
  return ans % mod;
}
bool is_sorted(vector<long long> a) {
  long long check = 1;
  for (long long i = 0; i + 1 < a.size(); i++)
    if (a[i + 1] < a[i]) check = 0;
  if (check)
    return true;
  else
    return false;
}
void solve() {
  long long a;
  long double kek;
  cin >> a >> kek;
  long double eps = 1e-7;
  for (long long i = 1; i <= a; i++) {
    long long left = a - i;
    long double pick0 = (long double)(i * (i - 1) * (i - 2)) /
                        (long double)(a * (a - 1) * (a - 2));
    long double pick3 = (long double)(left * (left - 1) * (left - 2)) /
                        (long double)(a * (a - 1) * (a - 2));
    long double pick2 = (long double)(3 * left * (left - 1) * i) /
                        (long double)(a * (a - 1) * (a - 2));
    long double pick1 = (long double)(3 * left * (i) * (i - 1)) /
                        (long double)(a * (a - 1) * (a - 2));
    long double good = pick3;
    good += pick2 * (long double)(1) / (long double)(2);
    good = 1 - good;
    if (good + eps > kek) {
      cout << i << "\n";
      return;
      ;
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long multitest = 0;
  long long tututu;
  tututu = 1;
  long long combinatorics = 0;
  if (combinatorics) {
    fac[1] = 1;
    fac[0] = 1;
    for (long long i = 2; i < 200005; i++) {
      fac[i] = fac[i - 1] * i;
      fac[i] %= mod;
    }
    for (long long i = 0; i < 200005; i++) {
      inv_fac[i] = inv(fac[i], mod);
    }
  }
  if (multitest) cin >> tututu;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
