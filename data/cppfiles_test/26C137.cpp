#include <bits/stdc++.h>
using namespace std;
void printlist(vector<long long> temp) {
  for (long long i = 0; i < temp.size(); ++i) {
    cout << temp[i] << " ";
  }
  cout << "\n";
}
long long mod = 1e9 + 7;
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
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long binexp(long long a, long long b) {
  if (b == 0) return 1;
  long long half = binexp(a, b / 2);
  if ((b % 2) == 0)
    return mul(half, half);
  else
    return mul(a, mul(half, half));
}
long long mod_inv(long long n) { return binexp(n, mod - 2); }
long long msb(long long n) {
  n |= (n >> 1);
  n |= (n >> 2);
  n |= (n >> 2);
  n |= (n >> 8);
  n |= (n >> 16);
  n |= (n >> 32);
  n = n + 1;
  return (n >> 1);
}
long long solve(long long n, long long a, long long low, long long high,
                long long m) {
  long long cn1 = 0;
  long long cn2 = 0;
  long long l = low;
  long long r = high;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    if ((n * a + mid - m) <= r && (n * a + mid - m) >= l) {
      return mid;
    } else if ((n * a + mid - m) > r) {
      cn1++;
      high = mid - 1;
    } else if ((n * a + mid - m) < l) {
      cn2++;
      low = mid + 1;
    }
  }
  if (cn1 <= cn2) return -1;
  return -2;
}
void precompute(long long fact[]) {
  fact[0] = 1;
  for (long long i = 1; i < 200005; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long fact[200005];
  precompute(fact);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (fact[2 * n] * mod_inv(fact[2])) % mod << "\n";
  }
  return 0;
}
