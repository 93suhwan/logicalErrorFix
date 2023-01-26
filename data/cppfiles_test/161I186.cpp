#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
bool prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<int> factors(int n) {
  vector<int> f;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      f.push_back(i);
      n /= i;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int modpow(int x, int n, int m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
void fastio() { ios::sync_with_stdio(0), cin.tie(0); }
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2);
  ans *= ans;
  ans %= 1000000007;
  if (b % 2) {
    ans *= a;
  }
  return ans % 1000000007;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<int> l(n), h(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> h[i];
  }
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = l[i]; j < h[i] + 1; j++) {
      cnt[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int idx = l[i];
    for (int j = l[i]; j < h[i] + 1; j++) {
      if (cnt[j] > cnt[idx]) idx = j;
    }
    cout << l[i] << " " << h[i] << " " << idx << "\n";
  }
}
int32_t main() {
  fastio();
  int t;
  cin >> t;
  int n = 1;
  while (t--) {
    solve();
    n++;
  }
  return 0;
}
