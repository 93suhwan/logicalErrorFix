#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1000005;
ll arr[N];
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll w, h;
    scanf("%lld %lld", &w, &h);
    ll ans = 0;
    for (ll i = 0; i < 2; i++) {
      ll k;
      scanf("%lld", &k);
      for (ll i = 0; i < k; i++) scanf("%lld", arr + i);
      ll width = arr[k - 1] - arr[0];
      ans = max(ans, width * h);
    }
    for (ll i = 0; i < 2; i++) {
      ll k;
      scanf("%lld", &k);
      for (ll i = 0; i < k; i++) scanf("%lld", arr + i);
      ll height = arr[k - 1] - arr[0];
      ans = max(ans, height * w);
    }
    printf("%lld\n", ans);
  }
}
