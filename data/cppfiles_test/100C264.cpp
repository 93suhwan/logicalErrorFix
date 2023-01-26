#include <bits/stdc++.h>
using namespace std;
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
const int64_t M = 998244353;
const long long MAX = 200001;
int64_t power(int64_t a, int64_t b) {
  b = (b < 0) ? (M + b - 1) : b;
  int64_t res = 1LL;
  while (b) {
    if (b % 2) res = res * a % M;
    a = a * a % M;
    b /= 2;
  }
  return res;
}
vector<long long> fac;
void prepareFactorial() {
  fac.resize(MAX);
  fac[0] = fac[1] = 1;
  for (long long i = 2; i < MAX; i++) fac[i] = (fac[i - 1] * i) % M;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> jury(n);
  unordered_map<long long, long long, custom_hash> frequency;
  pair<long long, long long> max_pair;
  for (long long &task : jury) {
    cin >> task;
    frequency[task]++;
    if (task > max_pair.first) {
      swap(max_pair.first, max_pair.second);
      max_pair.first = task;
    } else if (task > max_pair.second) {
      max_pair.second = task;
    }
  }
  long long cntMx = frequency[max_pair.first];
  long long cntSecondMx = frequency[max_pair.second];
  long long ans = 0;
  if (cntMx > 1) {
    ans = fac[n];
  } else if (max_pair.first - max_pair.second == 1) {
    long long total = fac[n];
    long long invalid = (fac[n] * power(cntSecondMx + 1, -1)) % M;
    ans = (total - invalid + M) % M;
  }
  cout << ans << "\n";
}
int32_t main() {
  prepareFactorial();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
