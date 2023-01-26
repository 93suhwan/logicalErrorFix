#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const long long inf = 1e12;
using ll = long long;
int phi[N];
void totient() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
    }
  }
}
ll a[N];
ll c(int l, int r) {
  if (l > r) return inf;
  ll ans = 0;
  for (int i = l, last; i <= r; i = last + 1) {
    last = r / (r / i);
    int x = 0;
    if (i >= l)
      x = last - i + 1;
    else if (last >= l)
      x = last - l + 1;
    ans += a[r / i] * x;
  }
  return ans;
}
ll dp[N][17];
void yo(int i, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  dp[mid][i] = inf;
  int opt = optl;
  ll cost = c(min(mid, optr) + 1, mid);
  for (int k = min(mid, optr); k >= optl; k--) {
    ll cc = dp[k][i - 1] + cost;
    if (cc <= dp[mid][i]) {
      dp[mid][i] = cc;
      opt = k;
    }
    if (k <= mid) {
      if (cost == inf)
        cost = a[mid / k];
      else
        cost += a[mid / k];
    }
  }
  yo(i, l, mid - 1, optl, opt);
  yo(i, mid + 1, r, opt, optr);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  totient();
  for (int i = 1; i < N; i++) {
    a[i] = a[i - 1] + phi[i];
  }
  int n = 100000;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = inf;
  }
  for (int i = 1; i <= n; i++) dp[i][1] = 1LL * i * (i + 1) / 2;
  for (int i = 2; i <= 16; i++) yo(i, 1, n, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    if (k >= 20 or (1 << k) > n) {
      cout << n << '\n';
    } else {
      cout << dp[n][k] << '\n';
    }
  }
  return 0;
}
