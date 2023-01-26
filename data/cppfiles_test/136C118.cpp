#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
template <typename T>
void printv(const T& t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  cout << '\n';
}
long long int modpower(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    res %= mod;
    a = a * a;
    a %= mod;
  }
  return res;
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
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long int mod_inv(long long int a, long long int b) {
  return expo(a, b - 2, b);
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  long long int x = n * (n + 1);
  x /= 2;
  if (sum % x != 0) {
    cout << "NO\n";
    return;
  }
  long long int s = sum / x;
  vector<long long int> ans(n);
  for (long long int i = 1; i < n; i++) {
    long long int curr = s - (v[i] - v[i - 1]);
    if (curr <= 0 || curr % n != 0) {
      cout << "NO\n";
      return;
    }
    curr /= n;
    ans[i] = curr;
  }
  long long int curr = s - (v[0] - v[n - 1]);
  if (curr <= 0 || curr % n != 0) {
    cout << "NO\n";
    return;
  }
  curr /= n;
  ans[0] = curr;
  cout << "YES\n";
  for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
