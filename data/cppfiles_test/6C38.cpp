#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
int phi[maxn];
int n;
int arr[maxn];
std::vector<int> vec[maxn];
int cnt[maxn];
void init() {
  phi[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!phi[i]) {
      for (int j = i; j < maxn; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      vec[j].emplace_back(i);
    }
  }
  return;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  long long ans = 0;
  for (int x = 1; x <= n; x++) {
    for (int i = x; i <= n; i += x) {
      for (const auto &val : vec[arr[i]]) {
        ++cnt[val];
      }
    }
    for (int i = x; i <= n; i += x) {
      for (const auto &val : vec[arr[i]]) {
        if (cnt[val]) {
          ans += (long long)cnt[val] * cnt[val] % MOD * phi[x] % MOD *
                 phi[val] % MOD;
          ans %= MOD;
          cnt[val] = 0;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
