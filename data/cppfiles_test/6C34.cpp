#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
const long long mod = 1e9 + 7;
int phi[MX];
void precalc_phi() {
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i < MX; i++) phi[i] = i;
  for (int i = 2; i < MX; i++)
    if (phi[i] == i)
      for (int j = i; j < MX; j += i) phi[j] -= phi[j] / i;
}
vector<int> d[MX];
void precalc_divisors() {
  for (int i = 1; i < MX; i++)
    for (int j = i; j < MX; j += i) d[j].push_back(i);
}
int n, arr[MX], cnt[MX];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  precalc_phi();
  precalc_divisors();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  long long ans = 0ll;
  for (int x = 1; x <= n; x++) {
    for (int i = x; i <= n; i += x)
      for (int j : d[arr[i]]) cnt[j]++;
    for (int i = x; i <= n; i += x)
      for (int j : d[arr[i]])
        if (cnt[j]) {
          (ans += phi[x] *
                  (phi[j] * 1ll * (cnt[j] * 1ll * cnt[j] % mod) % mod) % mod) %=
              mod;
          cnt[j] = 0;
        }
  }
  cout << ans << endl;
  return 0;
}
