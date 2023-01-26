#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long power(long long x, unsigned long long y, unsigned long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modInverse(long long a, long long m) { return power(a, m - 2, m); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  string str;
  cin >> n >> k >> str;
  vector<long long> prefix(n + 1);
  prefix[0] = 0;
  for (long long x = 0; x < n; x++) {
    prefix[x + 1] = prefix[x] + (str[x] == '1');
  }
  long long mod = 998244353;
  vector<long long> factorials(n + 1);
  factorials[0] = 1;
  for (long long x = 1; x <= n; x++) {
    factorials[x] = (factorials[x - 1] * x) % mod;
  }
  unordered_map<pair<long long, long long>, long long, hash_pair> map3;
  map3[make_pair(1, 2)] = 2;
  long long total = 0;
  for (long long x = 0; x < n; x++) {
    for (long long y = x + 1; y < n; y++) {
      long long ones = prefix[y + 1] - prefix[x];
      long long zeros = y - x + 1 - ones;
      if (ones <= k) {
        if (str[x] == '1') {
          zeros--;
        }
        if (str[x] == '0') {
          ones--;
        }
        if (str[y] == '1') {
          zeros--;
        }
        if (str[y] == '0') {
          ones--;
        }
        if (ones >= 0 && zeros >= 0) {
          if (zeros < ones) {
            swap(zeros, ones);
          }
          map3[make_pair(zeros, ones)]++;
        }
      }
    }
  }
  while (map3.size() > 0) {
    pair<pair<long long, long long>, long long> curr = *map3.begin();
    total = (total + curr.second *
                         factorials[curr.first.first + curr.first.second] *
                         modInverse(factorials[curr.first.first], mod) *
                         modInverse(factorials[curr.first.second], mod)) %
            mod;
    map3.erase(curr.first);
  }
  if (prefix[n] < k) {
    total = 0;
  }
  total++;
  cout << total << "\n";
  return 0;
}
