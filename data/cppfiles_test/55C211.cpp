#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
int T, k;
using ll = long long;
const ll mod = 1e9 + 7;
ll power(ll q, ll w) {
  ll ret = 1;
  while (w) {
    if (w & 1) ret = ret * q % mod;
    q = q * q % mod;
    w >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  T = 1;
  while (T--) {
    cin >> k;
    cout << 6 * power(4, (1ll << k) - 2) % mod << "\n";
  }
  return 0;
}
