#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long MOD = 998244353;
const long long inf = 1e18;
const long long MAX = 2e5 + 1;
inline long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
inline long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
inline long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
inline long long ceil(long long a, long long b) { return (a + b - 1) / (b); }
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long pwr(long long x, long long n) {
  x = x % mod;
  if (!n) return 1;
  if (n & 1)
    return mul(x, pwr(mul(x, x), (n - 1) / 2));
  else
    return pwr(mul(x, x), n / 2);
}
long long pwrmod(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * pwrmod(b * b % m, e / 2, m) % m;
  return pwrmod(b * b % m, e / 2, m);
}
long long modinv(long long n) { return pwr(n, mod - 2); }
long long inv(long long i) {
  if (i == 1) return 1;
  return (MOD - (MOD / i) * inv(MOD % i) % MOD) % MOD;
}
struct cmp {
  bool operator()(const int &k1, const int &k2) { return k1 > k2; }
};
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
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;
template <typename T1>
using safe_set = unordered_set<T1, custom_hash>;
void solve() {
  long long N;
  cin >> N;
  vector<long long> arr(N, 0);
  vector<long long> cnt(N + 1, 0);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  long long overall = 0;
  stack<long long> duplicates;
  vector<long long> ans(N + 1, -1);
  for (long long mex = 0; mex <= N; mex++) {
    long long cur_ans = 0;
    cur_ans += cnt[mex];
    if (mex != 0 && cnt[mex - 1] == 0) {
      if (duplicates.size() == 0) {
        break;
      } else {
        int tp = duplicates.top();
        duplicates.pop();
        overall += (mex - 1 - tp);
      }
    }
    cur_ans += overall;
    for (int freq = 0; freq < cnt[mex] - 1; freq++) {
      duplicates.push(mex);
    }
    ans[mex] = cur_ans;
  }
  for (int i = 0; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TEST = 1;
  cin >> TEST;
  for (long long tt = 1; tt <= TEST; tt++) {
    solve();
  }
  return 0;
}
