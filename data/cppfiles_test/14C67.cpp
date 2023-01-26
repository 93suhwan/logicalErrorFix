#include <bits/stdc++.h>
const long long int mod = 1000000000 + 7;
const long long int INF = 9000000000000000000;
using namespace std;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long int gcd(long long int a, long long int b) {
  return (a == 0 ? b : gcd(b % a, a));
}
long long int lcm(long long int a, long long int b) {
  return (a * b / (gcd(a, b)));
}
long long int add(long long int a, long long int b, long long int c = 0) {
  return ((a % mod + b % mod) % mod + c % mod) % mod;
}
long long int mul(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int sub(long long int a, long long int b) {
  return (a % mod - b % mod + mod) % mod;
}
void print(vector<long long int>& ans) {
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
void print(long long int a) { cout << a << endl; }
long long int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
long long int n, w, h, d, k, m, mx, timer, realans, cc, start, queries,
    startindex;
long long int arr[2005], dp[2005][2005];
long long int go(long long int id, long long int del) {
  if (id < 0) return 0;
  if (del == 0) {
    long long int cnt = 0;
    for (long long int i = id; i >= 1; i--) {
      if (arr[i] == i) cnt++;
    }
    return cnt;
  }
  if (dp[id][del] != -1) return dp[id][del];
  long long int fst = 0, scd = 0;
  if (arr[id] == id - del) {
    fst = 1 + go(id - 1, del);
  } else {
    fst = go(id - 1, del);
  }
  scd = go(id - 1, del - 1);
  return dp[id][del] = max(fst, scd);
}
void solve() {
  cin >> n >> k;
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
  long long int ans = -1;
  memset(dp, -1, sizeof(dp));
  for (long long int i = 0; i <= n; i++) {
    if (go(n, i) >= k) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
