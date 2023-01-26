#include <bits/stdc++.h>
using namespace std;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459;
const long double EPS = 1e-8;
long long MOD = 1e9 + 7;
long long M(long long n) { return (n % MOD + MOD) % MOD; }
long long pow2(long long n) { return 1ll << n; }
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const long long MX = 5e3, MASK = 8192;
set<long long> se[MX + 2];
int main(int argn, char** argv) {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int T = 1;
  for (long long(I) = (0); (I) <= ((T)-1); (I)++) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long(i) = (0); (i) <= ((n)-1); (i)++) cin >> a[i];
    for (long long(i) = (0); (i) <= ((n)-1); (i)++) se[a[i]].emplace(i);
    long long dp[MASK];
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (long long(i) = (1); (i) <= (MX); (i)++) {
      set<long long>& s = se[i];
      for (long long(mask) = (0); (mask) <= ((MASK)-1); (mask)++) {
        auto iter = s.lower_bound(dp[mask]);
        if (iter != s.end()) dp[mask ^ i] = min(dp[mask ^ i], *iter);
      }
    }
    vector<long long> ans;
    for (long long(x) = (0); (x) <= ((MASK)-1); (x)++)
      if (dp[x] < 1e6) ans.emplace_back(x);
    long long sz = ans.size();
    cout << sz << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}
