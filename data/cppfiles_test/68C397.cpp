#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const long long mod = 1e9 + 7;
const long double PII = acos(-1);
long long fpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
void ___print(int x) { cout << x; }
void ___print(long long x) { cout << x; }
void ___print(string x) { cout << x; }
void ___print(double x) { cout << x; }
void ___print(long double x) { cout << x; }
void ___print(float x) { cout << x; }
void ___print(char x) { cout << x; }
template <class T, class V>
void ___print(pair<T, V> p) {
  cout << "{ ";
  ___print(p.first);
  cout << ",";
  ___print(p.second);
  cout << " }";
}
template <class T>
void ___print(vector<T> v) {
  cout << "[ ";
  for (T tmp : v) {
    ___print(tmp);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void ___print(set<T> s) {
  cout << "[ ";
  for (T tmp : s) {
    ___print(tmp);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void ___print(multiset<T> s) {
  cout << "[ ";
  for (T tmp : s) {
    ___print(tmp);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void ___print(map<T, V> mp) {
  cout << "[ ";
  for (auto tmp : mp) {
    ___print(tmp);
    cout << "\n";
  }
  cout << "]";
}
long long mod_fpow(long long a, long long b) {
  long long res = 1;
  a = (a % mod);
  if (a < 0) a += mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long mod_inv(long long a) { return mod_fpow(a, mod - 2); }
long long mod_add(long long a, long long b) {
  long long res = (a + b) % mod;
  if (res < 0) res += mod;
  return res;
}
long long mod_mul(long long a, long long b) {
  long long res = ((a % mod) * (b % mod)) % mod;
  if (res < 0) res += mod;
  return res;
}
long long mod_sub(long long a, long long b) {
  long long res = (a - b) % mod;
  if (res < 0) res += mod;
  return res;
}
long long mod_div(long long a, long long b) {
  long long binv = mod_inv(b);
  long long res = ((a % mod) * (binv)) % mod;
  if (res < 0) res += mod;
  return res;
}
long long n, i;
cin >> n;
if (n == 1) {
  cout << 1 << ' ' << 1 << "\n";
  return;
}
long long low = 1, high = sqrt(n) + 2;
long long k, row, col;
while (low <= high) {
  long long mid = (low + high) >> 1;
  if (mid * mid >= n) {
    k = mid;
    high = mid - 1;
  } else
    low = mid + 1;
}
if (n >= (k * k) - (k - 1)) {
  row = k;
  col = (k * k) - (n) + 1;
} else {
  col = k;
  row = (k) - (((k * k) - (k - 1)) - n);
}
cout << row << " " << col << "\n";
}
signed main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  auto START___1 = high_resolution_clock::now();
  int CASES = 1;
  cin >> CASES;
  for (int i = 1; i <= CASES; i++) {
    solve();
  }
  auto STOP___1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(STOP___1 - START___1);
}
