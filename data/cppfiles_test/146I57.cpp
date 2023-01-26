#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (int)2e5 + 5;
int _ = 1;
vector<ll> pos;
ll n;
ll num[N];
void work() {
  scanf("%lld", &n);
  for (ll i = 0; i <= n; i++) num[i] = 0;
  for (ll i = 1, x; i <= n; i++) {
    scanf("%lld", &x);
    num[x]++;
  }
  ll ans = 0;
  ll sum = 0;
  ll x;
  for (x = 0; x <= n; x++) {
    if (sum < x) break;
    printf("%lld ", ans + num[x]);
    sum += num[x];
    if (!num[x] && pos.size()) {
      ans += x - pos.back();
      num[pos.back()]--;
      if (num[pos.back()] == 1) pos.pop_back();
      num[x]++;
    }
    if (num[x] > 1) pos.push_back(x);
  }
  for (ll i = x; i <= n; i++) printf("-1 ");
  printf("\n");
}
int main() {
  scanf("%d", &_);
  while (_--) {
    work();
  }
  return 0;
}
