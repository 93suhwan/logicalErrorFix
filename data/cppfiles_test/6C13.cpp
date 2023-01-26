#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long Mod = 1000000007LL;
const int N = 1e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
long long a[N], u[N], c[N], cnt[N], c2[N];
vector<int> D[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i) D[j].push_back(i);
  int mx = 0;
  for (int i = 1; i < N; i++) {
    for (auto x : D[i])
      if (x < i) u[i] -= u[x];
    if (i == 1) u[i] = 1;
    mx = max(mx, (int)D[i].size());
  }
  for (int i = 1; i < N; i++)
    for (auto x : D[i]) c[i] += x * u[i / x];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int g = 1; g <= n; g++) {
    for (int i = g; i <= n; i += g)
      for (auto x : D[a[i]]) cnt[x]++;
    for (int i = g; i <= n; i += g) {
      for (auto x : D[a[i]]) {
        c2[x] += cnt[x] * c[g];
        c2[x] %= Mod;
      }
    }
    for (int i = g; i <= n; i += g)
      for (auto x : D[a[i]]) cnt[x]--;
  }
  long long ans = 0;
  for (int i = N - 1; i >= 1; i--) {
    for (auto x : D[i]) {
      if (x < i) (c2[x] -= c2[i]) %= Mod;
    }
    c2[i] %= Mod;
    ans += (c2[i] * i);
    ans %= Mod;
  }
  ans += Mod;
  cout << ans % Mod << '\n';
  return 0;
}
