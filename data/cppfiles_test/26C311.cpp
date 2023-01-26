#include <bits/stdc++.h>
using namespace std;
void in() { return; }
template <typename T, typename... Types>
void in(T &a, Types &...b) {
  cin >> (a);
  in(b...);
}
void o() { return; }
template <typename T, typename... Types>
void o(T a, Types... b) {
  cout << (a);
  cout << ' ';
  o(b...);
}
bool sortin(const pair<long long int, long long int> &e,
            const pair<long long int, long long int> &f) {
  return (e.first < f.first);
}
bool POT(long long int x) { return x && (!(x & (x - 1))); }
long long int i, j, k, l, m, n, p, q, r, a, b, c, x, y, z, ts, mn = 1e18,
                                                               mod = 1e9 + 7;
long long int ar[250005], br[250005], xr[250005], tem[250005];
long long int inv(long long int p) {
  if (p == 0) return 1;
  if (p % 2)
    return (2 * inv(p - 1)) % mod;
  else {
    long long int aa = inv(p / 2);
    return (aa * aa) % mod;
  }
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  ar[0] = 1;
  for (long long int i = 1; i <= 250005 - 1; i++) ar[i] = (ar[i - 1] * i) % mod;
  x = inv(mod - 2);
  in(ts);
  while (ts--) {
    in(n);
    o((ar[n * 2] * x) % mod);
    cout << endl;
  }
}
