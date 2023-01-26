#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using ll = long long;
const ll INF = 9e18 + 7;
const ll MAXN = 2e5 + 7;
void goForIt() {
  map<ll, ll> cnt;
  map<ll, bool> taken;
  ll n;
  cin >> n;
  char top[n];
  for (ll i = 0; i < n; i++) {
    cin >> top[i];
    if (top[i] == '1') cnt[i + 1]++;
  }
  char bottom[n + 1];
  ll a[n + 1];
  for (ll i = 1; i < n + 1; i++) {
    cin >> bottom[i];
    a[i] = bottom[i] - '0';
  }
  ll ans = 0;
  for (ll i = 1; i < n + 1; i++) {
    if (a[i] == 1) {
      if (i >= 2 and cnt[i - 1] == 1 and taken[i - 1] == 0) {
        ans++;
        cnt[i - 1] = 0;
        taken[i - 1] = 1;
        a[i] = 0;
      } else if (i <= n - 1 and cnt[i + 1] == 1 and taken[i + 1] == 0) {
        ans++;
        cnt[i + 1] = 0;
        taken[i + 1] = 1;
        a[i] = 0;
      } else {
        if (cnt[i] == 0 and !taken[i]) {
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  ll T;
  cin >> T;
  while (T-- > 0) {
    goForIt();
  }
}
