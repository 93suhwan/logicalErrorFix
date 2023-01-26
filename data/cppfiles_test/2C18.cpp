#include <bits/stdc++.h>
template <class p, class q>
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using ll = long long;
using VI = std::vector<int>;
using VLL = std::vector<ll>;
using namespace std;
using namespace std::chrono;
ll n, m, k;
int const N = 2e5 + 3;
ll const P = 1e9 + 7;
ll a[N];
ll ans = 0;
ll sum;
ll doub[2 * N];
ll sum_doub[2 * N];
ll st[2][N];
ll power(ll x, ll pw, ll mod) {
  if (!pw) return 1;
  if (pw % 2)
    return (x * power(x, pw - 1, mod)) % mod;
  else {
    ll xx = power(x, pw / 2, mod);
    return (xx * xx) % mod;
  }
}
void add(int t, int ind, ll val) {
  for (; ind < N; ind += (ind & (-ind))) st[t][ind] = (st[t][ind] + val) % P;
}
void update(int ind, ll val) {
  add(0, ind, val);
  add(0, ind + 1, P - val);
  add(1, ind, 1LL * val * (ind - 1));
  add(1, ind + 1, P - 1LL * val * ind);
}
ll summ(int t, int ind) {
  ll ret = 0;
  for (; ind > 0; ind -= (ind & (-ind))) ret = (ret + st[t][ind]) % P;
  return ret;
}
ll prefix_sum(int l) { return (summ(0, l) * l - summ(1, l) + 3 * P) % P; }
ll query(int l, int r) {
  if (r <= k)
    return (prefix_sum(r) - prefix_sum(l - 1) + P) % P;
  else
    return (prefix_sum(k) - prefix_sum(l - 1) + prefix_sum(r - k) + P) % P;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  if (k == 1) {
    ans = 1LL * m * n;
    ans = ans % P;
    ans = (ans * (ans + P - 1)) % P;
    ans = (ans + 1) % P;
    cout << ans << "\n";
    return 0;
  }
  for (int i = (1); i <= (n); i++) sum = (sum + a[i]) % k;
  if (sum % k == 0) {
    ans += n * m * (m - 1) + 1LL;
    ans = ans % P;
  } else {
    ans += n * m * ((m - 1) / k);
    ans += 1LL * (!(m % k));
    ans = ans % P;
  }
  for (int i = (1); i <= (2 * n); i++) {
    doub[i] = a[(i - 1) % n + 1];
    sum_doub[i] = (sum_doub[i - 1] + doub[i]) % k;
  }
  ll ods = (sum % k) ? sum : 1;
  for (int i = (n + 1); i <= (2 * n - 1); i++) {
    update((sum_doub[i] * power(ods, k - 2, k)) % k + 1, 1);
  }
  ll ww = (sum_doub[2 * n] * power(ods, k - 2, k)) % k;
  if (sum % k) {
    ans = (ans + m * query(ww + 1, ww + 1 + (m - 1) % k)) % P;
    ans = (ans + ((m * ((m - 1) / k)) % P) * query(1, k)) % P;
  } else
    ans = (ans + ((m * m) % P) * query(ww + 1, ww + 1)) % P;
  for (int j = (2 * n - 1); j >= (n + 1); j--) {
    update((sum_doub[j] * power(ods, k - 2, k)) % k + 1, P - 1);
    update((sum_doub[j - n + 1] * power(ods, k - 2, k)) % k + 1, 1);
    ll ww = (sum_doub[j] * power(ods, k - 2, k)) % k;
    if (sum % k) {
      ans = (ans + m * query(ww + 1, ww + 1 + (m - 1) % k)) % P;
      ans = (ans + ((m * ((m - 1) / k)) % P) * query(1, k)) % P;
    } else
      ans = (ans + ((m * m) % P) * query(ww + 1, ww + 1)) % P;
  }
  cout << ans << "\n";
  return 0;
}
