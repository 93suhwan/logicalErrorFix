#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int mod = 998244353;
const int inf = 2e9 + 5;
const ll linf = 9e18 + 5;
int n, m;
const int N = 2e5 + 5;
int arr[N][2];
ll fact[N * 2];
ll tcaf[N * 2];
int seg[N * 2];
void build(int l = 1, int r = n, int ind = 1) {
  if (l == r) {
    seg[ind] = 1;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, 2 * ind);
  build(m + 1, r, 2 * ind + 1);
  seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}
int findind(int i, int l = 1, int r = n, int ind = 1) {
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  if (seg[2 * ind] >= i) {
    return findind(i, l, m, 2 * ind);
  } else {
    return findind(i - seg[2 * ind], m + 1, r, 2 * ind + 1);
  }
}
void update(int i, int l = 1, int r = n, int ind = 1) {
  if (i < l || r < i) {
    return;
  }
  if (l == r) {
    seg[ind] = 0;
    return;
  }
  int m = (l + r) / 2;
  update(i, l, m, 2 * ind);
  update(i, m + 1, r, 2 * ind + 1);
  seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}
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
ll ncr(ll n, ll r) {
  if (n < r || r < 0) {
    return 0;
  }
  ll d = mull(tcaf[n - r], tcaf[r]);
  return mull(fact[n], d);
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
  build();
}
void solve() {
  ll top = 2 * n - 1;
  for (int i = m - 1; i > -1; i--) {
    int x = findind(arr[i][1]);
    int y = findind(arr[i][1] + 1);
    if (x + 1 == y) {
      top--;
    }
    update(x);
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
