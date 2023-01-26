#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int mod = 998244353;
const int inf = 2e9 + 5;
const ll linf = 9e18 + 5;
int n, m;
const int N = 4e5 + 5;
int arr[N][2];
bool seen[N];
ll fact[N];
ll tcaf[N];
ll mull(ll a, ll b) { return (a * b) % mod; }
ll binpow(ll a, ll b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2) {
    return mull(a, binpow(a, b - 1));
  }
  ll half = binpow(a, b / 2);
  return mull(half, half);
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mull(i, fact[i - 1]);
  }
  tcaf[N - 1] = binpow(fact[N - 1], mod - 2);
  for (int i = N - 2; i > -1; i--) {
    tcaf[i] = mull(i + 1, tcaf[i + 1]);
  }
}
void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
}
ll ncr(ll n, ll r) {
  if (n < r || r < 0) {
    return 0;
  }
  ll d = mull(tcaf[n - r], tcaf[r]);
  return mull(fact[n], d);
}
void solve() {
  ll top = 2 * n - 1;
  for (int i = 0; i < m; i++) {
    if (!seen[arr[i][0] - arr[i][1]]) {
      top--;
      seen[arr[i][0] - arr[i][1]] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    seen[arr[i][0] - arr[i][1]] = false;
  }
  cout << ncr(top, n) << endl;
}
void output() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int number_of_testcases = 1;
  cin >> number_of_testcases;
  while (number_of_testcases--) {
    input();
    solve();
    output();
  }
}
