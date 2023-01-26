#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void _do(T x) {
  cerr << x << "\n";
}
template <typename T, typename... U>
void _do(T x, U... y) {
  cerr << x << ", ";
  _do(y...);
}
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 3e18;
const long double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fpow(long long a, long long b, long long m) {
  if (!b) return 1;
  long long ans = fpow(a * a % m, b / 2, m);
  return (b % 2 ? ans * a % m : ans);
}
long long inv(long long a, long long m) { return fpow(a, m - 2, m); }
const long long K = 8192;
long long a[1000005], cur[K];
vector<long long> ed[5005];
bool can[K];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0; i < 5001; i++) ed[i].push_back(0);
  for (long long i = 0; i < K; i++) cur[i] = 5001;
  can[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long x : ed[a[i]]) {
      long long y = x ^ a[i];
      can[y] = 1;
      while (cur[y] > a[i]) {
        cur[y]--;
        if (cur[y] != a[i]) ed[cur[y]].push_back(y);
      }
    }
    ed[a[i]].clear();
  }
  vector<long long> ans;
  for (long long i = 0; i < K; i++)
    if (can[i]) ans.push_back(i);
  cout << ans.size() << "\n";
  for (long long u : ans) cout << u << " ";
}
