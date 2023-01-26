#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int K = 21;
const int N = 100007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int B = 350;
int mu[N];
ll g[N];
vector<int> ps;
void sieve(int n) {
  mu[1] = 1;
  vector<bool> isnt(n + 5);
  for (int i = 2; i <= n; i++) {
    if (!isnt[i]) {
      ps.push_back(i);
      mu[i] = -1;
    }
    for (int p : ps) {
      ll x = 1ll * p * i;
      if (x > n) break;
      isnt[x] = 1;
      if (i % p == 0) {
        mu[x] = 0;
        break;
      } else {
        mu[x] = -mu[i];
      }
    }
  }
}
struct Vlst {
  ll _id[2 * B + 7];
  int n;
  int id(int x) { return x <= B ? x : n / x + B; }
  ll &Id(int x) { return _id[id(x)]; }
} tab[N];
void precalc() {
  for (int i = 1; i < N; i++)
    for (int j = i, k = 1; j < N; j += i, k++) {
      g[j] += mu[i] * k;
    }
  for (int i = 1; i < N; i++) g[i] += g[i - 1];
  for (int r = 1; r < N; r++) {
    ll sum = 0;
    tab[r].n = r;
    for (int l = 1, j; l <= r; l = j + 1) {
      j = r / (r / l);
      sum += g[r / l] * (j - l + 1);
      tab[r].Id(r / l) = sum;
    }
  }
}
ll calc(int l, int r) {
  ll res = tab[r].Id(1) - tab[r].Id(r / l);
  return res + g[r / l] * ((r / (r / l)) - l);
}
void dfs(ll *a, ll *b, int l, int r, int cl, int cr) {
  if (l > r) return;
  int mid = ((l + r) >> 1);
  int hi = min(mid, cr);
  ll cur = calc(hi, mid);
  int nxt = 0;
  ll mn = INF;
  assert(hi >= cl);
  for (int i = hi; i >= cl; i--) {
    cur += g[mid / i];
    if (cur + b[i - 1] < mn) mn = cur + b[i - 1], nxt = i;
  }
  a[mid] = mn;
  dfs(a, b, l, mid - 1, cl, nxt);
  dfs(a, b, mid + 1, r, nxt, cr);
}
ll dp[K][N];
void init() {
  int n = 100000;
  for (int k = 1; k < K; k++)
    for (int i = 1; i <= n; i++) dp[k][i] = INF;
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1ll * i * (i + 1) / 2;
  }
  for (int k = 2; k < K; k++) {
    dfs(dp[k], dp[k - 1], 1, n, 1, n);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (k >= K) {
    cout << k << endl;
  } else {
    cout << dp[k][n] << endl;
  }
}
void test() {
  for (int l = 1; l <= 10; l++)
    for (int r = l; r <= 10; r++) {
      ll sum = calc(l, r) + g[r / l];
      printf("%lld%c", sum, " \n"[r == 10]);
    }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  sieve(N - 1);
  precalc();
  init();
  int t;
  cin >> t;
  while (t--) solve();
}
