#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int mod = 1e9 + 7;
const int N = 1 << 17;
int par[N], phi[N];
VI divi[N];
int sz[N];
LL cnt[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  phi[1] = 1;
  for (int p = (2); p < (N); ++p) {
    if (par[p]) {
      int n = p / par[p];
      if (n % par[p] == 0)
        phi[p] = phi[n] * par[p];
      else
        phi[p] = phi[n] * (par[p] - 1);
      continue;
    }
    phi[p] = p - 1;
    for (int j = 2 * p; j < N; j += p) par[j] = p;
  }
  for (int d = (1); d < (N); ++d) {
    divi[d].reserve(sz[d] + 1);
    for (int j = 2 * d; j < N; j += d) sz[j]++;
  }
  for (int d = (1); d < (N); ++d) {
    for (int j = d; j < N; j += d) divi[j].push_back(d);
  }
  int n;
  cin >> n;
  VI a(n + 1);
  for (int i = (1); i < (n + 1); ++i) cin >> a[i];
  LL ans = 0;
  for (int d = (1); d < (n + 1); ++d) {
    LL cur = 0;
    for (int j = d; j <= n; j += d) {
      for (int di : divi[a[j]]) {
        cur -= cnt[di] * cnt[di] * phi[di];
        cnt[di]++;
        cur += cnt[di] * cnt[di] * phi[di];
      }
    }
    for (int j = d; j <= n; j += d) {
      for (int di : divi[a[j]]) {
        cnt[di]--;
      }
    }
    cur %= mod;
    ans += (cur * phi[d]) % mod;
  }
  cout << ans % mod << endl;
  return 0;
}
