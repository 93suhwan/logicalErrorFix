#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 998244353;
const int MAXN = 200000;
ll pow_mod(ll a, ll b, ll P) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ans;
}
ll inv_mod(ll a, ll P) { return pow_mod(a, P - 2ll, P); }
vector<ll> fact;
void calc_fact(int n, ll P) {
  if (fact.size() < 1) fact.push_back(1);
  for (int i = fact.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact.push_back(fact[i - 1] * i % P);
}
vector<ll> fact_inv;
void calc_fact_inv(int n, ll P) {
  if (fact_inv.size() < 1) fact_inv.push_back(1);
  for (int i = fact_inv.size(), nnnn = (n + 1); i < nnnn; ++i)
    fact_inv.push_back(fact_inv[i - 1] * inv_mod(i, P) % P);
}
ll nCr(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact[n] * fact_inv[r] % P) * fact_inv[n - r] % P;
}
ll nCr_inv(int n, int r, ll P) {
  if (r > n) return 0;
  calc_fact(n, P);
  calc_fact_inv(n, P);
  return (fact_inv[n] * fact[r] % P) * fact[n - r] % P;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s = "1" + s + "1";
  int cur = -1;
  ll ans = 0;
  for (int i = 0, nnnn = (n + 2); i < nnnn; ++i) {
    if (s[i] == '1') {
      int j = i, cnt = 0, last = 0;
      while (j < n + 2) {
        if (s[j] == '1') {
          cnt++;
          if (j >= i + 2 && cnt == k + 2) {
            int num = cnt - 2;
            int spaces = j - 1 - i - 1 + 1;
            int calc =
                nCr(spaces, num, mod) - nCr(spaces - j + last, num - 1, mod);
            if (ans == 0)
              ans += nCr(spaces, num, mod) - 1;
            else
              ans += calc;
          }
          last = j;
        }
        if (cnt == k + 2) {
          break;
        }
        j++;
      }
    }
  }
  cout << ans + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(12) << fixed;
  solve();
}
