#include <bits/stdc++.h>
using namespace std;
const int64_t MAX = 1e7 + 7;
const int64_t mod = 1000000007;
const int N = 1111111;
const int MAX_SIZE = 10000;
bool seive[MAX_SIZE + 1];
int64_t xyp(int64_t x, int64_t y) {
  if (y == 0) return 1LL;
  if (y == 1) return x;
  if (y % 2) {
    int64_t p = xyp(x, y - 1);
    return (x * p) % mod;
  }
  int64_t p = xyp(x, y / 2);
  return (p * p) % mod;
}
int64_t inv(int64_t x) { return xyp(x, mod - 2); }
int64_t fact[MAX];
void init() {
  fact[0] = 1;
  for (int64_t i = 1; i < MAX; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
int64_t ncr(int64_t n, int64_t r) {
  if (r < 0 || n < 0) return 0LL;
  if (r == 0 || n == r) return 1LL;
  if (r == 1 || ((n - r) == 1)) return n;
  int64_t p = (((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod;
  return p;
}
int64_t NCR(int64_t n, int64_t r) {
  int64_t ans = 1;
  r = min(n - r, r);
  for (int i = 1; i < r + 1; i++) {
    ans *= n;
    ans /= i;
    n--;
  }
  return ans;
}
void Seive() {
  memset(seive, 1, sizeof(seive));
  seive[1] = 0;
  for (int i = 2; i < MAX_SIZE + 1; i++) {
    if (seive[i] == 1) {
      for (int j = i + i; j <= MAX_SIZE; j += i) {
        seive[j] = 0;
      }
    }
  }
}
void printAndReturn(int n) {
  cout << n << '\n';
  return;
}
void read_arr(int a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
void write_arr(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << '\n';
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
string keys, s;
void solve() {
  cin >> keys >> s;
  unordered_map<char, int> mp;
  for (int i = 0; i < keys.size(); i++) mp[keys[i]] = i;
  int ans = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    ans += abs(mp[s[i]] - mp[s[i + 1]]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
